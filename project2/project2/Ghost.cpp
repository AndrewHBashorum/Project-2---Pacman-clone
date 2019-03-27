// Ghost function definitions here

#include "Ghost.h"

Ghost::Ghost()
{
	loadImage();
	row = 5;
	col = 5;
	moveCounter = 80;
	sprite.setTextureRect(sf::IntRect(0, 32, 32, 128 / 4));
}

void Ghost::draw(sf::RenderWindow & t_window) // draws ghost passed from game
{
	sprite.setTexture(texture);
	t_window.draw(sprite);
}


void Ghost::setCounter(int t_counter) // reset move counter
{
	moveCounter = t_counter;
}



void Ghost::moveUp(int t_new) // moves ghost up
{
	sprite.setTextureRect(sf::IntRect(0, 96, 32, 128 / 4)); // sets texture to looking up

	if (moveCounter < 10) // 
	{
		row--; // move up
		setCounter(t_new); // sets counter to inputed from game
	}
	
}

void Ghost::moveDown(int t_new)
{
	sprite.setTextureRect(sf::IntRect(0, 64,32, 128 / 4)); // sets texture to looking down

	if (moveCounter < 10)
	{
		row++; // move down
		setCounter(t_new);  // sets counter to inputed from game
	}
}

void Ghost::moveLeft(int t_new)
{
	sprite.setTextureRect(sf::IntRect(0, 32, 32, 128 / 4)); // sets texture to looking left

	if (moveCounter < 10)
	{
		col--; // move left
		setCounter(t_new); // sets texture to lookin
	}
}

void Ghost::moveRight(int t_new)
{
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 128 / 4)); // sets texture to lookin right
	if (moveCounter < 10)
	{
		col++;
		setCounter(t_new);
	} // sets texture to lookin
}


void Ghost::loadImage()
{
	if (!texture.loadFromFile("ASSETS/IMAGES/greenghost32.png")) // Loads tecture for player moving north
	{
		std::cout << "error with GREEN GHOST texture file";
	}
}


void Ghost::mazeToXY() // sets row amd col position to actual position on screen
{
	int xPos = col * 32; // 32 pixils in each sprite
	int yPos = row * 32;
	moveCounter--; // next time they can move when this is zero
	sprite.setPosition(xPos, yPos);
}


int Ghost::getRow() // returns row pos of ghost
{
	return row;
}

int Ghost::getCol() // returns col pos of ghost
{
	return col;
}

void Ghost::setRow(int t_row)
{
	row = t_row;
}

void Ghost::setCol(int t_col)
{
	col = t_col;
}
