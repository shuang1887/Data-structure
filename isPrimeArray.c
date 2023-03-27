#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void minmax(int a[], int len, int *min, int *max);

int main(){
	int a[] = {1, 2, 4, 6, 8, 9, 11, 14, 15, 34, 56, };
	int min, max;
	minmax(a, sizeof(a)/sizeof(a[0]), &min, &max);
	printf("min=%d, max=%d", min, max);
	
	return 0;
}

void minmax(int a[], int len, int *min, int *max){
	int i;
	*min = *max = a[0];
	for(i=1; i<len; i++){
		if(a[i] < *min){
			*min = a[i];
		}
		if(a[i]> *max){
			*max = a[i];
		}
	}
}




	

