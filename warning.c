#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <time.h>

int main()
{
   struct tm start = {0};
   char *result = "\0";
   char start_str[20] = "30 Dec 2019 12:33:45";
   result = strptime(start_str,"%m/%d/%Y %H:%M",&start);
}
