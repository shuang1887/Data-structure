#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int x, sum, count;
	printf("请输入数字，确认后按回车。");
	do{
		scanf("%d", &x);
		sum += x;
		++count; 
	}while(count <= 10);
	printf("平均数为%lf", 1.0*sum / count);
	return 0;
}
	

