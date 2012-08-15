#include<stdio.h>
#include<string.h>
int main(){

char s[25];
while(1){
memset(s, 0, sizeof(s));
printf("%s\n", s);
scanf("%s", s);
char *end = NULL;
for (char *i = s; ; i++){
	if(*i == '\0'){
		end = i;
		break;
	}
}

for(char *i = s; i < end; i++) {
	for(char *j = end; j> i; j--){ //Shift from last duplicate to end of string
		if(*i == *j) {
			char *k = j;
			while(k < end) {
				*k = *(k+1);
				k++;
			}
			end--;
		}
	}

}


printf("\n%s\n", s);

}

}
