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
	int sem3_result[5];
} results_t;

typedef struct {
	full_name_t full_name;
	results_t results;
	int number_of_sem;
}students_t; 

int read_argument(int, char **);
students_t* read_full_names(int *);
int read_results(students_t *, int, int);
char* catalog_of_exams(int);
int print_information(students_t *, int, int);

int main(int argc, char **argv)
{
	int numb_of_stud=Max_num_of_stud,sem_numb;
	students_t *stud;
	if(print_manual(argc,argv)) {
		return 0;
	}
	if(!(sem_numb=read_argument(argc, argv)) ) {
		return 0;	
	}
	stud = read_full_names(&numb_of_stud);
	read_results(stud,numb_of_stud,sem_numb);
	print_information(stud,numb_of_stud,sem_numb);
	return 0;
}

int read_argument(int argc, char **argv) {
	int sem_numb;
	if(argc == 2) {
		if(!(strcmp(argv[1], "-s1")) ) {
			sem_numb = 1;
		}
		if(!(strcmp(argv[1], "-s2")) ) {
			sem_numb = 2;
		}
		if(!(strcmp(argv[1], "-s3")) ) {
			sem_numb = 3;
		}
	}
	else {
		printf("You need to set one of three sems(first(-s1), second(-s2) or third (-s3))");
		return 0;
	}
	return sem_numb;
}

students_t *read_full_names(int *num_of_stud)
{
	int i;
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
		printf("Patronymic:\n   ");
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

int read_results(students_t * stud, int numb_of_stud, int sem_numb) {
	int i, j, amount_of_exams = sem_numb+2, exam_numb_in_sem[][5]={{1, 2, 3}, {1, 2, 4, 5},{1, 2, 3, 4, 5}};
	printf("Specify the results of students:\n");
	for(i=0; i < numb_of_stud; i++) {
		printf("%d) %s %s\n",i+1,stud[i].full_name.name, stud[i].full_name.surname);
		printf("Specify sem:\n");
		stud[i].number_of_sem=input_number_in_range(1,3);
		for(j=0; j < amount_of_exams; j++) {
			printf("  %s  ", catalog_of_exams(exam_numb_in_sem[sem_numb-1][j]));
			switch (stud[i].number_of_sem) {
				case 1: 
					stud[i].results.sem1_result[j]=input_number_in_range(1,10); 
					break;
				case 2:
					stud[i].results.sem2_result[j]=input_number_in_range(1,10);
					break;
				case 3: 
					stud[i].results.sem3_result[j]=input_number_in_range(1,10);
					break;
			}
			
		}
	}

	return 0;
}

int print_information(students_t * stud, int numb_of_stud, int sem_numb) {
	int i, j, amount_of_exams = sem_numb+2, exam_numb_in_sem[][4]={{1, 2, 3}, {1, 2, 4, 5}};
	printf("Results of students:\n");
	for(i=0; i < numb_of_stud; i++) {
		printf("%d) %s %s\n",i+1,stud[i].full_name.name, stud[i].full_name.surname);
		for(j=0; j < amount_of_exams; j++) {
			printf("  %s  ", catalog_of_exams(exam_numb_in_sem[sem_numb-1][j]));
			if(sem_numb == stud[i].number_of_sem) {
				switch (stud[i].number_of_sem) {
					case 1: 
						printf("%d", stud[i].results.sem1_result[j]);
						break;
					case 2:
						printf("%d", stud[i].results.sem2_result[j]);
						break;
					case 3: 
						printf("%d", stud[i].results.sem3_result[j]);
						break;
				}

			}
		}
		printf("\n");
	}

	return 0;
}


char *catalog_of_exams(int exam_number) {
    static char exam[][12]={"Math", "Programming", "AiLOVT", "Physics", "English"};
    if (exam_number >= 1 && exam_number <= 5)
        return exam[exam_number - 1];
    else
        return "";
}
