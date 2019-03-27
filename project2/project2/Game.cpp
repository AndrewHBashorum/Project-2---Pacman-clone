// Name: 
// Login: 
// Date: 
// Approximate time taken: 
//---------------------------------------------------------------------------
// Project 2 -  Description Template
// ---------------------------------------------------------------------------
// Known Bugs:
// List your bugs here

//////////////////////////////////////////////////////////// 
// Headers for SFML projects
// include correct library file for release and debug versions
// include iostream for console window output
// include 
//////////////////////////////////////////////////////////// 

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include "Game.h"   // include Game header file
#include "Cell.h"
#include <ctime>

int main()
{
	Game aGame;
	aGame.LoadContent();
	aGame.run();

	return 0;
}

Game::Game() : window(sf::VideoMode(400, 400), "Project 2")
// Default constructor
{
	setUpGame();
	gameMode = INSTRUCTIONS;
}


void Game::LoadContent()
// Load the font file & set up message
{
	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file";
	}
	
	// set up the message string 
	m_message.setFont(m_font);  // set the font for the text
	m_message.setCharacterSize(24); // set the text size
	m_message.setFillColor(sf::Color::White); // set the text colour
	m_message.setPosition(10, 10);  // its position on the screen

	m_instructionMessage.setFont(m_font);  // set the font for the text
	m_instructionMessage.setCharacterSize(18); // set the text size
	m_instructionMessage.setFillColor(sf::Color::White); // set the text colour
	m_instructionMessage.setPosition(10, 100);  // its position on the screen

	healthMessage.setFont(m_font);  // set the font for the text
	healthMessage.setCharacterSize(24); // set the text size
	healthMessage.setFillColor(sf::Color::White); // set the text colour
	healthMessage.setPosition(10, 65);  // its position on the 

	redDeath.setFillColor(sf::Color::Red); // set the text colour
	redDeath.setPosition(0, 125);  // its position on the 
	redDeath.setSize(rectangleSize);

	nameMessage.setFont(m_font);  // set the font for the text
	nameMessage.setCharacterSize(24); // set the text size
	nameMessage.setFillColor(sf::Color::White); // set the text colour
	nameMessage.setPosition(50, 170);  // its position on the screen

	nameDisplay.setFont(m_font);  // set the font for the text
	nameDisplay.setCharacterSize(24); // set the text size
	nameDisplay.setFillColor(sf::Color::White); // set the text colour
	nameDisplay.setPosition(10, 35);  // its position on the screen

	gameOverMan.setFont(m_font);  // set the font for the text
	gameOverMan.setCharacterSize(28); // set the text size
	gameOverMan.setFillColor(sf::Color::White); // set the text colour
	gameOverMan.setPosition(50, 150);  // its position on the screen

	setUpMaze();
}



void Game::pelletCheck() // code for collectables. gives player score for pelltets and health for big pellets / fruit
{
	for (int row = 0; row < MAX_ROWS; row++) // 2d nested for lopp checks every cell
	{
		for (int col = 0; col < MAX_COLS; col++)
		{
			if (maze[row][col].typeOFCell == 1) // if a pellet
			{
				if (player.getRow() == row && player.getCol() == col) // in same cell
				{
					player.increaseScore(); // gves player 1 score
					maze[row][col].typeOFCell = 0; // set to emty cell texture
					maze[row][col].setCellToEmpty(); // sets texture
				}
			}

			if (maze[row][col].typeOFCell == 3) // if a fruit
			{
				if (player.getRow() == row && player.getCol() == col) // in same cell
				{
					player.increaseHealth(); // 1 more life
					maze[row][col].typeOFCell = 0; // reset cell texture
					maze[row][col].setCellToEmpty(); // sets texture to emt
				}
			}
		}
	}
}


void Game::setUpMaze() // sets up 2d maze. sets cell type and displaces each cell into position
{
	maze[0][0].typeOFCell = 6; // first row
	maze[0][1].typeOFCell = 11;
	maze[0][2].typeOFCell = 11;
	maze[0][3].typeOFCell = 11;
	maze[0][4].typeOFCell = 11;
	maze[0][5].typeOFCell = 11;
	maze[0][6].typeOFCell = 11;
	maze[0][7].typeOFCell = 11;
	maze[0][8].typeOFCell = 11;
	maze[0][9].typeOFCell = 11;
	maze[0][10].typeOFCell = 11;
	maze[0][11].typeOFCell = 7;


	maze[1][0].typeOFCell = 12; // second row
	maze[1][1].typeOFCell = 3;
	maze[1][2].typeOFCell = 1;
	maze[1][3].typeOFCell = 1;
	maze[1][4].typeOFCell = 1;
	maze[1][5].typeOFCell = 0;
	maze[1][6].typeOFCell = 0;
	maze[1][7].typeOFCell = 1;
	maze[1][8].typeOFCell = 1;
	maze[1][9].typeOFCell = 1;
	maze[1][10].typeOFCell = 0;
	maze[1][11].typeOFCell = 12;


	maze[2][0].typeOFCell = 12; // third row
	maze[2][1].typeOFCell = 1;
	maze[2][2].typeOFCell = 6;
	maze[2][3].typeOFCell = 7;
	maze[2][4].typeOFCell = 1;
	maze[2][5].typeOFCell = 0;
	maze[2][6].typeOFCell = 0;
	maze[2][7].typeOFCell = 1;
	maze[2][8].typeOFCell = 6;
	maze[2][9].typeOFCell = 7;
	maze[2][10].typeOFCell = 1;
	maze[2][11].typeOFCell = 12;

	maze[3][0].typeOFCell = 12; // fourth row
	maze[3][1].typeOFCell = 1;
	maze[3][2].typeOFCell = 12;
	maze[3][3].typeOFCell = 12;
	maze[3][4].typeOFCell = 1;
	maze[3][5].typeOFCell = 6;
	maze[3][6].typeOFCell = 7;
	maze[3][7].typeOFCell = 1;
	maze[3][8].typeOFCell = 4;
	maze[3][9].typeOFCell = 5;
	maze[3][10].typeOFCell = 1;
	maze[3][11].typeOFCell = 12;


	maze[4][0].typeOFCell = 12; // fift row
	maze[4][1].typeOFCell = 1;
	maze[4][2].typeOFCell = 4;
	maze[4][3].typeOFCell = 5;
	maze[4][4].typeOFCell = 1;
	maze[4][5].typeOFCell = 4;
	maze[4][6].typeOFCell = 5;
	maze[4][7].typeOFCell = 1;
	maze[4][8].typeOFCell = 1;
	maze[4][9].typeOFCell = 0;
	maze[4][10].typeOFCell = 1;
	maze[4][11].typeOFCell = 12;


	maze[5][0].typeOFCell = 12; // 6th row
	maze[5][1].typeOFCell = 1;
	maze[5][2].typeOFCell = 1;
	maze[5][3].typeOFCell = 1;
	maze[5][4].typeOFCell = 1;
	maze[5][5].typeOFCell = 0;
	maze[5][6].typeOFCell = 0;
	maze[5][7].typeOFCell = 1;
	maze[5][8].typeOFCell = 1;
	maze[5][9].typeOFCell = 1;
	maze[5][10].typeOFCell = 1;
	maze[5][11].typeOFCell = 12;


	maze[6][0].typeOFCell = 12;  // 7th row
	maze[6][1].typeOFCell = 1;
	maze[6][2].typeOFCell = 13;
	maze[6][3].typeOFCell = 11;
	maze[6][4].typeOFCell = 8;
	maze[6][5].typeOFCell = 0;
	maze[6][6].typeOFCell = 0;
	maze[6][7].typeOFCell = 13;
	maze[6][8].typeOFCell = 11;
	maze[6][9].typeOFCell = 8;
	maze[6][10].typeOFCell = 1;
	maze[6][11].typeOFCell = 12;


	maze[7][0].typeOFCell = 12; //8th row
	maze[7][1].typeOFCell = 1;
	maze[7][2].typeOFCell = 1;
	maze[7][3].typeOFCell = 1;
	maze[7][4].typeOFCell = 1;
	maze[7][5].typeOFCell = 1; //
	maze[7][6].typeOFCell = 1; //
	maze[7][7].typeOFCell = 1;
	maze[7][8].typeOFCell = 1;
	maze[7][9].typeOFCell = 1;
	maze[7][10].typeOFCell = 1;
	maze[7][11].typeOFCell = 12;


	maze[8][0].typeOFCell = 12;  // 9th row
	maze[8][1].typeOFCell = 1;
	maze[8][2].typeOFCell = 6;
	maze[8][3].typeOFCell = 11;
	maze[8][4].typeOFCell = 7;
	maze[8][5].typeOFCell = 1; //
	maze[8][6].typeOFCell = 1;//
	maze[8][7].typeOFCell = 6;
	maze[8][8].typeOFCell = 11;
	maze[8][9].typeOFCell = 7;
	maze[8][10].typeOFCell = 1;
	maze[8][11].typeOFCell = 12;


	maze[9][0].typeOFCell = 12;  // 10th row
	maze[9][1].typeOFCell = 1;
	maze[9][2].typeOFCell = 4;
	maze[9][3].typeOFCell = 11;
	maze[9][4].typeOFCell = 5;
	maze[9][5].typeOFCell = 1; //
	maze[9][6].typeOFCell = 1;//
	maze[9][7].typeOFCell = 4;
	maze[9][8].typeOFCell = 11;
	maze[9][9].typeOFCell = 5;
	maze[9][10].typeOFCell = 1;
	maze[9][11].typeOFCell = 12;


	maze[10][0].typeOFCell = 12;  // 11th row
	maze[10][1].typeOFCell = 0;
	maze[10][2].typeOFCell = 1;
	maze[10][3].typeOFCell = 1;
	maze[10][4].typeOFCell = 1;
	maze[10][5].typeOFCell = 1; //
	maze[10][6].typeOFCell = 1;//
	maze[10][7].typeOFCell = 1;
	maze[10][8].typeOFCell = 1;
	maze[10][9].typeOFCell = 1;
	maze[10][10].typeOFCell = 3;
	maze[10][11].typeOFCell = 12;


	maze[11][0].typeOFCell = 4;  // 12th row
	maze[11][1].typeOFCell = 11;
	maze[11][2].typeOFCell = 11;
	maze[11][3].typeOFCell = 11;
	maze[11][4].typeOFCell = 11;
	maze[11][5].typeOFCell = 11;
	maze[11][6].typeOFCell = 11;
	maze[11][7].typeOFCell = 11;
	maze[11][8].typeOFCell = 11;
	maze[11][9].typeOFCell = 11;
	maze[11][10].typeOFCell = 11;
	maze[11][11].typeOFCell = 5;

	for (int row = 0; row < MAX_ROWS; row++)
	{
		float displacemantCol = row * 32;

		for (int col = 0; col < MAX_COLS; col++)
		{
			float displacemantRow = col * 32;
			maze[row][col].setPosition(displacemantRow, displacemantCol);
			maze[row][col].setUpTexture();
		}
	}


}


void Game::run()
{
	srand(time(nullptr)); // set the seed once
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// the clock object keeps the time.
	sf::Clock clock;


	clock.restart();

	while (window.isOpen())
	{
		// check if the close window button is clicked on
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (gameMode == GAME_PLAY)
			{
				userInput(event);
			}
			
			if (event.type == sf::Event::Closed)
				window.close();

			if (gameMode == USER_INPUT_SCREEN)
			{
				if (event.type == sf::Event::TextEntered)
				{
					bool backSpace = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::BackSpace);

					if (backSpace == true && name.length() != 0)
					{
						name.pop_back();
					}
					else if (event.text.unicode < 123 && event.text.unicode > 64)
					{
						if (event.text.unicode > 96 || event.text.unicode < 91)
						{
							name.push_back((char)event.text.unicode);
						}
					}
				}
			}
			
		}
	
		//get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.
		if (timeSinceLastUpdate > timePerFrame)
		{
			update();
			draw();

			// reset the timeSinceLastUpdate to 0 
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}  // end while loop

}



void Game::update()
// This function takes the keyboard input and updates the game world
{
	gameModeInput();
	if (gameMode == GAME_PLAY) // only when game is on
	{
		randomMove();
		scoreSpeedCounter();
		gameOver();
		collisions();
		pelletCheck();
		ghostTwoThree();
		player.mazeToXY();// update any game variables here ...
		ghostOneAroundMaze();
		ghost.mazeToXY();
		for (int i = 0; i < MAX_GHOSTS; i++)
		{
			ghosts[i].mazeToXY();
			ghostFollow[i].mazeToXY();
		}
	}	

	if (gameMode == INSTRUCTIONS)
	{
		ghostOneAroundMaze();
	}
}

bool Game::canMoveUp(int t_row, int t_col) // checks if an entity can move up
{
	int above = t_row - 1; // cell directly above
	
	if (maze[above][t_col].typeOFCell > 3) // if any cell being used as a wall
	{
		return false;
	}
	else
		return true;
}

bool Game::canMoveDown(int t_row, int t_col)  // checks if an entity can move down
{
	int below = t_row + 1; // checks cell directly below

	if (maze[below][t_col].typeOFCell > 3) // if any cell being used as a wall
	{
		return false;
	}
	else
		return true;
}

bool Game::canMoveLeft(int t_row, int t_col)  // checks if an entity can move left
{
	int leftOf = t_col - 1; // checks cell directly left

	if (maze[t_row][leftOf].typeOFCell > 3) // if any cell being used as a wall
	{
		return false;
	}
	else
		return true;
}

bool Game::canMoveRight(int t_row, int t_col)  // checks if an entity can move right
{
	int rightOf = t_col + 1; // cell directly right of body

	if (maze[t_row][rightOf].typeOFCell > 3) // if any cell being used as a wall
	{
		return false;
	}
	else
		return true;
}

void Game::gameModeInput()
{
	if (gameMode == INSTRUCTIONS) // when in instruction screen press space to go to user input screen
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			gameMode = USER_INPUT_SCREEN;
		}
	}
	if (gameMode == USER_INPUT_SCREEN)  // when in  user input screen screen press space to go to GAME_PLAY screen
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			gameMode = GAME_PLAY;
		}
	}

	if (gameMode == GAME_OVER)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))   // when in game over screen screen press r to go to GAME_PLAY screen
		{
			gameMode = GAME_PLAY;
			reseter();
		}
	}

}

void Game::reseter() // resets game 
{
	speedCounter = 80; // resets counter for ghosts
	followerSpeedCounter = 80;
	setUpMaze(); // sets up maze to level 1
	setUpGame(); //sets pos of sprites
	player.reset(); // resets pacmans data
}

void Game::gameOver() // death detecetion
{
	if (player.getHealth() <= 0) // if pacman has no health
	{
		gameMode = GAME_OVER; 

		if (player.getScore() > highScore) // checks if his score is new highscore
		{
			highScore = player.getScore();
		}
	}
}


void Game::draw()
// This function draws the game world
{
	// Clear the screen and draw your game sprites
	window.clear();

	if (gameMode == USER_INPUT_SCREEN) // draws user input screen
	{
		window.draw(redDeath);
		nameMessage.setString("Enter your name : " + name);
		window.draw(nameMessage);
	}

	if (gameMode == INSTRUCTIONS) // draws instruction screen
	{
		m_instructionMessage.setString("INSTRUCTIONS \n -Use arrow Keys up-Left-Down-Right to move. \n -Avoid Ghosts and collect pellets to gain score. \n -Red(bossman) Ghosts will follow you \n while green(marley bob) ghosts will move around the edge. \n and yellow(crazy eyes) will move randomly. \n -Collecting big pellets will give you an extra life. \n \n \n Press Space to continue  ");
		window.draw(m_instructionMessage);
	}


	if (gameMode == GAME_OVER)  // draws game over screen
	{
		std::string message = "Game over Press R to restart \n" + name + " 's HighScore: " + std::to_string(highScore);
		gameOverMan.setString(message);
		window.draw(redDeath);
		window.draw(gameOverMan);

		window.draw(m_message);  // write message to the screen
		window.draw(nameDisplay);
		window.draw(healthMessage);
	}


	if (gameMode == GAME_PLAY)  // draws game play screen
	{
		for (int row = 0; row < MAX_ROWS; row++)
		{
			for (int col = 0; col < MAX_COLS; col++)
			{
				maze[row][col].draw(window); // draws maze
			}
		}
		for (int i = 0; i < MAX_GHOSTS; i++)
		{
			ghosts[i].draw(window); // draws green ghosts
		}

		for (int i = 0; i < MAX_GHOSTS_FOLLOW; i++)
		{
			ghostFollow[i].draw(window); // draws red ghosts
		}
		ghost.draw(window);
		player.draw(window);
		nameDisplay.setString(name);
		m_message.setString("Score :" + std::to_string(player.getScore()));
		healthMessage.setString("Health :" + std::to_string(player.getHealth()));
		window.draw(m_message);  // write message to the screen
		window.draw(nameDisplay);
		window.draw(healthMessage);
	}


	
	window.display();
}


void Game::setUpGame()
// Initialize the game objects to play a new game
{
	ghosts[0].setRow(1); // sets intial pos of ghosts
	ghosts[0].setCol(1);

	ghosts[1].setRow(10);
	ghosts[1].setCol(10);

	ghostFollow[0].setRow(1);
	ghostFollow[0].setCol(10);

	ghostFollow[1].setRow(10);
	ghostFollow[1].setCol(1);

	ghost.setRow(5);
	ghost.setCol(5);

}

void Game::collisions()
{
	for (int i = 0; i < MAX_GHOSTS; i++)
	{
		if (player.getRow() == ghosts[i].getRow()) // same row
		{
			if (player.getCol() == ghosts[i].getCol()) // same col therfore same cell
			{
				player.collision(); // calls for collision function which decreases players lives
			}
		}

		if (player.getRow() == ghostFollow[i].getRow())
		{
			if (player.getCol() == ghostFollow[i].getCol())
			{
				player.collision(); // calls for collision function which decreases players lives
			}
		}
	}

	if (player.getRow() == ghost.getRow())
	{
		if (player.getCol() == ghost.getCol())
		{
			player.collision();  // calls for collision function which decreases players lives
		}
	}
	
}

void Game::randomMove()
{
	int random = rand() % 4 + 1; // SETS RANDOM NUMBER

	if (random == 1) 
	{
		if (canMoveLeft(ghost.getRow(), ghost.getCol()) == true) // checks if he can move left
		{
			ghost.moveLeft(RANDOM_COUNTER); // moves left
		}
		else
			random++;
		
	}

	if (random == 2)
	{
		if (canMoveUp(ghost.getRow(), ghost.getCol()) == true) // checks if he can move up
		{
			ghost.moveUp(RANDOM_COUNTER); // moves up
		}
		else
			random++;
	}

	if (random == 3)
	{
		if (canMoveRight(ghost.getRow(), ghost.getCol()) == true) // checks if he can move right 
		{
			ghost.moveRight(RANDOM_COUNTER); // moves right
		}
		else
			random++;
	}

	if (random == 4)
	{
		if (canMoveDown(ghost.getRow(), ghost.getCol()) == true) // checks if he can move down
		{
			ghost.moveDown(RANDOM_COUNTER); // moves down
		}
		else
			random = rand() % 4 + 1;
	}
}

void Game::userInput(sf::Event t_event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (canMoveLeft(player.getRow(), player.getCol()) == true) // checks if he can move left
		{
			if (counter < 3) // if counter isnt 4
			{
				counter++;
			}
			else // if counter is 4 set it back to 1
			{
				counter = 1; 
			}
			player.moveLeft(counter);
		}	 // calls player to move left
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (canMoveRight(player.getRow(), player.getCol()) == true)  // checks if he can move right
		{
			if (counter < 3) // if counter isnt 4
			{
				counter++;
			}
			else  // if counter is 4 set it back to 1
			{
				counter = 1;
			}

			player.moveRight(counter); // calls player to move
		}
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{

		if (canMoveUp(player.getRow(), player.getCol()) == true)
		{
			if (counter < 3)  // if counter isnt 4
			{
				counter++;
			}
			else  // if counter is 4 set it back to 1
			{
				counter = 1;
			}
			player.moveUp(counter);
		}
		
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (canMoveDown(player.getRow(), player.getCol()) == true)
		{
			if (counter < 3) // if counter isnt 4
			{
				counter++;
			}
			else  // if counter is 4 set it back to 1
			{
				counter = 1;
			}
			player.moveDown(counter);
		}
	
	}

}
void Game::ghostTwoThree()
{
	for (int i = 0; i < MAX_GHOSTS_FOLLOW; i++)
	{
		if (ghostFollow[i].getRow() < player.getRow()) // if player is above ghost
		{
			if (canMoveDown(ghostFollow[i].getRow(), ghostFollow[i].getCol()) == true) // if can move down
			{
				ghostFollow[i].moveDown(followerSpeedCounter); //moves ghost down
			}
			else if (canMoveLeft(ghostFollow[i].getRow(), ghostFollow[i].getCol()) == true) // cant go down go left
			{
				ghostFollow[i].moveLeft(followerSpeedCounter); // moves left
			}
		}

		if (ghostFollow[i].getRow() > player.getRow()) // if player is below  ghost
		{
			if (canMoveUp(ghostFollow[i].getRow(), ghostFollow[i].getCol()) == true) // if can move up
			{
				ghostFollow[i].moveUp(followerSpeedCounter); //moves ghost down
			}
			else if (canMoveRight(ghosts[i].getRow(), ghostFollow[i].getCol()) == true) // if can move right
			{
				ghostFollow[i].moveRight(followerSpeedCounter);  // moves right
			}
		}

		if (ghostFollow[i].getCol() > player.getCol()) // if player is right of ghost
		{
			if (canMoveLeft(ghostFollow[i].getRow(), ghostFollow[i].getCol()) == true)
			{
				ghostFollow[i].moveLeft(followerSpeedCounter); // move left
			}
			else if (canMoveDown(ghostFollow[i].getRow(), ghostFollow[i].getCol()) == true) // if cant move right move down
			{
				ghostFollow[i].moveDown(followerSpeedCounter); // move down
			}
		}

		if (ghostFollow[i].getCol() < player.getCol())  // if player is right of ghost
		{
			if (canMoveRight(ghostFollow[i].getRow(), ghostFollow[i].getCol()) == true) // if can move me right
			{
				ghostFollow[i].moveRight(followerSpeedCounter); // move right
			}
			else if (canMoveUp(ghostFollow[i].getRow(), ghostFollow[i].getCol()) == true) // if cant move right move up
			{
				ghostFollow[i].moveUp(followerSpeedCounter); // moves up
			}
		}
	}
	

}
void Game::scoreSpeedCounter() // scoring. increases speed of ghosts as score increases
{
	if (player.getScore() > 5)  // if score is over 5 increase speed
	{
		speedCounter = 70;
	}

	if (player.getScore() > 15)
	{
		speedCounter = 60;
	}

	if (player.getScore() > 20)
	{
		speedCounter = 50;
	}

	if (player.getScore() > 30)
	{
		speedCounter = 40;
	}

	if (player.getScore() > 40)
	{
		speedCounter = 25;
	}

	if (player.getScore() > 50)
	{
		speedCounter = 20;
	}

	if (player.getScore() == 55) // if score is 55 reset level
	{
		levelTwo();
	}

	if (player.getScore() > 65)
	{
		followerSpeedCounter = 70;
	}

	if (player.getScore() > 80)
	{
		followerSpeedCounter = 60;
	}

	if (player.getScore() > 90)
	{
		followerSpeedCounter = 50;
	}

	if (player.getScore() > 95)
	{
		followerSpeedCounter = 45;
	}

	if (player.getScore() > 105)
	{
		followerSpeedCounter = 35;
	}

	if (player.getScore() > 115)
	{
		followerSpeedCounter = 25;
	}

	if (player.getScore() == 114)
	{
		levelTwo();
	}

	if (player.getScore() == 165)
	{
		levelTwo();
	}

	if (player.getScore() == 200)
	{
		levelTwo();
	}

	if (player.getScore() == 250)
	{
		levelTwo();
		followerSpeedCounter = 13;
	}

	if (player.getScore() == 300)
	{
		levelTwo();
	}

	if (player.getScore() == 350)
	{
		levelTwo();
	}

	if (player.getScore() == 400)
	{
		levelTwo();
	}

	if (player.getScore() == 450)
	{
		levelTwo();
		followerSpeedCounter = 13;
	}

	if (player.getScore() == 500)
	{
		levelTwo();
	}

	if (player.getScore() == 550)
	{
		levelTwo();
	}

	if (player.getScore() == 600)
	{
		levelTwo();
	}

	if (player.getScore() == 650)
	{
		levelTwo();
	}

	if (player.getScore() == 700)
	{
		levelTwo();
		followerSpeedCounter = 13;
	}


	if (player.getScore() == 750)
	{
		levelTwo();
	}

	if (player.getScore() == 800)
	{
		levelTwo();
	}

	if (player.getScore() == 850)
	{
		levelTwo();
	}

	if (player.getScore() == 900)
	{
		levelTwo();
		followerSpeedCounter = 13;
	}


	if (player.getScore() == 950)
	{
		levelTwo();
	}

	if (player.getScore() > 1000)
	{
		levelTwo();
	}
}

void Game::levelTwo() // level 2
{
	for (int row = 0; row < MAX_ROWS; row++) // nested for loop to check every cell
	{
		for (int col = 0; col < MAX_COLS; col++)
		{
			if (maze[row][col].typeOFCell == 0) // if empty cell
			{
				maze[row][col].typeOFCell = 1; // sets emtpy cells to pellets
				maze[row][col].setCellToPellet();

				int random = (rand() % 20) + 1; //random number between 1-20

				if (random == 4)
				{
					maze[row][col].typeOFCell = 3; // 1 in 20 chance
					maze[row][col].setCellToPellet();
				}
			}

			
		}
	}
}
void Game::ghostOneAroundMaze() // moves that green ghost
{
	for (int i = 0; i < MAX_GHOSTS; i++)
	{
		if (ghosts[i].getRow() == 1 && ghosts[i].getCol() < 10) // if on top row 
		{
			ghosts[i].moveRight(speedCounter); // move right
		}

		if (ghosts[i].getCol() == 10 && ghosts[i].getRow() < 10) // on right most col
		{
			ghosts[i].moveDown(speedCounter); // move down
		}

		if (ghosts[i].getCol() > 1 && ghosts[i].getRow() == 10) // on bottom row
		{
			ghosts[i].moveLeft(speedCounter); // move left
		}

		if (ghosts[i].getCol() == 1 && ghosts[i].getRow() > 1) // if on left most column
		{
			ghosts[i].moveUp(speedCounter); // move up
		}
	}
	
}
