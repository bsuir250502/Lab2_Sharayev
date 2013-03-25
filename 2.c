#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max_num_of_stud 20

typedef struct {
	typedef struct{
		char name[10];
		char surname[10];
		char patronymic[10];
	} Full_name_t;
	typedef union {
		int exm_num;
		int result;
	} results_t;
}students_t; 

char* myfgets(char *str, int num)
{
	if( !(fgets(str, num, stdin)) ){
		return 0;
	}
	else {
	str[strlen(str)-1]='\0';
	}
	return str;
}

int main()
{
	int i;
	for(i=0;i<Max_num_of_stud;i++){
		printf("Enter the name of the %d student", i+1);
	}
	
    
    return 0;
}
