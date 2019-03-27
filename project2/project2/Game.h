// Game class declaration
#pragma once

#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function

#include "Cell.h"   // include Cell header file
#include "Pacman.h"   // include Pacman header file
#include "Ghost.h"   // include Ghost header file
#include "ghostFollower.h"
#include "ghostRandom.h"
class Game
{
	// private data members
	// put your game objects here eg 2D array and Pacman object and 1D array of ghosts objects etc.

	static const int MAX_ROWS = 12; // MAX NUMBER OF ROWS 
	static const int MAX_COLS = 12; // max number of columns
	static const int MAX_GHOSTS = 2; // max number of GHOSTS
	static const int MAX_GHOSTS_FOLLOW = 2; // max number of GHOSTS

	int active_ghosts = 4; // number of active ghosts in the maze
//	static const int CELL_SIZE; // size of each cell

	sf::RenderWindow window;
	sf::Vector2f rectangleSize = { 400,150 }; // width of rectangle
	sf::RectangleShape redDeath; // red 


	GhostRandom ghost; // 
	Pacman player;
	Ghost ghosts[MAX_GHOSTS];
	GhostFollow ghostFollow[MAX_GHOSTS_FOLLOW];
	Cell maze[MAX_ROWS][MAX_COLS];

	std::string name = "";

	int highScore = 0; // highscore 
	int speedCounter = 80; // speed of green ghost
	int followerSpeedCounter = 80; // speed of red ghost
	int counter = 0;
	int gameMode; // game mode its in

public:
	sf::Font m_font;  // font for writing text
	sf::Text m_message;  // text to write on the screen
	sf::Text healthMessage; // message which displays health pacman has
	sf::Text nameMessage;
	sf::Text nameDisplay;
	sf::Text gameOverMan;
	sf::Text m_instructionMessage;
public:	  // declaration of member functions	
	Game();  // default constructor
	void	LoadContent();
	void	run();      
	void	update(); 
	void	draw(); // DRAW 
	void	setUpGame(); // init game objects
	void    pelletCheck(); // checks for eaten pellet
	void	setUpMaze(); // sets up maze
	void    collisions(); // checks for collision 
	void    userInput(sf::Event t_event); // gets user input
	void    ghostOneAroundMaze(); // moves green ghost around the maze
	void    ghostTwoThree(); // moves red ghost to follow the plyer
	void    levelTwo(); // starts new level
	bool    canMoveUp(int t_row, int t_col); // checks if any inputed values can move around the maze
	bool    canMoveDown(int t_row, int t_col);
	bool    canMoveLeft(int t_row, int t_col);
	bool    canMoveRight(int t_row, int t_col);
	void    scoreSpeedCounter(); // checks level and score increasing difficulty as the game continues
	void    gameModeInput(); // changes game screeen 
	void    gameOver(); // game over 
	void    reseter(); // restarts game 
	void    randomMove(); // yellow moves randomly
};

