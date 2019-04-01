#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class GhostRandom
{
	int row; // row pos of yellow ghost
	int col; // col pos of yellow ghost
	int moveCounter; // when 0  can move
	sf::Texture texture;
	sf::Sprite sprite; // player sprite


public:
	GhostRandom(); // default constructor
	void draw(sf::RenderWindow &t_window); // draws yellow ghost
	void moveUp(int t_new); // moves up ghost with passed new movecounter to speed up as the game goes on
	void moveDown(int t_new); // moves ghost down
	void moveLeft(int t_new); // moves ghost left
	void moveRight(int t_new); // moves ghoat right
	void resetCounter(int t_counter); // sets move counter
	void mazeToXY(); // sets row and col pos to x y pos of yellow ghost
	void loadImage(); // loads content of yellow ghost
	int getRow(); // returns row pos of ghost
	int getCol(); // returns col pos of ghsot
	void setRow(int t_row);
	void setCol(int t_col);
};
