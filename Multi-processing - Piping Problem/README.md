# Multi-processing - Piping Problem

## Overview
This project is a `pipex` implementation that reproduces a simple shell pipeline between two commands:
`< infile cmd1 | cmd2 > outfile`.

## Core Concepts Covered
- process creation with `fork`
- inter-process communication with `pipe`
- file descriptor redirection with `dup2`
- external command execution with `execve`
- `PATH` resolution and command parsing
- parent/child lifecycle management with `waitpid`

## Build
From this project directory:

```bash
make
```

## Run
Expected format:

```bash
./pipex infile "cmd1 arg1" "cmd2 arg2" outfile
```

Example:

```bash
./pipex infile "grep hello" "wc -l" outfile
```

## Notes
- This version expects exactly 4 arguments after the binary name.
- It focuses on mandatory pipex behavior (no here_doc flow in this codebase).
