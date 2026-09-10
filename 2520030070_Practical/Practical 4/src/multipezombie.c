#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>//header file for wait or waitpid
#include<stdlib.h>//header file for exit()
int main(){
int pid[3];
for(int i=0;i<3;i++){
pid[i]=fork();
if(pid[i]==0){
printf("Chid %d pid=%d\n",i+1,getpid());
exit(0);
}
}
//printf("Parent process %d\n",getpid());
//sleep(30);
for(int i=0;i<3;i++){
wait(NULL);
printf("Parent collected Child %d\n",i+1);
}
}