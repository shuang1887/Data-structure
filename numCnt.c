#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int isPrime(int x, int knownPrimes[], int numberOfKnownPrimes);

int main(){
	const int number = 100;
	int prime[number]; 
	prime[0] = 2;
	int count = 1;
	int i = 3;
	while (count < number){
		if (isPrime(i, prime, count)){
			prime[count++] = i;
		}
		i++;
	}
	for(i=0; i<number; i++){
		printf("%d", prime[i]);
		if( (i+1)%5 ){
			printf("\t");
		}
		else{
			printf("\n");
		}
	}
	return 0;
}

int isPrime(int x, int knownPrimes[], int numberOfKnownPrimes){
	int ret = 1;
	int i;
	for( i=0; i<numberOfKnownPrimes; i++ ){
		if ( x % knownPrimes[i] == 0){
			ret = 0;
			break;
		}
	}
	return ret;
}



	

