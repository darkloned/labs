/*
 * Created by darkloned.
 * Task 9-dynamic:
 *  Create dynamic link library from
 *  "Task 9-static" sources and use it
 *  during runtime, loading it into
 *  memory via system calls.
 */

#include <dlfcn.h>

#include "stack.h"

void dlErrorException(char* dlerror)
{
	printf("%s\n", dlerror);
	exit(1);
}

int main(int argc, char* argv[])
{
	Stack* (*newStack)(int poolsize);
	bool (*isEmpty)(Stack* s);
	void (*printStack)(Stack* s);
	void (*push)(Stack* s, double item);
	double (*pop)(Stack* s);
	void (*deleteStack)(Stack* s);

	void* handle = dlopen("lib/stack.so", RTLD_LAZY);

	if (!handle)
	{
		dlErrorException(dlerror());
	}

	newStack = dlsym(handle, "newStack");
	isEmpty = dlsym(handle, "isEmpty");
	printStack = dlsym(handle, "printStack");
	push = dlsym(handle, "push");
	pop = dlsym(handle, "pop");
	deleteStack = dlsym(handle, "deleteStack");

	if (dlerror())
	{
		dlErrorException(dlerror());
	}

	Stack* s = (*newStack)(8);

	(*push)(s, 3.14159);
	(*push)(s, 2.71828);
	(*push)(s, 1.61803);
	(*push)(s, 42.4242);

	if (!(*isEmpty)(s))
	{
		printf("%.5f\n", pop(s));
	}
	(*printStack)(s);

	(*deleteStack)(s);

	return 0;
}
