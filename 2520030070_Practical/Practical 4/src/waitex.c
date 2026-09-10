#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>// used for the wait() and waitpid() system calls
#include<stdlib.h>// used for the exit() system call
int main()
{
int pid[3];// array declaration (initializing 3 childs)
for(int i=0;i<3;i++) // loop which runs for 3 childs
{
pid[i]=fork(); //creating 3 childs
if(pid[i]==0) // indicates a child process
{
printf("Child %d pid=%d\n",i+1,getpid());
sleep(i+1); // giving a pause after every child
exit(0);// exits the standard input form the user
}
}
// parents should wait till the finish the
//----- For the Child 1------
wait(NULL); 
printf("Parent: One child is completed with wait()\n");
//----- For the Child 2------
waitpid(pid[2],NULL,0);
printf("Parent: Child 3 has completed with waitpid()\n");
//----- For the Child 3-------
wait(NULL);
printf("Parent: All the childs are Completed\n");
}
