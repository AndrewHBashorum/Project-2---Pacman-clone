#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Ghost
{
	int row; // row pos of green ghost
	int col; // col pos of green ghost
	int moveCounter; // move counter only allows ghost to move and x amount of frames
	sf::Texture texture; // green ghost texture
	sf::Sprite sprite; // player sprite

public:
	Ghost(); // default constructor
	void draw(sf::RenderWindow &t_window); // passed from game draw. this draws the green ghost
	void moveUp(int t_new); // moves green ghost up / called from game
	void moveDown(int t_new); // moves green ghost down
	void moveLeft(int t_new);// moves green ghost left
	void moveRight(int t_new);// moves green ghost right
	void setCounter(int t_counter); // sets move counter
	void mazeToXY(); // sets row and col pos to xy pos
	void loadImage(); // loads image of green ghost
	int getRow(); // returns row pos of ghost
	int getCol(); // returns col pos of ghost
	void setRow(int t_row);
	void setCol(int t_col);
	
};
