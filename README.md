# PathFinderCpp
Intro: Visual Studio C++ Project, Its 2D grid (GUI) based Project which detect shortest path between two points by Popular Algorithms (Dijkstra &amp; A*).


Description:- 
Navigate into the extracted PathFinderCpp directory. Assuming that you have Microsoft Visual Studio 2019 installed, 
double click on the file PathFinderCpp.sln to open the project solution. The project creates a 40x40 2D grid-based map, with 2 objects. 
The red circle represents the target (or player), and can be moved using the cursor keys. The green objects is an AI “bot”. 

Project Structure:- 
Quit the Pathfinder programme (press Escape), and examine the project code files. You should locate the following files in the “Solution Explorer” pane,
in the Visual Studio IDE. There are other files also included, but these are the ones you should pay particular attention to: 
  game.h
  level.h
  dynamic.h
  botbase.h
  bots.h 
  main.cpp
  level.cpp
  dynamic.cpp
  botRandom.cpp 
If you use Windows File Explorer to look in the root folder (PathFinderCPP) for the solution, you should also see the following graphics files: 
tile.bmp tile-blocked.bmp tile-closed.bmp tile-route.bmp target.bmp bot.bmp
