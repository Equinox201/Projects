# Escape the Dragon Dungeon - Pac-Man Imitation

## Overview
This project is a custom `so_long` implementation: a small 2D tile game built with MiniLibX.  
The player navigates a map, collects all items, and exits the dungeon while respecting map rules.

## Core Concepts Covered
- map parsing and validation (`.ber` format)
- flood-fill/path validation for map solvability
- event-driven programming with keyboard hooks
- 2D rendering with sprites using MiniLibX
- memory/resource cleanup in C

## Build
From this project directory:

```bash
make
```

## Run
Run with a map file:

```bash
./so_long maps/map1.ber
```

## Controls
- `W/A/S/D` or arrow keys: move
- `ESC`: quit

## Notes
- The game expects exactly one map argument.
- Linux/X11 MiniLibX is used (`-lX11 -lXext -lm -lz`).
