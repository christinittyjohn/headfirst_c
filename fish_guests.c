#include<stdio.h>
struct exercise {
	const char *description;
	float duration;
	};
struct meal {
	const char *ingredients;
	float weight;
	};
struct preferences {
	struct meal food;
	struct exercise exercises;
	};
 typedef struct fish {
	const char *name;
	const char *species;
	int teeth;
	int age;
	struct preferences care;
	}fish;

void label(fish a)
{
	printf("%s is a %s with %i teeth. He is %i.Feed with %.2f of %s and is to %s for %.2f hours",
	a.name,a.species,a.teeth,a.age,a.care.food.weight,a.care.food.ingredients,a.care.exercises.description,a.care.exercises.duration);
}
int main()
{
	 fish snappy= {"Snappy","Piranha",69,4,{{"meat",0.2},{"swim in the jacuzzi",7.5}}};
	label(snappy);
	return 0;
}



