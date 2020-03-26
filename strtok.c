#include <stdio.h> 
#include <string.h> 

int main() 
{ 

        char str[10];
	char* token = strtok('\0'," ");
        strcpy(str,strtok('\0'," "));
	while (token != NULL) { 
		printf("%s\n", token); 
		token = strtok(NULL, "-"); 
	} 

	return 0; 
} 
