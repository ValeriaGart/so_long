# SO_LONG

Omg that's my first written from the scratch game!🐣

## Description

```
• The player’s goal is to collect every collectible present on the map, then escape
chosing the shortest possible route.
• The W, A, S, and D keys must be used to move the main character. (I also implemented arrows additionally)
• The player should be able to move in these 4 directions: up, down, left, right.
• The player should not be able to move into walls.
• At every move, the current number of movements must be displayed in the shell.
• You have to use a 2D view (top-down or profile).
• The game doesn’t have to be real time.
```

All the graphical content is also created by me, look how pretty it is:

![](https://github.com/ValeriaGart/so_longg/blob/master/gameplay.gif)

## How?

First of all I used the graphical library provided by 42 codding school.

The maps for games you can find in the maps folder. There are some of created by me, but you may ofc add yours! The symbols for those are:

```
0 for an empty space,
1 for a wall,
C for a collectible,
E for a map exit,
P for the player’s starting position

bonus:
V for the villain
```

My program checks the map, opens the window and puts the tiles on it appropriately. It's all very manual, so i just rerender everything when something has to move due to the catched signal. I also have moves count in the terminal.

For the bonus version i added villains, animation and count on the screen (top left corner).

The pictures are stored in textures folder in .ber format.

Nothing more to add about how it's done, the rest are basic algorythms in C. Go check my code if you like or just run and play my game ^^

## How to run 

📍runs only on linux because of the school library📍

`make` compile without bonus (all the bonus maps will appear to be invalid, only basic stuff works)

`make bonus` compile with bonus part

`make clean` remove *.o files

`make fclean` remove *.o + executables 

run basic programm with `./so_long path/to/the/map`

run bonus programm with `./so_long_bonus path/to/the/map`

