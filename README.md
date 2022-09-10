## PathFinderCpp
Intro: Visual Studio C++ Project, Its 2D grid (GUI) based Project which detect shortest path between two points by Popular Algorithms (Dijkstra &amp; A*).


### Description:- 
Navigate into the extracted PathFinderCpp directory. Assuming that you have Microsoft Visual Studio 2019 installed, 
double click on the file PathFinderCpp.sln to open the project solution. The project creates a 40x40 2D grid-based map, with 2 objects. 
The red circle represents the target (or player), and can be moved using the cursor keys. The green objects is an AI “bot”. 

### Project Structure:- 
Quit the Pathfinder programme (press Escape), and examine the project code files. You should locate the following files in the “Solution Explorer” pane,
in the Visual Studio IDE. There are other files also included, but these are the ones you should pay particular attention to: 
 - game.h
 - level.h
 - dynamic.h
 - botbase.h
 - bots.h 
 - main.cpp
 - level.cpp
 - dynamic.cpp
 - botRandom.cpp 
 
If you use Windows File Explorer to look in the root folder (PathFinderCPP) for the solution, you should also see the following graphics files: 
tile.bmp tile-blocked.bmp tile-closed.bmp tile-route.bmp target.bmp bot.bmp & few text files for level/2D grid.

### Main Features of the Code 
#### main.cpp:
`defines the main function which is the entry point of the programme: it first performs some initialisation (loading graphics, creating main game objects), and then runs the main loop of the programme which updates the animation and movement of the bots and player. The main loop is enclosed in the ‘while’ loop defined on line 90.`

#### level.h and level.cpp:
`These contains the code for the cLevel class, which loads the txt file map and turns it into a 2D grid representing the level.`

#### dynamic.h and dynamic.cpp:
`These contains the code for the cDynamic class, which animates the player and bot classes. All moving objects inherit from this class. When you set a new grid position for a dynamic object using the SetNext() function, the dynamic object moves smoothly from its current location to the new location. This takes half a second, and the animation is controlled by its Update() function.`

#### botbase.h:
`This defines the class cBotBase, which is a base class for other AI bot classes. As a base class, you cannot create an object of this type directly. It inherits from the class cDynamic, because bots are dynamic objects. 
The key part of this class is the virtual function ChooseNextGridPosition(). This function is called automatically when the bot arrives at a new grid location (i.e. when it has finished animating from one grid location to another), and the code in this function should decide which location to move to next. Because this is called automatically, bots are always moving.`

#### bots.h and botRandom.cpp:
`bot.h contains a definition for the class cBotRandom, which is a simple example bot class. An object of this class is instantiated in the main function, and you can see it wondering around randomly(for empty level file) when you run the provided code.` 

