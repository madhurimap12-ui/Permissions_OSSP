#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
// Part one of the program
int main()
{
int pid;
pid=fork();
if(pid==0)
{
printf("Child process %d\n",getpid());
exit(0);
}
else
{
printf("Parent process %d\n", getpid());
sleep(30); // for Zombie
//wait(NULL);// collecting the status of the child
printf("Parent process completed\n");
}
} 
