#pragma once
#include "SFML/Graphics.hpp" 
#include "Globals.h"

class Cell
{
	// private data members

	sf::Texture emptyTexture; // textures for maze 
	sf::Texture pelletTexture; // texture of pellet / get score
	sf::Texture circleTexture; // texture for circile wall
	sf::Texture pillTexture; // texture for biggir pellts / health
	sf::Texture bottomLeftTexture;  // texture for bottom left corner piece
	sf::Texture bottomRightTexture; // texture for bottom right corner piece
	sf::Texture topRightTexture; // texture for top right corner piece
	sf::Texture topLeftTexture; // texture for top left corner piece
	sf::Texture rightWallTexture; // texture for right end wall piece
	sf::Texture leftWallTexture; // texture for bottom left corner piece
	sf::Texture topWallTexture; // texture for bottom left corner piece
	sf::Texture wallTexture; // texture for bottom left corner piece
	sf::Texture bottomWallTexture; // texture for bottom left corner piece
	sf::Texture VerticalWallTexture; // texture for bottom left corner piece
	

	sf::Texture fruit; // the big circle
	sf::Sprite sprite; // sprtie
public:
	
	Cell(); // defualt constructor
	int typeOFCell; // controls the texture that is used in a cell
	sf::Sprite getBody(); //retuns sprite
	void draw(sf::RenderWindow &t_window); // draws maze passing the window from game
	void loadImage(); 
	void setPosition(int t_xpos,int t_ypos); // sets positon of cells
	void setCellToEmpty(); // sets cell texture to empty texture. used when player eats pellet
	void setCellToPellet(); // sets cell to pellet cell
	void setCellToFruit(); // sets cell to fruit cell
	void setTypeOFCell(int t_newCell); // sets type of cell 
	void setUpTexture(); // sets up textures of type of cell
};