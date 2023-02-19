# Alien vs. Zombie

Our team found out about a game called Alien Path and are intrigued by it. Hence, we decided to try and create our own little simplified version of the game. Our own version of the game would be named as Alien vs. Zombie which is exactly what the game is all about. Players need to utilise their knowledge on RPG, path-planning, and much more in order to defeat their enemies —— Zombie. There are much more details regarding it, and players can try it out to get a gist about it !

You may add one signature screenshot of your program here or above the title. Check out [this tutorial](https://www.digitalocean.com/community/tutorials/markdown-markdown-images) to learn how to do it.

Please provide the YouTube link to your [Video Demo](https://youtube.com).

## Compilation Instructions
```
g++ main.cpp pf/GameSetting.cpp pf/helper.cpp pf/Character.cpp pf/GameBoard.cpp pf/GameCommand.cpp pf/GameObject.cpp pf/ZombieMoveAttack.cpp -DDEMO
```

## User Manual

- Default Game Settings
    - Board Row : 5 (The default row settings when the game was loaded)
    - Board Columns : 9 (The default columns setting when the game was loaded)
    - Zombie Count : 1 (The default zombie number that would be spawned in the game)
    All settings mentioned above could be changed according to the player's input

- GameBoard
    - Title of the game displayed on top.
    - Board Row & Columns : According to the inputs given by player, if not default settings are used.
    - Game Characters : Alien, Zombie (depend on the no. set by users, default is 1)
    - Characters Attributes: Alien (Life & Attack), Zombie (Life, Attack, Range)

- Game Command
    - A list of commands that the users can use during the gameplay

- Game Object
    - Health(h) = Adds 20 life to Alien (if Alien's full health, would not be added)
    - Pod(p) = Impose 10 damage to Zombie when hit by Alien
    - Rock(r) = Hides a game object (health or pod) beneath it, reveal the hidden object when hit by Alien, Alien will stop next to it
    - Empty(blank space) = Just an empty space on the board.
    - Trail = Left by the Alien, will be reset to a randowm game object(except trail) when the Alien's turn ends

- Game Controls
    - up = Alien moves up
    - down = Alien moves down
    - left = Alien moves left
    - arrow = Switch the direction of an arrow object in the game board (The player will be asked to enter the row and column of the arrow object
    to switch, followed by the direction of the arrow object to switch to)
    - help = A list of the game commands and the description respectively that the player can use during the gameplay
    - save = save the current game to a file (player will be prompted to enter a name of the file to save to)
    - load = load a saved game file (player will be prompted to enter the file name to load from)
    - quit = quit the game while still in play (player will be asked to confirm his/her decision)
 
## Progress Log

- [Part 1](PART1.md)
- [Part 2](PART2.md)

## Contributors

Please replace the following with your group members' names. 

- CHUA KAI ZHENG
- LEE JIA MENG


