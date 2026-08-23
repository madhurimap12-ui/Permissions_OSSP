# Custom Shell Implementation — Project README

A C-based custom shell project focused on process abstraction and system-level programming, developed on a Linux environment.

## Phase 1: Environment Setup & Project Initialization

- **Install Linux VM** — Set up a Linux virtual machine as the development environment.
- **Configure GCC** — Install and verify the GNU Compiler Collection for compiling C source files.
- **Setup Git Repository** — Initialize version control and connect to a remote repository for tracking changes.
- **Create Project Structure** — Establish the directory layout (e.g. `src/`, `include/`, `bin/`, `docs/`).
- **Understand Shell Architecture** — Study how a Unix shell reads, parses, and executes commands.
- **Build Initial Makefile** — Write a Makefile to automate compilation and linking of the project.

## Phase 2: Process Abstraction & System Calls

- **Analyze Process Abstraction** — Study how the OS represents and manages running processes.
- **Execute `fork()`** — Implement and test process creation using the `fork()` system call.
- **Understand `exec()` Family** — Explore `execl()`, `execv()`, `execvp()`, etc. for replacing a process image.
- **Analyze Parent-Child Relationships** — Examine how `fork()` creates parent-child process links and how they communicate/synchronize.
- **Inspect Process Tree** — Use tools like `ps`, `pstree`, or `/proc` to visualize running process hierarchies.
- **Practice System Call Tracing** — Use `strace` to trace and debug system calls made by the shell.

## Getting Started

```bash
# Clone the repository
git clone <repo-url>
cd <project-directory>

# Build the project
make

# Run the shell
./shell
```

## Requirements

- Linux environment (VM or native)
- GCC compiler
- Git
- `strace` (for system call tracing)

## Status

🔧 In progress — environment setup and process abstraction phases underway.
