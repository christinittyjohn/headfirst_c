#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
void error(char *msg)
{
fprintf(stderr,"%s:%s",msg,strerror(errno));
exit(1);
}

int main(int argc, char *argv[])
{
char *phrase = argv[1];
char *vars[] = {"RSS_FEED=https://timesofindia.indiatimes.com/rssfeeds/-2128936835.cms", NULL};
FILE *f = fopen("stories.txt", "w");
if(!f) {
error("Can't open stories.txt");
}
pid_t pid = fork();
if (pid == -1) {
error("Can't fork process");
}
if (!pid) {
if(dup2(fileno(f),1)==-1){
error("Can't redirect Standard Output");
}
if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py",
phrase, NULL, vars) == -1) {
error("Can't run script");
}
}
return 0;
}


