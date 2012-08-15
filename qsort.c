#include<stdio.h>

int pivot(int *a, int l, int h) {
	int p = l;
	int i = l;
	int j = h;
	while(1) {
		while( *(a+j) > *(a+p) && j >= l)
			j--;
		while( *(a+i) < *(a+p) && i <= h)
			i++;

		if(i < j) {
			int tmp = *(a+j);
			*(a+j) = *(a+i);
			*(a+i) = tmp;
		} else {
			return j;
		}
	}
}

void qsort(int *a, int l,int  h) {
	if( l >= h ) {
		return;
	}
	int p = pivot(a, l, h);
	printf("Pivot %d\n", p);
	int i;
	for ( i = l; i <= h; i++) {
		printf("%d\t", *(a+i));
	}
	printf("\n");
	qsort(a, l, p);
	qsort(a, p+1, h);
}

int main() {

	int a[10] = {45, 23, 56, 12, 24, 57, 97, 72,10, 13};

	qsort(a, 0, 9);
	int i;
	for ( i = 0; i < 10; i++) {
		printf("%d\t", a[i]);
	}

	printf("\n");
	
}
