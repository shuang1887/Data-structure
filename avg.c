#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int x, sum, count;
	printf("���������֣�ȷ�Ϻ󰴻س���");
	do{
		scanf("%d", &x);
		sum += x;
		++count; 
	}while(count <= 10);
	printf("ƽ����Ϊ%lf", 1.0*sum / count);
	return 0;
}
	

