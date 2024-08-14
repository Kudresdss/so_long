# so_long
so_long project for 42cursus

Currently works only on macOS and linux systems.

It is a simple 2D Top-Down maze game written from scratch in C and using the MiniLibx graphical library. The game's objective is to collect all the collectable chests before reaching the exit, while avoiding obstacles such as walls and enemies.

The game recieves a 2D map file with .ber extension. The map is written with these ASCII symbols:

|  Symbol  | Tile |
| :---: | :-------: |
| 0   | Floor   |
| 1   | Wall    |
| E   | Exit    |
| C   | Coin    |
| P   | Player  |
| X   | Enemy   |

Only the bonus part of the game has enemies that will try to catch the player. In bonus part, one of the collectible chests will always be converted into an aggressive mimic.
Maps are located in "maps" folder, one game instance can recieve only one map as an argument at a time.

All of the following actions must be done inside the copied project's directory, in the command line.

Compilation:
- run "make"

Compilation with bonus:
- run "make bonus"

Clean object files:
- run "make clean"

Full clean object and library files:
- run "make fclean"

Recompilation:
- run "make re"
