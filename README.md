# game_project
game project that I have made

This is a lights out game I have write
import the q2b file to a linux system supports g++14
call make command
run the q2b.exe to play the game
Note: this game requires Xming to enable the graphical output


How to play?

new n :Creates a new n  n grid, where n  1. If there was already an active grid,
that grid is destroyed and replaced with the new one.

init :Enters initialization mode. Subsequently, read pairs of integers r c and set
the cell at row r, column c as on. The top-left corner is row 0, column 0. The
coordinates -1 -1 end initialization mode. It is possible to enter initialization mode
more than once, and even while the game is running. When initialization mode
ends, the board should be displayed.

game g :Once the board has been initialized, this command starts a new game, with
a commitment to solve the game in g moves or fewer.

switch r c :Within a game, switches the cell at row r, column c on or off, and then
redisplays the grid.

Here is a sample game process:
new 5
init
1 2
2 2
3 2
-1 -1
_____
__X__
__X__
__X__
_____
game 3
3 moves left
switch 2 2
_____
_____
_X_X_
_____
_____
2 moves left
switch 3 1
_____
_____
___X_
XXX__
_X___
1 move left
switch 3 3
_____
_____
_____
XX_XX
_X_X_
0 moves left
Lost


Now go ahead and try it out!!!!
