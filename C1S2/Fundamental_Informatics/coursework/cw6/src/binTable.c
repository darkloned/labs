#include<stdio.h>

#include"config.h"

int main()
{
	FILE* table = 	 fopen("table.txt", "r");
	FILE* binTable = fopen("table.bin", "w");

	if (!table) // no such file
	{
		printf("FileNotFoundException: table.txt doesn't exist.\n");

		return 1;
	}

	Config conf;

	while(fscanf(table, "%d %s %s %d %s", &conf.n, conf.surname, conf.cpu, &conf.cpu_cores, conf.os) != EOF)
		fwrite(&conf, sizeof(conf), 1, binTable);

	fclose(table);
	fclose(binTable);

	return 0;
}
