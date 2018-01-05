#include <stdio.h>

int foo()
{
	return 1;
}

int bar(int x)
{
	return foo();
}

int main()
{
	int x;
	scanf("%d", &x);

	bar(x);

	return 0;
}
