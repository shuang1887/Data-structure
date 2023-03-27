#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i = 1, j = 0, isPrime = 1, count = 1;
	//scanf("%d", &x);
	do{
		isPrime = 1;
		for(j = 2; j < i; j++){
			if(i % j == 0){
			isPrime = 0;
			break;//发现一次被整除，就立即跳出循环，不需要把i遍历。	continue是跳过当前轮次的循环 
			}
		}
		if(isPrime == 1){
			printf("%d.%d, ", count, i);
			count++;
		}
		i++;
	}while(count <= 50);	
}


	

