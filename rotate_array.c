#include<stdio.h>


/*
	Rotate a [m * n] array by 90 degrees

	Create an [n * m] array
	b[j][m-i-1] =	a[i][j] 90 DEGREES TO right
	b[n-j-1][i] = 	a[i][j] 90 DEGREES to left
	

*/

int main() {

	int a[5][7];
	int count = 0;
	int i, j;
	for (i=0 ; i< 5; i++)
	{
		for (j = 0; j<7; j++)
		{
			a[i][j] = count++;
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}

	int b[7][5];
	for(i = 0; i < 5; i++){
		for(j =0; j<7; j++) 
		{
			b[j][5-i-1] = a[i][j];
		}
	}
	
	printf("90 degree rotation");
	for(i =0; i< 7; i++){
		printf("\n");
		for(j =0; j< 5; j++) {
			printf("%d\t", b[i][j]);
		}
	}

}
