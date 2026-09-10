#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> // for wait system call
#include <time.h> // for clock() and CLOCKS_PER_SEC

int main()
{
int fd[2]; // parameter for anonymous pipe
int data; // variable that writes data to pipe
clock_t start, end; // variables for start and end times
double timetaken, eff; // variables for communication time and efficiency
pipe(fd); // create anonymous pipe
start = clock(); // start measuring time
if (fork() == 0) // create child process
{
close(fd[1]); // close write end of pipe
printf("Consumer\n"); // display consumer
for (int i = 0; i < 5; i++) // consume 5 values
{
read(fd[0], &data, sizeof(data)); // read data from pipe
printf("Consumed %d\n", data); // display consumed data
}
close(fd[0]); // close read end of pipe
}
else
{
close(fd[0]); // close read end of pipe
printf("Producer\n"); // display producer
for (int i = 1; i <= 5; i++) // produce 5 values
{
data = i * 10; // generate data
write(fd[1], &data, sizeof(data)); // write data to pipe
printf("Produced %d\n", data); // display produced data
}
close(fd[1]); // close write end of pipe
wait(NULL); // wait for child process to finish
end = clock(); // stop measuring time
timetaken = (double)(end - start) / CLOCKS_PER_SEC; // calculate communication time
eff = 5.00 / timetaken; // calculate communication efficiency
printf("Communication time is %lf\n", timetaken); // display communication time between the process
printf("Communication Efficiency is %lf\n", eff); // display communication efficiency
}
return 0; // end program
}


