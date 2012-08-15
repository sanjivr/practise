#include<stdio.h>

void swap(int *a, int *b) {
	
	int t = *a;
	*a = *b;
	*b = t;
}

int main() {
	int n = 5;
	int a[n][n];
	int count = 0;	
	int i, j;
	for (i = 0; i < n; i++) {
		for(j =0 ; j <n; j++) {
			a[i][j] = count++;
		}
	}

	for (i = 0; i < n; i++) {
		for(j =0 ; j <n; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	

	for (i = 0; i < n-2; i++) {
		for(j = i+1 ; j <n; j++) {
			swap(&a[i][j], &a[j][i]);
		}
	}

	for(i = 0; i < n; i++) {
		for(j = 0; j< (n-1)/2; j++) {
			swap(&a[i][j], &a[i][n-j-1]);
		}

	}

		printf("\n");
		printf("\n");
		printf("\n");
	for (i = 0; i < n; i++) {
		for(j =0 ; j <n; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	
}
