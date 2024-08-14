# so_long
so_long project for 42 cursus

Currently works only on macOS and linux systems.

It is a simple 2D Top-Down maze game written from scratch in C and using the MiniLibx graphical library. The game objective is to collect all the collectibles before reaching the exit, while avoiding obstacles such as walls and enemies.

The game recieves a 2D map file with .ber extension. The map is written with these ASCII symbols:

| --- | ------- |
| 0   | Floor   |
| 1   | Wall    |
| E   | Exit    |
| C   | Coin    |
| P   | Player  |
| X   | Enemy   |

Only the bonus part of the game has enemies that will try to catch the player.
Maps are located in "maps" folder, one game instance can recieve only one map as an argument at a time.
