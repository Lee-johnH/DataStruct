/*�ó��������õݹ麯����ʵ�ֽ��������ⳤ�ȵ��ַ�����������Ĺ��ܡ����磺����
  �ַ���FishC��������ַ���ChsiF
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