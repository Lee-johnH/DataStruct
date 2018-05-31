/*该程序是利用递归函数，实现将输入任意长度的字符串反向输出的功能。例如：输入
  字符串FishC，则输出字符串ChsiF
*/

#include <stdio.h>

void print()
{
	char a;
	scanf("%c", &a);
	if(a != '#')
	{
		print();
		printf("%c",a);
	}
		
}

int main()
{
	print();

	return 0;
}