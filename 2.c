#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "mylib.h"
#define Max_num_of_stud 20

typedef struct {
	char name[10];
	char surname[10];
	char patronymic[10];
}full_name_t;

typedef union {
		int exm_num;
		int result;
	} results_t;

typedef struct {
	full_name_t full_name;
	results_t results;
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


int main(int argc, char **argv)
{
    int i,n=Max_num_of_stud,sem_num;
    if(print_manual(argc,argv)) {
		return 0;
	}
	if(argc > 1 && argc < 3) {
		if(!(strcmp(argv[2], "-f") {
			sem_num = 1;
		}
		if(strcmp(argv[2], "-s") {
			sem_numb = 2;
		}
	}
	else {
		printf("You need to set one of two sems(first(-f) or second(-s))");
		return 0;
	}
	read_names(&n);

    
    return 0;
}
