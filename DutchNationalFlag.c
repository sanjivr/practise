#include<stdio.h>
void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int main() {
  int data[10] = {0,1,2,0,1,2,0,2,1,0};
  int low = 1;
  int high = 2;
  int p = -1;
  int q = 10;
  int i;
  for (i = 0; i < q;) {
    if (data[i] < low) {
      swap(&data[i], &data[++p]);
      ++i;
    } else if (data[i] >= high) {
      swap(&data[i], &data[--q]);
    } else {
      ++i;
    }
  }

 for(i = 0; i < 10;i++){
	printf("%d\t", data[i]);
	}
	printf("\n");
}


