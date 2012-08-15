#include<stdio.h>

int main(){

	int a[8] = {7,7,3,6,6,7,3,3};
	
	int *end = &a[7];
	int *begin = a;
	for ( ; begin <= end ; begin++){
		while(*end == *begin && begin != end) {
			end--;
		}
	
		int *next = begin + 1;
		for (;next <= end ; next++) {
			printf("comparing %d and %d \n", *begin, *next);
			if(*begin == *next)
			{
				printf("swapping %d and %d \n", *next, *end);
				int tmp = *next;
				*next = *end;
				*end = tmp;
				end--;
			}
		}
	}
	begin = a;
	for(; begin <= end; begin++){
		printf("%d\t", *begin);
	}

}
