# Multi-threading - Dining Philosophers Problem

## Overview
This project implements the classic Dining Philosophers concurrency problem using POSIX threads and mutexes.
It simulates philosopher lifecycles (eat, sleep, think) while preventing data races and handling death/stop conditions.

## Core Concepts Covered
- multithreading with `pthread`
- shared-state synchronization with mutexes
- thread-safe logging and state transitions
- starvation/death monitoring loops
- timing and scheduling in concurrent systems

## Build
From this project directory:

```bash
make
```

## Run
Required arguments:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [must_eat_count]
```

Example:

```bash
./philo 5 800 200 200
```

## Notes
- `must_eat_count` is optional.
- This implementation enforces input validation and bounded philosopher count.
