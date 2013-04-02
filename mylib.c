#include "mylib.h"

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

int prnt_manual(int argc,char **argv){
    if(argc > 1 && !(strcmp(argv[1] ,"-h")) ) {
        printf("____________________________\n"
               " Manual\n"
               "____________________________\n"
               );
    }
    return 0;
}
