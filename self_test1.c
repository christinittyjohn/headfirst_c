#include<stdio.h>

int add_this(int (*points)(int, int))
{
	int x = 2,y = points;
	return x+y;
}
int mult_this(int a, int b)
{
	int x = a,y = b;
	return x*y;
}
	 	
int main()
{
printf("%i\n",add_this(mult_this(1,8)));
return 0;
}



