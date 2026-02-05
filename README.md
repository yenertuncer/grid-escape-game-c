# Grid Escape Game with Persistent State in C

## Description
A simple grid-based escape game implemented in C where the player moves on a board
to reach an exit door. The game state is saved to a file, allowing the player to
continue from the last position after restarting the program.

## Features
- Randomly generated game board
- Player and exit door placed at random positions
- Movement using WASD keys
- Persistent game state using file storage
- Reset functionality to start a new game
- Boundary-checked player movement

## Concepts & Techniques
- File I/O for game state persistence
- Random number generation
- Grid-based movement logic
- State management across program runs
- Basic game mechanics in C

## Technologies
- C
- GCC
- Standard C libraries (`stdio.h`, `stdlib.h`, `time.h`)

## How to Compile and Run
```bash
gcc main.c -o grid_escape
./grid_escape
