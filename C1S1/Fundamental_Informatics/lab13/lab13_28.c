#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define VOWELS (1u<<('a'-'a')|1u<<('e'-'a')|1u<<('i'-'a')|1u<<('o'-'a')|1u<<('u'-'a'))

const char* delims = " .,!?:;+-*=/|\\(){}[]<>\n";

bool isDelim(char c)
{
	return (strchr(delims, c) != NULL);
}

unsigned int nextWordToSet()
{
	unsigned int wordset = 0;
	int c;

	while (isDelim(c = getchar())) {}
	
	if (c == EOF) return 0;

	do
	{
		wordset |= 1u << (tolower(c) - 'a');
	}
	while (!isDelim(c = getchar()) && (c >= 'a' && c <= 'z'));

	return wordset;
}

bool onlyVowels(unsigned int wordset)
{
	return ((wordset | VOWELS) == VOWELS);
}


int main()
{
	unsigned int wordset;
	bool found = false;

	while ((wordset = nextWordToSet()) != 0)
	{
		if (onlyVowels(wordset))
		{
			found = true;
			break;
		}
	}

	printf(found ? "YES\n" : "NO\n");

	return 0;
}
