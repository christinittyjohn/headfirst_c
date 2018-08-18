#include<stdio.h>

typedef struct {
const char *name;
const char *species;
int age;
}turtle;

void happy_birthday(turtle *t)
{
	t->age++;
	printf("Happy Birthday %s ! You are now %i years old\n",
		t->name,t->age);
}


int main()
{
	turtle myrtle = {"Myrtle","Leatherback sea turtle",99};
	happy_birthday(&myrtle);
	return 0;
}
