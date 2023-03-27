#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int num, renum;
	printf("请输入任意整数。");
	scanf("%d", &num);
	while(num >0){
		renum = renum * 10 + num % 10;
		num /= 10;
	}

	printf("%d", renum);
	return 0;
}
	

