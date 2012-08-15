#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

int main(){

	char s[MAX_SIZE];
	int charfound = 0;
	int count = 0;
	char *c = s;
	char *n = s+1;

	printf("Enter a string: ");

	if ( fgets(s, sizeof s, stdin) != NULL )
	{
		char *newline = strchr(s, '\n'); /* search for newline character */
		if ( newline != NULL )
		{
			*newline = '\0'; /* overwrite trailing newline */
		}
		printf("text = \"%s\"\n", s);
	}
	printf("\n");

	if( *s == '\0') {
		printf("Words:%d\n", count);
		return 0;	
	}

	while(1){
		if(*c != ' ') {
			if( *n == ' '){
				count++;
			}
			else if( *n == '\0')
				count++;
				printf("Words:%d\n", count);
				return 0;
			}
			
		}
		if(*n == '\0')
		{
				printf("Words:%d\n", count);
				return 0;
		}	

		c++;
		n++;
	} 
}
