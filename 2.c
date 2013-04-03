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
		int sem1_exam_num[3];
		int sem1_result[3];
		int sem2_exam_num[4];
		int sem2_result[4];
	} results_t;

typedef struct {
	full_name_t full_name;
	results_t results;
}students_t; 

students_t* read_full_names(int *n)
{
    int i, j;
    students_t *stud;
    char arr[Max_num_of_stud][3][30];
    for (i = 0; i < Max_num_of_stud; i++) {
		printf("Enter the name of the %d student:\n   ", i+1);
        myfgets(arr[0][i], 30);
		if (!(strcmp(arr[0][i],"End.")) ) {
            break;
        }
		printf("The surname:\n   ");
		myfgets(arr[1][i], 30);
		printf("Patronymic:\n   ", i+1);
		myfgets(arr[2][i], 30);
		
    }
    *n = i;
    stud = (students_t *) malloc(*n * sizeof(students_t));
    for (i = 0; i < *n; i++) {
        strncpy(stud[i].full_name.name, arr[0][i],30);
		strncpy(stud[i].full_name.surname, arr[1][i],30);
		strncpy(stud[i].full_name.patronymic, arr[2][i],30);
    }
    return stud;
}

int read_argument(int argc, char **argv) {
	int sem_numb;
	if(argc > 1 && argc < 3) {
		if(!(strcmp(argv[2], "-f")) ) {
			sem_numb = 1;
		}
		if(!(strcmp(argv[2], "-s")) ) {
			sem_numb = 2;
		}
	}
	else {
		printf("You need to set one of two sems(first(-f) or second(-s))");
		return 0;
	}
	return sem_numb;
}

int main(int argc, char **argv)
{
    int i,n=Max_num_of_stud,sem_numb;
    if(print_manual(argc,argv)) {
		return 0;
	}
	if(!(sem_numb=read_argument(argc, argv)) ) {
		return 0;	
	}
    read_full_names(&n);
	
    return 0;
}

