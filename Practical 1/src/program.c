#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
char command[100];
pid_t pid;

printf("Enter a Linux command: ");
scanf("%s", command);

pid = fork();
if (pid == 0)
{
printf("\nChild Process\n");
printf("Child PID: %d\n", getpid());
printf("Parent PID: %d\n", getppid());

execlp(command, command, (char *)NULL);
printf("Command execution failed\n");
exit(1);
}
else
{
printf("\nParent Process\n");
printf("Parent PID: %d\n", getpid());
printf("Child PID: %d\n", pid);
wait(NULL);
printf("\nChild process completed.\n");
}
return 0;
}
