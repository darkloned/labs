#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char* delims = " .,!?:;+-*=/|\\(){}[]<>\n";
const char* hexs = "0123456789ABCDEF";

bool isDelim(char c)
{
	return (strchr(delims, c) != NULL || c == EOF);
}

bool isHex(char c)
{
	return (strchr(hexs, c) != NULL);
}

int strtohex(char c)
{
	return (strchr(hexs, c) - hexs);
}

int main()
{
	const int prefix_empty = 0, prefix_0 = 1, prefix_0x = 2;

	char c;
	int prefix = prefix_empty;
	bool hexPossible  = true;
	int sumEven = 0, sumOdd = 0, sum = 0;
	int i = 0;

	do
	{
		c = toupper(getchar());

		if (!hexPossible)
		{
			hexPossible = isDelim(c);
			continue;
		}

		if (prefix == prefix_empty && c == '0')
		{
			prefix = prefix_0;
		}
		else if (prefix == prefix_0 && c == 'X')
		{
			prefix = prefix_0x;
		}
		else if (prefix == prefix_0x && isHex(c))
		{
			int cHex = strtohex(c);
			i++;

			if (i % 2 == 0)
			{
				sumEven += cHex;
			}
			else
			{
				sumOdd += cHex;
			}
		}
		else 
		{
			if (isDelim(c))
			{
				sum += (i % 2 == 0) ? sumEven : sumOdd;
			}
			else
			{
				hexPossible = false;
			}

			i = 0;
			prefix = prefix_empty;
			sumEven = sumOdd = 0;
		}
	}
	while (c != EOF);
	
	printf("0x%X\n", sum);

	return 0;
}
