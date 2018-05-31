#include <stdio.h>
#include <assert.h>

int my_strlen(const char *str)
{
	assert(*str != '\0');
	const char *cp = str;
	while(*cp++ != '\0')
		;
	return (cp - str - 1);

}

int main(void)
{
	char *p = "123";
	printf("%d\n", my_strlen(p));

	return 0;

}