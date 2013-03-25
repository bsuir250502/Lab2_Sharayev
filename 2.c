#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main()
{
    
    return 0;
}
