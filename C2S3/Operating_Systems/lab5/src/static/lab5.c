/*
 * Created by darkloned.
 * Task 9-static:
 *  Implement stack library and use it
 *  during compile time in the linking phase.
 */

#include "stack.h"

int main(int argc, char* argv[])
{
	Stack* s = newStack(8);

	push(s, 3.14159);
	push(s, 2.71828);
	push(s, 1.61803);
	push(s, 42.4242);

	if (!isEmpty(s))
	{
		printf("%.5f\n", pop(s));
	}
	printStack(s);

	deleteStack(s);

	return 0;
}
