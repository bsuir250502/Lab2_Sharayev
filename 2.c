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
	int sem1_result[3];
	int sem2_result[4];
	} results_t;

typedef struct {
	full_name_t full_name;
	results_t results;
}students_t; 

int read_results(students_t *, int, int);
char* catalog_of_exams(int);
int print_information(students_t *, int, int);


students_t* read_full_names(int *num_of_stud)
{
	int i, j;
	students_t *stud;
	char arr[Max_num_of_stud][3][30];
	for (i = 0; i < Max_num_of_stud; i++) {
		printf("Enter the name of the %d student:\n   ", i+1);
		myfgets(arr[0][i], 30);
		if (!(strcmp(arr[0][i],"end")) ) {
			break;
		}
		printf("The surname:\n   ");
		myfgets(arr[1][i], 30);
		printf("Patronymic:\n   ", i+1);
		myfgets(arr[2][i], 30);
		
    }
    *num_of_stud = i;
    stud = (students_t *) malloc(*num_of_stud * sizeof(students_t));
    for (i = 0; i < *num_of_stud; i++) {
		strncpy(stud[i].full_name.name, arr[0][i],30);
		strncpy(stud[i].full_name.surname, arr[1][i],30);
		strncpy(stud[i].full_name.patronymic, arr[2][i],30);
    }
    return stud;
}



int read_argument(int argc, char **argv) {
	int sem_numb;
	if(argc > 1 && argc < 3) {
		if(!(strcmp(argv[1], "-f")) ) {
			sem_numb = 1;
		}
		if(!(strcmp(argv[1], "-s")) ) {
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
    int i,numb_of_stud=Max_num_of_stud,sem_numb;
	students_t *stud;
    if(print_manual(argc,argv)) {
		return 0;
	}
	if(!(sem_numb=read_argument(argc, argv)) ) {
		return 0;	
	}
	sem_numb=1;
    stud = read_full_names(&numb_of_stud);
	read_results(stud,numb_of_stud,sem_numb);
	print_information(stud,numb_of_stud,sem_numb);
    return 0;
}

int read_results(students_t * stud, int numb_of_stud, int sem_numb) {
	int i, j, amount_of_exams, exam_numb_in_sem[][4]={{1, 2, 3}, {1, 2, 4, 5}};
	if(sem_numb == 1) {
		amount_of_exams=3;
	}
	else {
		amount_of_exams=4;
	}
	printf("Specify results of students:\n");
	for(i=0; i < numb_of_stud; i++) {
		printf("%d) %s %s\n",i+1,stud[i].full_name.name, stud[i].full_name.surname);
		for(j=0; j < amount_of_exams; j++) {
			printf("  %s  ", catalog_of_exams(exam_numb_in_sem[sem_numb-1][j]));
			if(sem_numb == 1) {
				stud[i].results.sem1_result[j]=input_number_in_range(1,10);
			}
			else {
				stud[i].results.sem2_result[j]=input_number_in_range(1,10);
			}
		}
	}

	return 0;
}

int print_information(students_t * stud, int numb_of_stud, int sem_numb) {
	int i, j, amount_of_exams, exam_numb_in_sem[][4]={{1, 2, 3}, {1, 2, 4, 5}};
	if(sem_numb == 1) {
		amount_of_exams=3;
	}
	else {
		amount_of_exams=4;
	}
	printf("Results of students:\n");
	for(i=0; i < numb_of_stud; i++) {
		printf("%d) %s %s\n",i+1,stud[i].full_name.name, stud[i].full_name.surname);
		for(j=0; j < amount_of_exams; j++) {
			printf("  %s  ", catalog_of_exams(exam_numb_in_sem[sem_numb-1][j]));
			if(sem_numb == 1) {
				printf("%d", stud[i].results.sem1_result[j]);
			}
			else {
				printf("%d", stud[i].results.sem2_result[j]);
			}
		}
	}

	return 0;
}

char *catalog_of_exams(int exam_numb) {
	char exam[][12]={"Math", "Programming", "AiLOVT", "Physics", "English"};
	switch(exam_numb) {
		case 1: return exam[0];
		case 2: return exam[1];
		case 3: return exam[2];
		case 4: return exam[3];
		case 5: return exam[4];
		default: return 0;
	}
}


