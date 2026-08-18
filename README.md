# Practical / Skill-01

## Title
Process Creation and Command Execution Using fork(), exec() and 
wait()

## Objective
To develop a C program that demonstrates how an operating system 
executes a command entered by a user.

## Requirements
1. Accept a Linux command as input.
2. Create a child process using fork().
3. Execute the command in the child process using an appropriate 
exec() system call.
4. Allow the parent process to wait for the child using wait().
5. Display the Process ID (PID) of both parent and child 
processes.

## System Calls Used

### fork()
The fork() system call creates a new child process.

### execlp()
The execlp() system call replaces the child process with the 
specified command.

### wait()
The wait() system call allows the parent process to wait until 
the child process finishes.

### getpid()
getpid() returns the Process ID of the current process.

### getppid()
getppid() returns the Process ID of the parent process.

## Hardware and Operating System Investigation

The following commands are used to investigate hardware resources 
and operating system services:

- uname
- lscpu
- lsblk
- ps
- top

These commands help understand how the operating system manages 
CPU, memory, storage and I/O devices.

## Conclusion

The practical demonstrates process creation using fork(), command 
execution using execlp(), and synchronization using wait(). It 
also demonstrates how operating system services provide an 
abstraction between user programs and computer hardware.
