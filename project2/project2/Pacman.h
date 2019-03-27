#pragma once
// Player class declaration
#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Pacman
{
	// private data members
	int health; // health of pacman
	int score; // score of pacmamn
	int row; // row / y position of pacman
	int col; // col / x pos of pacman
	sf::Texture texture; // textures for four diffrent player directions
	sf::Sprite sprite; // player sprite
	int counter; // when pacman can next move
public:
	Pacman(); // default constructor
	int getHealth(); // return health
	void setHealth(int t_health); // sets health
	int getScore();  // returns score
	void setScore(int t_score); // sets score
	void increaseHealth(); // increase health of pacman
	sf::Sprite getBody(); // returns player sprtie
	void loadImage(); // loads pacman content
	void draw(sf::RenderWindow &t_window); // draws pacman

	int getRow(); // returns row pos of pacman
	int getCol(); // returns col pos of pacman
	void moveLeft(int t_counter); // moves pacman left / called from game with passed counter to change speed
	void moveRight(int t_counter); // moves pacman right
	void moveUp(int t_counter); // moves north
	void moveDown(int t_counter); // moves south

	void setPosition(float t_xPos, float t_yPos); // sets pos of pacman
	void increaseScore(); // increase score by 1 when called
	void collision(); // called in game when collision between ghost and pacman is detected / only lose health once a second = counter
	void mazeToXY(); // sets row amd col pos to xy pos
	void reset(); // resets game for new game

};