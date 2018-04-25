#include "GlobalVars.h"

//INITIALISES THE WINDOW//
bool XO::initialise()
{
	bool init = true;

	//CHECKS IF ALL SDL FILES ARE INITIALISED//
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		//PRINTS TO FILE - SDL CANNOT INIT//
		errorLog("SDL Could not be initialised, check if all SDL files are in correct folders");
		//GET SDL BUILT IN ERROR//
		SDL_GetError();
		init = false;
	}

	else
	{
		//CREATE A NEW WINDOW//
		window = SDL_CreateWindow(
			"XO",	//GAME WINDOW NAME//
			SDL_WINDOWPOS_CENTERED,	//WINDOW IS CENTERED IN X DIRECTION//
			SDL_WINDOWPOS_CENTERED,	//WINDOW IS CENTERED IN Y DIRECTION//
			winWidth,	//WINDOW WIDTH//
			winHeight,	//WINDOW HEIGHT//
			SDL_WINDOW_SHOWN	//THE WINDOW IS VISIBLE//
			);

		if (window == NULL)
		{
			//PRINTS TO FILE - WINDOW CANNOT INIT//
			errorLog("Window could not be created");
			//GET SDL BUILT IN ERROR//
			SDL_GetError();
			init = false;
		}
		else
		{
			//GET THE WINDOW SURFACE//
			screen = SDL_GetWindowSurface(window);

			//CALLS LOAD IMG FUNCTION//
			bool imgInit = loadImg();

			if (imgInit == false)
			{
				errorLog("Something went wrong while loading images");
			}

			//WRITES THE GAME BACKGROUND INTO THE SCREEN//
			SDL_BlitSurface(gameBackground, NULL, screen, NULL);

			//RECTANGLE USED TO DRAW MENU TO SCREEN//
			SDL_Rect Menu;
			Menu.x = 25;
			Menu.y = 350;
			Menu.w = 420;
			Menu.h = 140;

			//DRAWS THE MENU TO SCREEN//
			SDL_BlitSurface(MainMenu, NULL, screen, &Menu);

			//UPDATES THE WINDOW WITH THE BLITTED IMAGE//
			SDL_UpdateWindowSurface(window);
		}

	}
	return init;
}

void XO::gameLoop()
{
	SDL_Event gameInput;

	while (!quitPlay)
	{
		while (SDL_PollEvent(&gameInput))
		{
			//THIS HELPS DETERMINE WHOSE TURN IT IS//
			int turn;
			//CHECKS IF A KEY IS PRESSED//
			if (gameInput.type == SDL_KEYDOWN)
			{
				//LOOKS AT WHICH KEY WAS PRESSED BY THE USER//
				switch (gameInput.key.keysym.sym)
				{
				case SDLK_1:
					if (checkGridEmpty(0, 0) == true)
					{
						//NOTE: THERE'S A REASON THIS IS IN HERE//
						//IF THIS IS NOT CONTAINED WITHIN THE IFS, THEN THE GAME BREAKS SINCE THE PLAYER ENDS UP//
						//PRESSING THE BUTTON MULTIPLE TIMES AND END UP WRITING TO A GRID VALUE THAT HAS ALREADY//
						//BEEN CHOSEN BY A PLAYER//
						turn = whosTurn();
						grid[0][0] = turn;

						//AI ONLY REACTS IF THE USER INPUTS//
						if (playAI == true)
						{
							//LITTLE DELAY TO GIVE THE AI TIME TO READ THE GRID//
							SDL_Delay(100);							
							//THE AI'S TURN//
							whosTurn();
							//RUN THE AI//
							GameAI();
						}
					}
					break;

				case SDLK_2:
					if (checkGridEmpty(1, 0) == true)
					{
						turn = whosTurn();
						grid[1][0] = turn;

						//AI ONLY REACTS IF THE USER INPUTS//
						if (playAI == true)
						{
							//LITTLE DELAY TO GIVE THE AI TIME TO READ THE GRID//
							SDL_Delay(100);
							//THE AI'S TURN//
							whosTurn();
							//RUN THE AI//
							GameAI();
						}
					}
					break;

				case SDLK_3:
					if (checkGridEmpty(2, 0) == true)
					{
						turn = whosTurn();
						grid[2][0] = turn;

						//AI ONLY REACTS IF THE USER INPUTS//
						if (playAI == true)
						{
							//LITTLE DELAY TO GIVE THE AI TIME TO READ THE GRID//
							SDL_Delay(100);	
							//THE AI'S TURN//
							whosTurn();
							//RUN THE AI//
							GameAI();
						}
					}
					break;

				case SDLK_4:
					if (checkGridEmpty(0, 1) == true)
					{
						turn = whosTurn();
						grid[0][1] = turn;

						//AI ONLY REACTS IF THE USER INPUTS//
						if (playAI == true)
						{
							//LITTLE DELAY TO GIVE THE AI TIME TO READ THE GRID//
							SDL_Delay(100);
							//THE AI'S TURN//
							whosTurn();
							//RUN THE AI//
							GameAI();
						}
					}
					break;

				case SDLK_5:
					if (checkGridEmpty(1, 1) == true)
					{
						turn = whosTurn();
						grid[1][1] = turn;

						//AI ONLY REACTS IF THE USER INPUTS//
						if (playAI == true)
						{
							//LITTLE DELAY TO GIVE THE AI TIME TO READ THE GRID//
							SDL_Delay(100);	
							//THE AI'S TURN//
							whosTurn();
							//RUN THE AI//
							GameAI();
						}
					}
					break;

				case SDLK_6:
					if (checkGridEmpty(2, 1) == true)
					{
						turn = whosTurn();
						grid[2][1] = turn;

						//AI ONLY REACTS IF THE USER INPUTS//
						if (playAI == true)
						{
							//LITTLE DELAY TO GIVE THE AI TIME TO READ THE GRID//
							SDL_Delay(100);	
							//THE AI'S TURN//
							whosTurn();
							//RUN THE AI//
							GameAI();
						}
					}
					break;

				case SDLK_7:
					if (checkGridEmpty(0, 2) == true)
					{
						turn = whosTurn();
						grid[0][2] = turn;

						//AI ONLY REACTS IF THE USER INPUTS//
						if (playAI == true)
						{
							//LITTLE DELAY TO GIVE THE AI TIME TO READ THE GRID//
							SDL_Delay(100);	
							//THE AI'S TURN//
							whosTurn();
							//RUN THE AI//
							GameAI();
						}
					}
					break;

				case SDLK_8:
					if (checkGridEmpty(1, 2) == true)
					{
						turn = whosTurn();
						grid[1][2] = turn;

						//AI ONLY REACTS IF THE USER INPUTS//
						if (playAI == true)
						{
							//LITTLE DELAY TO GIVE THE AI TIME TO READ THE GRID//
							SDL_Delay(100);	
							//THE AI'S TURN//
							whosTurn();
							//RUN THE AI//
							GameAI();
						}
					}
					break;

				case SDLK_9:
					if (checkGridEmpty(2, 2) == true)
					{
						turn = whosTurn();
						grid[2][2] = turn;

						//AI ONLY REACTS IF THE USER INPUTS//
						if (playAI == true)
						{
							//LITTLE DELAY TO GIVE THE AI TIME TO READ THE GRID//
							SDL_Delay(100);	
							//THE AI'S TURN//
							whosTurn();
							//RUN THE AI//
							GameAI();
						}
					}
					break;

				case SDLK_ESCAPE:
					quitPlay = true;
					break;


				}
			}
			//CHECKS IF THE WINDOW WAS CLOSED//
			else if (gameInput.type == SDL_QUIT)
			{
				//EXITS THE MAIN LOOP//
				quitPlay = true;
				quitGame = true;
			}
			//NEEDED LATER TO MAKE SURE AI DOESNT DO DOUBLE MOVES//
			hasAImoved = false;

			//CHECKS IF THE AI WAS ACTIVATED AND IF ITS THE AI'S TURN//


			windowUpdate();

			int winner = checkWin();

			if (winner != 0)
			{
				SDL_Rect winMsg;
				winMsg.x = 130;
				winMsg.y = 255;
				winMsg.w = 75;
				winMsg.h = 75;

				//IF NOUGHTS WINS//
				if (winner == 1)
				{
					SDL_BlitSurface(Nought, NULL, screen, &winMsg);
					winMsg.x += 75;
					winMsg.w = 150;
					SDL_BlitSurface(Win, NULL, screen, &winMsg);

				}
				//IF CROSS WINS//
				if (winner == 2)
				{
					SDL_BlitSurface(Cross, NULL, screen, &winMsg);
					winMsg.x += 75;
					winMsg.w = 150;
					SDL_BlitSurface(Win, NULL, screen, &winMsg);
				}
				//IF DRAW//
				if (winner == 3)
				{
					winMsg.x = 175;
					winMsg.w = 150;
					SDL_BlitSurface(Draw, NULL, screen, &winMsg);
				}

				quitPlay = true;
			}


			windowUpdate();
		}
	}

	resetGrid();

	playAI = false;
	AIsetup = false;
	AIattackPattern = 0;
	hasAImoved = false;
	attStep = 0;

	SDL_Delay(3000);

	close();
	initialise();
}

int XO::whosTurn()
{
	SDL_Rect playerTurn;
	playerTurn.x = 25;
	playerTurn.y = 350;
	playerTurn.w = 420;
	playerTurn.h = 140;

	if (player1 > player2)
	{
		player2++;
		SDL_BlitSurface(XTurn, NULL, screen, &playerTurn);
		return 1;
	}
	else if (player2 >= player1)
	{
		player1++;
		SDL_BlitSurface(OTurn, NULL, screen, &playerTurn);
		return 2;
	}
}

bool XO::checkGridEmpty(int x, int y)
{
	if (grid[x][y] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int XO::checkWin()
{
	int win = 0;

	//PLACED HERE FIRST BECAUSE IF ANYONE WINS ON THE LAST TURN, THIS GETS OVERWRITTEN//
	//DRAW I.E. NO ONE WINS//
	//THIS IS WHERE THE BOARD IS FULL BUT THE BOARD DOES NOT HAVE ANY WIN STATES//
	if (grid[0][0] != 0 && grid[0][1] != 0 && grid[0][2] != 0 &&
		grid[1][0] != 0 && grid[1][1] != 0 && grid[1][2] != 0 &&
		grid[2][0] != 0 && grid[2][1] != 0 && grid[2][2] != 0)
	{
		win = 3;
	}

	//PLAYER 1 WIN STATES//
	////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////
	//HORIZONTAL WIN STATES//
	if ((grid[0][0] == 1 && grid[1][0] == 1 && grid[2][0] == 1) ||
		(grid[0][1] == 1 && grid[1][1] == 1 && grid[2][1] == 1) ||
		(grid[0][2] == 1 && grid[1][2] == 1 && grid[2][2] == 1))
	{
		win = 1;
	}
	//VERTICAL WIN STATES//
	if ((grid[0][0] == 1 && grid[0][1] == 1 && grid[0][2] == 1) ||
		(grid[1][0] == 1 && grid[1][1] == 1 && grid[1][2] == 1) ||
		(grid[2][0] == 1 && grid[2][1] == 1 && grid[2][2] == 1))
	{
		win = 1;
	}
	//DIAGONAL WIN STATES//
	if ((grid[0][0] == 1 && grid[1][1] == 1 && grid[2][2] == 1) ||
		(grid[2][0] == 1 && grid[1][1] == 1 && grid[0][2] == 1))
	{
		win = 1;
	}
	////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////

	//PLAYER 2 WIN STATES//
	////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////
	if ((grid[0][0] == 2 && grid[1][0] == 2 && grid[2][0] == 2) ||
		(grid[0][1] == 2 && grid[1][1] == 2 && grid[2][1] == 2) ||
		(grid[0][2] == 2 && grid[1][2] == 2 && grid[2][2] == 2))
	{
		win = 2;
	}
	//VERTICAL WIN STATES//
	if ((grid[0][0] == 2 && grid[0][1] == 2 && grid[0][2] == 2) ||
		(grid[1][0] == 2 && grid[1][1] == 2 && grid[1][2] == 2) ||
		(grid[2][0] == 2 && grid[2][1] == 2 && grid[2][2] == 2))
	{
		win = 2;
	}
	//DIAGONAL WIN STATES//
	if ((grid[0][0] == 2 && grid[1][1] == 2 && grid[2][2] == 2) ||
		(grid[2][0] == 2 && grid[1][1] == 2 && grid[0][2] == 2))
	{
		win = 2;
	}
	////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////

	return win;
}

void XO::resetGrid()
{
	//THIS IS TO RESET THE GRID TO ZERO VALUES SHOULD THE PLAYERS WANT TO PLAY ANOTHER GAME//

	grid[0][0] = 0;
	grid[0][1] = 0;
	grid[0][2] = 0;

	grid[1][0] = 0;
	grid[1][1] = 0;
	grid[1][2] = 0;

	grid[2][0] = 0;
	grid[2][1] = 0;
	grid[2][2] = 0;

	quitPlay = false;

	windowUpdate();
}
