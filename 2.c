#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "mylib.h"
#define Max_num_of_stud 20

typedef struct {
	 struct full_name_t{
		char name[10];
		char surname[10];
		char patronymic[10];
	} full_name;
	union results_t{
		int exm_num;
		int result;
	} results;
}students_t; 

students_t* read_names(int *n)
{
    int i, j;
    students_t *stud;
    char arr[Max_num_of_stud][30];
    for (i = 0; i < Max_num_of_stud; i++) {
		printf("Enter the name of the %d student:   ", i+1);
        myfgets(arr[i], 30);
        if (!(strcmp(arr[i],"end")) ) {
            break;
        }
    }
    *n = i;
    stud = (students_t *) malloc(*n * sizeof(students_t));
    for (i = 0; i < *n; i++) {
        strncpy(stud[i].full_name.name, arr[i],30);
    }
    return stud;
}


int main()
{
	int i,n=Max_num_of_stud;
	read_names(&n);
	
    
    return 0;
}
