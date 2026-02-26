# Projects

Portfolio-style overview of my C systems projects from the 42 curriculum, focused on low-level programming, Unix internals, rendering, and concurrency.



## Best 2 Projects (Start Here)

### [Unix Command Shell - Minishell](./Unix%20Command%20Shell%20-%20Minishell)
Built a shell with lexing/parsing, expansion, redirections, pipes, built-ins, and signal handling. This project best shows process control and Unix API understanding.

### [Raycasting Engine - cub3D](./Raycasting%20Engine%20-%20cub3D)
Built a Wolfenstein-style renderer from scratch with DDA raycasting, texture sampling, map validation, and an interactive game loop.



## Project Portfolio

### [Escape the Dragon Dungeon - Pac-Man Imitation](./Escape%20the%20Dragon%20Dungeon%20-%20Pac-Man%20Imitation)
Goal: Build a small playable 2D game (`so_long`) using strict map constraints.

Tech: C, MiniLibX, Makefile, Linux/X11.

Key Concepts: map parsing, flood fill, event hooks, tile rendering.

Biggest challenge: enforcing map validity and solvable paths while keeping the render loop stable.

What I learned?: how to combine data validation and interactive graphics in a clean C flow.



### [Multi-processing - Piping Problem](./Multi-processing%20-%20Piping%20Problem)
Goal: Recreate a shell-like 2-command pipeline (`pipex`).

Tech: C, POSIX (`fork`, `pipe`, `dup2`, `execve`, `waitpid`).

Key Concepts: process orchestration, file descriptor routing, `PATH` resolution.

Biggest challenge: preventing file descriptor leaks and handling child/parent error paths correctly.

What I learned?: how command execution really works under shell pipelines.



### [Multi-threading - Dining Philosophers Problem](./Multi-threading%20-%20Dining%20Philosophers%20Problem)
Goal: Solve Dining Philosophers with safe multithreading semantics.

Tech: C, pthreads, mutexes.

Key Concepts: synchronization, race prevention, monitor loop design, timing control.

Biggest challenge: balancing lock ordering with starvation/death detection.

What I learned?: practical thread-safety and shared-state discipline.



### [Tower of Hanoi - Sorting Algo](./Tower%20of%20Hanoi%20-%20Sorting%20Algo)
Goal: Sort integers using constrained stack operations (`push_swap`).

Tech: C, linked lists, Makefile.

Key Concepts: stack operations, pivot/chunk strategy, move minimization.

Biggest challenge: reducing operation count while keeping logic maintainable.

What I learned?: how algorithmic constraints shape data-structure design.



### [Raycasting Engine - cub3D](./Raycasting%20Engine%20-%20cub3D)
Goal: Build a simple 3D engine from a 2D map using raycasting.

Tech: C, MiniLibX, libft, Makefile.

Key Concepts: DDA raycasting, texture mapping, map/config parsing, game loop architecture.

Biggest challenge: rendering correctness plus robust validation and memory lifecycle handling.

What I learned?: how graphics math, parsing, and system-level C integrate end-to-end.



### [Unix Command Shell - Minishell](./Unix%20Command%20Shell%20-%20Minishell)
Goal: Implement a mini Bash-like interactive shell.

Tech: C, readline, POSIX process APIs.

Key Concepts: lexer/parser pipeline, expansion, pipes, redirections, built-ins, signals.

Biggest challenge: preserving shell semantics across many edge cases.

What I learned?: how to architect a stateful interactive Unix program.

## Continuous Integration
A minimal compile-only CI check is included for all projects:

- Workflow file: [`.github/workflows/compile-check.yml`](./.github/workflows/compile-check.yml)
- Purpose: verify each project still builds on Ubuntu with required system libraries.
