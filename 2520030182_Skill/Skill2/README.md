# Custom Shell Implementation

A shell, built from scratch in C, running on Linux. This project is as much about understanding how the OS handles processes and input as it is about writing code — every piece here maps back to something happening under the hood when you type a command and hit Enter.

## Phase 1: Getting the Environment Ready

Before writing a single line of shell logic, the groundwork had to be laid. This phase was about setting up a proper development environment and getting comfortable with the tools.

- Spun up a **Linux VM** to have a clean, dedicated space to build and test in.
- Installed and configured **GCC** so C code could actually compile.
- Set up a **Git repository** to track changes and keep the project versioned from day one.
- Laid out a sensible **project structure** — folders for source, headers, binaries, and docs.
- Spent time actually **understanding shell architecture** — how a shell reads a line, figures out what it means, and hands it off to the OS.
- Wrote the **first Makefile** so the whole thing could be built with a single command instead of manual compiling.

## Phase 2: Learning How Processes Really Work

This is where things got interesting — moving from "how do I compile this" to "how does a process actually come into being."

- Broke down what **process abstraction** really means at the OS level.
- Got hands-on with **`fork()`**, watching a single process split into a parent and a child.
- Explored the **`exec()` family** to understand how a process image gets replaced with something new entirely.
- Traced through **parent-child relationships** to see how the two stay connected (and when they don't).
- Used tools like `ps` and `pstree` to actually **look at the process tree** instead of just imagining it.
- Practiced **tracing system calls** with `strace` to see exactly what's happening beneath the C code.

## Phase 3: Building the Interactive Loop

With the fundamentals in place, it was time to make the shell feel like an actual shell — something you can sit down and type into.

- Built the **main loop** that keeps the shell alive and responsive after every command.
- Designed a **prompt** that displays before each input, the way `$` or `>` would in a real terminal.
- Wired up **reading user input** so the shell actually listens before doing anything.
- Handled **exit conditions** properly, so the shell knows when to shut down gracefully instead of just hanging or crashing.
- Sketched out a **control flow diagram** to map the loop's logic before diving deeper into edge cases.
- Ran the loop through repeated **interactive testing** to catch anything that broke under real use.

## Phase 4: Handling Keyboard Input Properly

A shell isn't just about running commands — it's about handling everything a person might type, including mistakes.

- Set up **keyboard input capture** at a lower level than just waiting for a full line.
- Handled the **backspace key** so users can actually correct typos instead of being stuck with them.
- Processed the **Enter key** as the signal that a command is ready to run.
- Managed an **input buffer** to hold characters as they're typed, before the command is finalized.
- Made sure the shell could **support multi-character commands**, not just single letters or symbols.
- Went through rounds of **testing real user interaction** to make sure typing actually feels natural.

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

🔧 In progress — core loop and input handling are up and running; refinements ongoing.
