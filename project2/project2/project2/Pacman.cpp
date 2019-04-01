// Pacman function definitions here

#include "Pacman.h"
#include "Globals.h"
Pacman::Pacman()
{
	loadImage();
	health = 1;
	score = 0;
	float xPos = 224;
	float yPos = 224;
	row = 7;
	col = 7;
	counter = 85;
	setPosition(xPos, yPos);
	sprite.setTextureRect(sf::IntRect(0, 244, 32, 423 / 12)); // sets pacman to left facing texture
}

void Pacman::reset() // resets pacmans data for new game
{
	health = 1;
	score = 0;
	float xPos = 224;
	float yPos = 224;
	row = 7;
	col = 7;
	counter = 85;
	setPosition(xPos, yPos);
	sprite.setTextureRect(sf::IntRect(0, 244, 32, 423 / 12)); // sets pacman to left facing texture
}


int Pacman::getHealth() // returns health of pacman
{
	return health;
}


void Pacman::setHealth(int t_health) // sets health of pacman
{
	health = t_health;
}

int Pacman::getScore() // retunrs score of pacman / used in game to check game over
{
	return score;
}

void Pacman::setScore(int t_score)
{
	score = t_score;
}

sf::Sprite Pacman::getBody() // returns sprite
{
	return sprite;
}

void Pacman::loadImage()
{
	if (!texture.loadFromFile("ASSETS/IMAGES/pacman.png")) // Loads tecture for player 
	{
		std::cout << "error with pacman texture file";
	}
}

void Pacman::portal() // allows player to go through protals on top and bottom of the screen and appear on the other side
{
	if (row == 0)
	{
		if (col == 5 || col == 6)
		{
			row = 10;
		}
	}

	if (row == 11)
	{
		if (col == 5 || col == 6)
		{
			row = 1;
		}
	}
}


void Pacman::draw(sf::RenderWindow &t_window)
{
	sprite.setTexture(texture);
	//sprite.setTextureRect(sf::IntRect(0, 64, 32, 423 / 12));

	t_window.draw(sprite);
}

int Pacman::getRow() // retunrs row pos
{
	return row;
}

int Pacman::getCol() // returns col pos
{
	return col;
}



void Pacman::moveLeft(int t_counter) // moves pacman left and changes texture so it looks like he is opening his mouth
{
	if (col > 1) // inside moundary
	{
		col--;
	}
	// counter is used to change the texture of pacmans mouth every move
	if (t_counter == 1)
	{
		sprite.setTextureRect(sf::IntRect(0, 244, 32, 423 / 12)); // half open
	}

	if (t_counter == 2)
	{
		sprite.setTextureRect(sf::IntRect(0, 212, 32, 423 / 12)); //closed
	}

	if (t_counter == 3)
	{
		sprite.setTextureRect(sf::IntRect(0, 276, 32, 423 / 12)); // full open
	}
}

void Pacman::moveRight(int t_counter) // moves player right inside boundary of screen  // moves pacman right and changes texture so it looks like he is opening his mouth
{
	if (col < MAX_COLS - 2) // inside boundary
	{
		col++;
	}
	// counter is used to change the texture of pacmans mouth every move
	if (t_counter == 3)
	{
		sprite.setTextureRect(sf::IntRect(0, 32, 32, 423 / 12));  // mouth half open
	}
	
	if (t_counter == 2)
	{
		sprite.setTextureRect(sf::IntRect(0, 0, 32, 423 / 12)); // mouth open
	}

	if (t_counter == 1)
	{
		sprite.setTextureRect(sf::IntRect(0, 64, 32, 423 / 12)); // mouth closed
	}
}

void Pacman::moveUp(int t_counter)  // moves player up inside boundary of screen  // moves pacman left and changes texture so it looks like he is opening his mouth
{

	row--;
	// counter is used to change the texture of pacmans mouth every move
	if (t_counter == 2)
	{
		sprite.setTextureRect(sf::IntRect(0, 384, 32, 423 / 12));  // mouth half open
	}

	if (t_counter == 1)
	{
		sprite.setTextureRect(sf::IntRect(0, 352, 32, 423 / 12)); // mouth open
	}

	if (t_counter == 3)
	{
		sprite.setTextureRect(sf::IntRect(0, 320, 32, 423 / 12));  // mouth closed
	}
}

void Pacman::moveDown(int t_counter)  // moves player down inside boundary of screen
{

	row++;
	// counter is used to change the texture of pacmans mouth every move
	if (t_counter == 1)
	{
		sprite.setTextureRect(sf::IntRect(0, 140, 32, 423 / 12)); // mouth half open
	}

	if (t_counter == 2)
	{
		sprite.setTextureRect(sf::IntRect(0, 108, 32, 423 / 12));  // mouth open
	}

	if (t_counter == 3)
	{
		sprite.setTextureRect(sf::IntRect(0, 172, 32, 423 / 12));  // mouth closed
	}
	 // sets pacman to left facing texture
}

void Pacman::setPosition(float t_xPos, float t_yPos) // set pos of player
{
	sprite.setPosition(t_xPos, t_yPos);
}

void Pacman::increaseScore() // increase score
{
	score = score + 1;
}

void Pacman::increaseHealth() // increase score
{
	health = health + 1;
}

void Pacman::collision() // if player coliides with ghost
{
	if (counter <= 0) // so it only reducing health once every 2 or so seconds
	{
		health = health - 1;
		counter = 40;
	}
}

void Pacman::mazeToXY() // sets row pos to xy ppos
{
	int xPos = col * 32; // 32 pixils in each image
	int yPos = row * 32;
	counter--; // decrements counter to move player and for player ability to lose health
	sprite.setPosition(xPos, yPos); // sets row pos to xy ppos
}
