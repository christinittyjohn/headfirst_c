#include<stdio.h>

typedef struct{
char const *string1;
char string2 [5];
int ***int_pointer;
char **char_pointer
} data;

int main()
{	int integer = 100;
	int *integer1 = integer;
	int *points_integer1 = integer1;
	int *points_points_integer1 = points_integer1;
	char a[3] = "hi";
	char *points_a = a;
	char **points_points_a = points_a;	
	
	data set1 = {"this is a better way!","baad",points_points_integer1};
	printf("this is the string %s and this is also a  string \n %s \n %i ",set1.string1,set1.string2,set1.int_pointer);
	set1.string1 = "I tried changing it";
	printf("this is the string %s and this is also a  string \n %s \n %i ",set1.string1,set1.string2,set1.int_pointer);
	
	set1.char_pointer = points_points_a;
	printf("\n%s",set1.char_pointer);
	 
	
	
	return 0;
}	
