#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int num, guess, atmp;
	srand(time(0));
	num = rand()%100 + 1;
	printf("������һ��1~100����Ȼ����");
	do{
		scanf("%d", &guess);
		++atmp;
		if(num > guess){
			printf("����");
		}
		if(num < guess){
			printf("ССС");
		}
	}while(num != guess);
	printf("���¶���������%d�Ρ�", atmp);
	return 0;
}
	

