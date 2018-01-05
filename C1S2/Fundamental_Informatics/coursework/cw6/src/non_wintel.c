#include<stdio.h>
#include<string.h>

#include"config.h"

int main()
{
	Config conf;

	FILE* table = fopen("table.bin", "r");

	if (!table) // no such file
	{
		printf("FileNotFoundException: table.bin doesn't exist.\n");

		return 1;
	}

	printf("Non-Wintel computers are: "); 

	while(fread(&conf, sizeof(conf), 1, table))
		if (strcmp(conf.cpu, "Intel") || strcmp(conf.os, "Windows"))
			printf("%d ", conf.n);

	printf("\n");

	fclose(table);

	return 0;
}
