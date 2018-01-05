#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	char* surnames[10] = {  "Ivanov" ,	"Ivanova" ,
							"Petrov" ,	"Petrova" ,
							"Orlov"	 ,	"Orlova"  ,
							"Egorov",	"Egorova" ,
							"Kozlov" ,	"Kozlova"	};
	
	char* cpu[2] 	 = { "Intel"  , "AMD" 	};
	int cpu_cores[2] = { 2		  , 4 		};
   	char* os[2] 	 = { "Windows", "Linux" };

	srand(time(NULL));	
	
	stdout = freopen("table.txt", "w+", stdout);

	FILE *table = stdout;

	stdout = fopen("table.txt", "w+");

	for (int i = 0; i < 10; i++)
    	printf("%d\t%s\t\t%s\t%d\t%s\n",i + 1,
										surnames [i],
										cpu		 [rand() % 2],
										cpu_cores[rand() % 2],
										os		 [rand() % 2]	);

	fclose(stdout);

	stdout = table;

	return 0;
}
