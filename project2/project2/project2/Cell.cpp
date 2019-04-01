#include "Cell.h"
#include <iostream>
Cell::Cell()
{
	typeOFCell = 0; // init cellytpe to 0
	loadImage();
}


sf::Sprite Cell::getBody() // returns sprite
{
	return sprite;
}

void Cell::draw(sf::RenderWindow &t_window) 
{
	t_window.draw(sprite);
	
}

void Cell::loadImage() // loads all content
{
	if (!emptyTexture.loadFromFile("ASSETS/IMAGES/emptyCell.png")) // Loads tecture for emty cell
	{
		std::cout << "error with empty texture file";
	}

	if (!circleTexture.loadFromFile("ASSETS/IMAGES/wallCell.jpg")) // Loads tecture for wall cell
	{
		std::cout << "error with player north player file";
	}

	if (!pelletTexture.loadFromFile("ASSETS/IMAGES/smallpill.png"))
	{
		std::cout << "error with pellet cell";
	}

	if (!pillTexture.loadFromFile("ASSETS/IMAGES/bigpill.png"))
	{
		std::cout << "error with pellet cell";
	}

	if (!bottomLeftTexture.loadFromFile("ASSETS/IMAGES/BottomLeft.jpg")) 
	{
		std::cout << "error with bottom left";
	}

	if (!bottomRightTexture.loadFromFile("ASSETS/IMAGES/BottomRight.jpg"))
	{
		std::cout << "error with bottom right";
	}

	if (!topLeftTexture.loadFromFile("ASSETS/IMAGES/TopLeft.jpg"))
	{
		std::cout << "error with top left";
	}

	if (!topRightTexture.loadFromFile("ASSETS/IMAGES/wall6.jpg"))
	{
		std::cout << "error with top right";
	}

	if (!wallTexture.loadFromFile("ASSETS/IMAGES/wall3.jpg"))  
	{
		std::cout << "error with wall3";
	}

	if (!rightWallTexture.loadFromFile("ASSETS/IMAGES/RightWallEnd.jpg")) // Loads tecture for player moving north
	{
		std::cout << "error with bottom right";
	}

	if (!topWallTexture.loadFromFile("ASSETS/IMAGES/TopWallEnd.jpg"))
	{
		std::cout << "error with top wall end";
	}

	if (!bottomWallTexture.loadFromFile("ASSETS/IMAGES/bottomWallEnd.jpg"))
	{
		std::cout << "error with bottom wall end";
	}

	if (!VerticalWallTexture.loadFromFile("ASSETS/IMAGES/VerticalWall.jpg"))
	{
		std::cout << "error with bottom wall end";
	}

	if (!leftWallTexture.loadFromFile("ASSETS/IMAGES/wall2.jpg"))
	{
		std::cout << "error with bottom wall end";
	}


}

void Cell::setPosition(int t_xpos, int t_ypos) 
{
	sprite.setPosition(t_xpos, t_ypos);
}

void Cell::setCellToEmpty() // sets texture to empty
{
	sprite.setTexture(emptyTexture);
}

void Cell::setCellToPellet() // sets texture to pellet
{
	sprite.setTexture(pelletTexture);
}

void Cell::setCellToFruit() // sets texture to fruit
{
	sprite.setTexture(pillTexture);
}

void Cell::setTypeOFCell(int t_newCell) // sets type of cell
{
	 typeOFCell = t_newCell;
}

void Cell::setUpTexture() // sets up textures at the start of the game for each cell called in game after setup maze
{
	if (typeOFCell == 0)  // checks type of cell and sets textures to each cell
	{
		sprite.setTexture(emptyTexture);
	}

	if (typeOFCell == 1)  // checks type of cell and sets textures to each cell
	{
		sprite.setTexture(pelletTexture);
	}

	if (typeOFCell == 3)  // checks type of cell and sets textures to each cell
	{
		sprite.setTexture(pillTexture);
	}

	if (typeOFCell == 4)  // checks type of cell and sets textures to each cell
	{
		sprite.setTexture(bottomLeftTexture);
	}

	if (typeOFCell == 5)  // checks type of cell and sets textures to each cell
	{
		sprite.setTexture(bottomRightTexture);
	}

	if (typeOFCell == 6)  // checks type of cell and sets textures to each cell
	{
		sprite.setTexture(topLeftTexture);
	}

	if (typeOFCell == 7)  // checks type of cell and sets textures to each cell
	{
		sprite.setTexture(topRightTexture);
	}

	if (typeOFCell == 8)  // checks type of cell and sets textures to each cell
	{
		sprite.setTexture(rightWallTexture);
	}

	if (typeOFCell == 13)  // checks type of cell and sets textures to each cell
	{
		sprite.setTexture(leftWallTexture);
	}


	if (typeOFCell == 9)  // checks type of cell and sets textures to each cell
	{
		sprite.setTexture(topWallTexture);
	}

	if (typeOFCell == 10)  // checks type of cell and sets textures to each cell
	{
		sprite.setTexture(bottomWallTexture);
	}

	if (typeOFCell == 11)  // checks type of cell and sets textures to each cell
	{
		sprite.setTexture(wallTexture);
	}

	if (typeOFCell == 12)  // checks type of cell and sets textures to each cell
	{
		sprite.setTexture(VerticalWallTexture);
	}

}
