#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int find(const char *str, const char *p)
{
	int LenStr = strlen(str);
	int LenP = strlen(p);
	int i = 0,j = 0;

	for(i = 0; i < LenStr; i++)
	{
		j = 0;
		while((i+j < LenStr) && (j < LenP) && (str[i+j] == p[j]))
			j++;
		if(j == LenP)
			return i;
	}

	return -1;

}


int main(int argc, char *argv[])
{
	const char *str = "abcdefghijklmmnx";
	const char *p = "mmn";
	printf("index: %d\n", find(str, p));

	return 0;
}