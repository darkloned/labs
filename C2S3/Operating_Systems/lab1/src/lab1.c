/*
 * Created by darkloned.
 * Task:
 *  Explore 12 different Linux system calls using C.
 *
 *  See log file for demonstration of working.
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MESSAGE "Hello, World!\n"
#define MSGSIZE 14

void catch(int status, char* errormsg) // imitation of try-catch exceptions
{
    if (status < 0)
    {
        printf("%s\n", errormsg);
        exit(1); // #1
    }
}
 
int main()
{
    printf("ProcessID: %d\n", getpid()); // #20
    catch(chdir("out"), "Error changing current working directory."); // #12
    catch(creat("file.txt", S_IRUSR | S_IWUSR), "Error creating a new file"); // #8

    int fileDescriptor = open("file.txt", O_RDWR); // #5

    catch(fileDescriptor, "Error opening a file and obtaining its file descriptor.");
 
    if (write(fileDescriptor, MESSAGE, MSGSIZE) != MSGSIZE) // #4
    {
        catch(-1, "Error writing to file.");
    }

    catch(lseek(fileDescriptor, MSGSIZE / 2, SEEK_SET), "Error changing the location of the RW pointer of a file descriptor."); // #19

    char buffer[MSGSIZE / 2];

    if (read(fileDescriptor, buffer, MSGSIZE / 2) != MSGSIZE / 2) // #3
    {
        catch(-1, "Error reading from file.");
    }

    write(fileDescriptor, buffer, MSGSIZE / 2);

    struct stat fileStat;

    catch(fstat(fileDescriptor, &fileStat), "Error getting information about file."); // #108
    printf("file.txt size: %ld bytes\n", fileStat.st_size);
    catch(close(fileDescriptor), "Error closing an opened file descriptor."); // #6

    time_t rawTime;

    time(&rawTime); // #13

    struct tm * timeinfo = localtime(&rawTime);

    printf("Current date and time: %s\n", asctime(timeinfo));

    fileDescriptor = dup(STDOUT_FILENO); // #41

    catch(fileDescriptor, "Error creating an alias for standart output.");
    catch(write(fileDescriptor, MESSAGE, MSGSIZE), "Error writing to standart output using file descriptor.");
 
    return 0;
}
