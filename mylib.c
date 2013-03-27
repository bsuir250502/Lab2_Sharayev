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
