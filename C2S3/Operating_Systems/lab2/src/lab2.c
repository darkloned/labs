/*
 * Created by darkloned.
 * Task 27:
 *  Managing system processes and using pipes.
 *  Get string S as a parameter. Create N child processes,
 *  pass them a filename and S[i] character to write it out.
 *
 *  See log file for usage example.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define EOS '\0' // End Of String
#define MEMBUFFER 128 // that should be enough

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("Incorrect arguments.\n");

		return 1;
	}

	char* inputString = argv[1];

	for (int charID = 0; charID < strlen(inputString); ++charID)
	{
		int fileDescriptor[2];
		// fileDescriptor[0] - reading end
		// fileDescriptor[1] - writing end

		if (pipe(fileDescriptor) == -1)
		{
			printf("Pipe error.\n");

			return 1;
		}

		pid_t processID = fork();

		if (processID < 0)
		{
			printf("Fork error.\n");

			return 1;
		}
		else if (processID > 0) // parent
		{
			close(fileDescriptor[0]);

			char* filename = malloc(MEMBUFFER);
			char* fileOutput = malloc(2);

			snprintf(filename, MEMBUFFER, "out/%s%d%s", inputString, charID + 1, ".txt\0");

			fileOutput[0] = inputString[charID];
			fileOutput[1] = EOS;

			write(fileDescriptor[1], filename, MEMBUFFER);
			write(fileDescriptor[1], fileOutput, 2);
			
			close(fileDescriptor[1]);

			int exitStatus = 0;

			wait(&exitStatus);

			free(filename);
			free(fileOutput);

			if (WEXITSTATUS(exitStatus))
			{
				printf("Writing to file error.\n");

				return 1;
			}
		}
		else // child
		{
			close(fileDescriptor[1]);

			char* filename = malloc(MEMBUFFER);
			char* fileOutput = malloc(2);

			read(fileDescriptor[0], filename, MEMBUFFER);
			read(fileDescriptor[0], fileOutput, 2);

			FILE* file = fopen(filename, "w");

			if (fprintf(file, "%s\n", fileOutput) < 0)
			{
				exit(1);
			}

			fclose(file);

			free(filename);
			free(fileOutput);

			exit(0);
		}
	}

	return 0;
} 
