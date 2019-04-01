// Ghost function definitions here

#include "ghostFollower.h"

GhostFollow::GhostFollow()
{
	loadImage();
	row = 5; // init row pos
	col = 5; // init col pos
	moveCounter = 70; // innit move counter
	sprite.setTextureRect(sf::IntRect(0, 32, 32, 128 / 4)); 
}

void GhostFollow::draw(sf::RenderWindow & t_window)
{
	sprite.setTexture(texture);
	t_window.draw(sprite);
}


void GhostFollow::resetCounter(int t_counter)
{
	moveCounter = t_counter;
}

void GhostFollow::setMoveCounter(int t_new)
{
	moveCounter = t_new;
}

void GhostFollow::moveDown(int t_new) // moves player south
{
	sprite.setTextureRect(sf::IntRect(0, 64, 32, 128 / 4)); // south facing texture

	if (moveCounter < 10)
	{
		row++; // move down
		resetCounter(t_new); // set move counter to whatever is inputed in game
	}
}

void GhostFollow::moveUp(int t_new)  // moves player north
{
	sprite.setTextureRect(sf::IntRect(0, 96, 32, 128 / 4)); // player facing north

	if (moveCounter < 10)
	{
		row--; // move up
		resetCounter(t_new);
	}

}

void GhostFollow::moveLeft(int t_new)  // moves player west
{
	sprite.setTextureRect(sf::IntRect(0, 32, 32, 128 / 4)); // west facing texture

	if (moveCounter < 10)
	{
		col--; // move left
		resetCounter(t_new);
	}
}

void GhostFollow::moveRight(int t_new)
{
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 128 / 4)); // east facing texture
	if (moveCounter < 10)
	{
		col++; // move right
		resetCounter(t_new);
	}
}

void GhostFollow::loadImage()
{
	if (!texture.loadFromFile("ASSETS/IMAGES/redghost32.png")) // Loads tecture for player moving north
	{
		std::cout << "error with  greenghost32Copy.png tt GHOST texture file";
	}

}


void GhostFollow::mazeToXY() // sets row and col pos to actual  xy pos
{

	int xPos = col * 32; // 32 pixils in each cell
	int yPos = row * 32;
	moveCounter--; // when 0 ghost can move
	sprite.setPosition(xPos, yPos);
}


int GhostFollow::getRow()
{
	return row;
}

int GhostFollow::getCol()
{
	return col;
}

void GhostFollow::setRow(int t_row)
{
	row = t_row;
}

void GhostFollow::setCol(int t_col)
{
	col = t_col;
}
