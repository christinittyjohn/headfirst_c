#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
char *feeds[] = {"https://timesofindia.indiatimes.com/rssfeeds/-2128936835.cms",
"https://timesofindia.indiatimes.com/rssfeeds/296589292.cms",
"https://timesofindia.indiatimes.com/rssfeeds/5880659.cms"};
int times = 3;
char *phrase = argv[1];
int i;
for (i = 0; i < times; i++) {
char var[255];
sprintf(var, "RSS_FEED=%s", feeds[i]);
char *vars[] = {var, NULL};
pid_t pid= fork();
if (pid == -1) {
fprintf(stderr, "Can't fork process: %s\n", strerror(errno));
return 1;
}
if (!pid) {
if(execle("/usr/bin/python","/usr/bin/python","./rssgossip.py",phrase,NULL,vars)== -1){
fprintf(stderr, "Can't run script: %s\n", strerror(errno));
return 1;
}
}
}
}
