#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
int main() {
char command[100];
printf("Enter command: ");
scanf("%s", command);
int pid;
pid=fork();
if(pid==0){
printf("Child process");
printf("Child process id is %d\n",getpid());
printf("Parent process id is %d\n",getppid());
execlp(command, command, (char *)NULL);
}
else if(pid >0){
printf("Parent process \n");
printf("Child process id is %d\n", pid);
printf("Parent process id is %d\n", getpid());
wait(NULL);
}
else
printf("fork isfailure");

}
