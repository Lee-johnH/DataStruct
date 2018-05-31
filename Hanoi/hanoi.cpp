#include <stdio.h>

//将 n 个盘子从 x 借助 y 移动到 z
void move(int n, char x, char y, char z)
{
	if(1 == n)
		printf("%c--->%c\n",x, z);
	else
	{
		move(n-1, x, z, y);		//将n-1个盘子从x借助z移动到y
		printf("%c--->%c\n", x, z);	//将第n个盘子从x移动到z
		move(n-1, y, x, z);			//将n-1个盘子从y借助x移动到z
	}

}

int main()
{
	int num = 0;
	printf("请输入汉诺塔层数：");
	scanf("%d", &num);
	printf("移动步骤如下：\n");
	move(num, 'x', 'y', 'z');

	return 0;
}