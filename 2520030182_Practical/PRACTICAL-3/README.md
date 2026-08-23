# Process Creation and State Transitions in Linux

## Aim

To create a parent and child process using `fork()` and observe their process IDs and different process states using Linux tools like `ps`, `top`, and `/proc`.

## Part 1: C Program using fork()

The following program creates a child process from a parent process and displays the PID, PPID, and current state.

```c
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
pid_t pid=fork();

if(pid<0){
printf("Fork failed\n");
}
else if(pid==0){
printf("Child Process\n");
printf("PID: %d\n",getpid());
printf("PPID: %d\n",getppid());
printf("State: Running\n");
sleep(5);
printf("Child finished\n");
}
else{
printf("Parent Process\n");
printf("PID: %d\n",getpid());
printf("PPID: %d\n",getppid());
printf("Child PID: %d\n",pid);
printf("State: Running\n");
wait(NULL);
printf("Child completed\n");
}
return 0;
}
```

## How to Run

Save the program as `process.c`.

Compile it:

```bash
gcc process.c -o process
```

Run it:

```bash
./process
```

The program will display the PID and PPID of both processes.

## Part 2: Observing Process States

Linux processes can move through different states during their lifetime.

For this experiment, we observe:

- **Ready** – The process is ready to run and is waiting for CPU time.
- **Running** – The process is currently using the CPU.
- **Waiting** – The process is waiting for something, such as I/O or another process.
- **Terminated** – The process has finished execution.

### Using `ps`

First run the program:

```bash
./process
```

While it is running, use:

```bash
ps -ef | grep process
```

You can also check a particular process:

```bash
ps -o pid,ppid,state,cmd -p PID
```

Replace `PID` with the actual process ID.

The `STATE` column shows the current process state.

### Using `top`

Run:

```bash
top
```

Find the parent or child process using its PID.

The `S` column shows the process state. The value can change depending on what the process is doing.

Press `q` to exit `top`.

### Using `/proc`

Linux provides process information inside `/proc`.

For a process with PID 1234:

```bash
cat /proc/1234/status
```

Look for the line:

```text
State:
```

This shows the current state of the process.

## Observations

| Stage | Expected Observation |
|---|---|
| Before `fork()` | Only the parent process exists |
| After `fork()` | Parent and child processes exist |
| Child during `sleep()` | Child is waiting/sleeping |
| Parent during `wait()` | Parent is waiting for the child |
| After child finishes | Child is terminated |
| After `wait()` returns | Parent continues and eventually terminates |

The exact order and timing may be slightly different because Linux decides when each process gets CPU time.

## Conclusion

This experiment shows how `fork()` creates a child process and how the parent and child can have different PIDs and PPIDs.

Using `ps`, `top`, and `/proc` helps us see what is happening to the processes while the program is running.

In simple terms:

```text
Parent
  |
 fork()
  |
  +----> Child
  |        |
  |      Running
  |        |
  |      Waiting
  |        |
  |    Terminated
  |
Waiting for child
  |
Continues
  |
Terminated
```

This experiment helps us understand process creation, process IDs, and basic process state changes in Linux.
