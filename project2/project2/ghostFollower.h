#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class GhostFollow
{
	int row; // row pos
	int col; // col pos
	int moveCounter; // time til they can move again
	sf::Texture texture;
	sf::Sprite sprite; // player sprite


public:
	GhostFollow(); // default constructor
	void draw(sf::RenderWindow &t_window);
	void moveUp(int t_new); // move functions 
	void moveDown(int t_new);
	void moveLeft(int t_new);
	void moveRight(int t_new);
	void resetCounter(int t_counter); // sets movecounter from input in game
	void mazeToXY(); // sets row and col pos to actual x y pos
	void loadImage(); // loads content of ghostfollower
	void setMoveCounter(int t_new);
	int getRow(); // return row / col
	int getCol(); // retunrs col pos of ghost
	void setRow(int t_row);
	void setCol(int t_col);
};
