#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int num, guess, atmp;
	srand(time(0));
	num = rand()%100 + 1;
	printf("请您猜一个1~100的自然数。");
	do{
		scanf("%d", &guess);
		++atmp;
		if(num > guess){
			printf("大大大");
		}
		if(num < guess){
			printf("小小小");
		}
	}while(num != guess);
	printf("您猜对辣！用了%d次。", atmp);
	return 0;
}
	

