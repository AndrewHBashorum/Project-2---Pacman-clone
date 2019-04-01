// Ghost function definitions here

#include "ghostRandom.h"

GhostRandom::GhostRandom()
{
	loadImage(); // loads content for ghost 
	row = 5; // init row col
	col = 5;
	moveCounter = 80; // init move counter dertermines how fast the yellow ghost can move
	sprite.setTextureRect(sf::IntRect(0, 32, 32, 128 / 4));
}

void GhostRandom::draw(sf::RenderWindow & t_window)
{
	sprite.setTexture(texture); // sets init texture
	t_window.draw(sprite); // draws sprite
}


void GhostRandom::resetCounter(int t_counter)
{
	moveCounter = t_counter; // sets move counter to inputed value
}

void GhostRandom::moveUp(int t_new) // moves ghost up
{
	sprite.setTextureRect(sf::IntRect(0, 96, 32, 128 / 4)); // sets texture to looking up

	if (moveCounter < 10) // 
	{
		row--; // move up
		resetCounter(t_new); // sets counter to inputed from game
	}

}

void GhostRandom::moveDown(int t_new)
{
	sprite.setTextureRect(sf::IntRect(0, 64, 32, 128 / 4)); // sets texture to looking down

	if (moveCounter < 10)
	{
		row++; // move down
		resetCounter(t_new);  // sets counter to inputed from game
	}
}

void GhostRandom::moveLeft(int t_new)
{
	sprite.setTextureRect(sf::IntRect(0, 32, 32, 128 / 4)); // sets texture to looking left

	if (moveCounter < 10)
	{
		col--; // move left
		resetCounter(t_new); // sets texture to lookin
	}
}

void GhostRandom::moveRight(int t_new)
{
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 128 / 4)); // sets texture to lookin right
	if (moveCounter < 10)
	{
		col++;
		resetCounter(t_new);
	} // sets texture to lookin
}

void GhostRandom::loadImage()
{
	if (!texture.loadFromFile("ASSETS/IMAGES/yellowghost32.png")) // Loads tecture for player moving north
	{
		std::cout << "error with GREEN GHOST texture file";
	}
}


void GhostRandom::mazeToXY() // sets row and col pos to actual x y pos
{

	int xPos = col * 32;  //  32 pixils in each image / cell
	int yPos = row * 32;
	moveCounter--;
	sprite.setPosition(xPos, yPos);
}


int GhostRandom::getRow() // returns row pos of ghost
{
	return row;
}

int GhostRandom::getCol() // returns col pos of ghost
{
	return col;
}

void GhostRandom::setRow(int t_row) // sets new row pos of pacman
{
	row = t_row;
}

void GhostRandom::setCol(int t_col) // sets new col pos of ghost
{
	col = t_col;
}
