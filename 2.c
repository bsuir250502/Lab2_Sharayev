int read_results(students_t * stud, int numb_of_stud, int sem_numb) {
	int i, j, amount_of_exams = sem_numb+2, exam_numb_in_sem[][4]={{1, 2, 3}, {1, 2, 4, 5}};
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
	int i, j, amount_of_exams = sem_numb+2, exam_numb_in_sem[][4]={{1, 2, 3}, {1, 2, 4, 5}};
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

char *catalog_of_exams(int exam_number) {
    static char exam[][12]={"Math", "Programming", "AiLOVT", "Physics", "English"};
    if (exam_number >= 1 && exam_number <= 5)
        return exam[exam_number - 1];
    else
        return "";
}
