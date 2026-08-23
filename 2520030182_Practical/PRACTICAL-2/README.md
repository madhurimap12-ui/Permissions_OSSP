# System Call Tracing using `strace`

## Aim

To use `strace` to see the system calls made by the command:

```bash
cat sample.txt
```

and understand what the Linux kernel is doing behind the scenes.

## Steps

### 1. Create a sample file

```bash
echo "Hello World" > sample.txt
```

### 2. Run `strace`

```bash
strace cat sample.txt
```

This runs `cat` and shows the system calls it makes.

To save the output:

```bash
strace -o trace.txt cat sample.txt
```

## Important System Calls

While running the command, we can see system calls such as:

- **`execve()`** – starts the `cat` program.
- **`openat()`** – opens `sample.txt`.
- **`read()`** – reads the contents of the file.
- **`write()`** – displays the contents on the terminal.
- **`close()`** – closes the file.
- **`exit_group()`** – ends the `cat` program.

The exact output can be different depending on the Linux system.

## Simple Flow

```text
Start cat
   ↓
Open sample.txt
   ↓
Read the file
   ↓
Write the contents to the screen
   ↓
Close the file
   ↓
Exit
```

## Kernel Services Involved

The main kernel services used are:

1. **Process management** – starts and stops the program.
2. **File management** – opens and closes the file.
3. **Input/Output management** – reads the file and writes its contents to the screen.

## Conclusion

Although `cat sample.txt` looks like a very simple command, it uses several system calls to communicate with the Linux kernel.

The main sequence is:

```text
open → read → write → close
```

Using `strace` helps us understand what happens inside the system when a normal Linux command is executed.
