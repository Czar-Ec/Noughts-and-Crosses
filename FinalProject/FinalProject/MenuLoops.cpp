#include "GlobalVars.h"

void XO::mainLoop()
{
	//INITIALISE AN EVENT//
	SDL_Event mainMenuInput;

	//THIS RECTANGLE IS THE LOCATION OF THE MENU//
	SDL_Rect MenuRect;
	MenuRect.x = 25;
	MenuRect.y = 350;
	MenuRect.w = 420;
	MenuRect.h = 140;


	//THE MAIN LOOP//
	while (!quitGame)
	{
		//WHILE AN EVENT IS BEING POLLED//
		while (SDL_PollEvent(&mainMenuInput))
		{
			//IF A JEY IS BEING PRESSED//
			if (mainMenuInput.type == SDL_KEYDOWN)
			{
				switch (mainMenuInput.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					screen = NULL;
					quitGame = true;
					break;

				case SDLK_1:
					player1 = 1;
					player2 = 0;

					playAI = false;

					SDL_BlitSurface(OTurn, NULL, screen, &MenuRect);

					resetGrid();
					gameLoop();
					break;

				case SDLK_2:
					player1 = 1;
					player2 = 0;

					playAI = true;

					SDL_BlitSurface(OTurn, NULL, screen, &MenuRect);

					resetGrid();
					gameLoop();
					break;

				case SDLK_3:
					optionLoop();

					break;
				}
			}
			//ELSE IF THE WINDOW IS CLOSED//
			else if (mainMenuInput.type == SDL_QUIT)
			{
				quitGame = true;
			}

		}

	}
}

void XO::optionLoop()
{
	SDL_Rect OptBox;
	OptBox.x = 25;
	OptBox.y = 350;
	OptBox.h = 140;
	OptBox.w = 420;

	SDL_BlitSurface(OptionMenu, NULL, screen, &OptBox);

	windowUpdate();
	
	SDL_Event optionMenuInput;

	bool returntoMain = false;

	while (!returntoMain)
	{
		while (SDL_PollEvent(&optionMenuInput))
		{
			if (optionMenuInput.type == SDL_KEYDOWN)
			{
				switch (optionMenuInput.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					
					SDL_BlitSurface(MainMenu, NULL, screen, &OptBox);

					windowUpdate();

					returntoMain = true;
					break;
				//DEFAULT IMAGE PACK//
				case SDLK_1:
					imgPack = 1;
					close();
					initialise();
					returntoMain = true;
					break;
				//GREEN IMAGE PACK//
				case SDLK_2:
					imgPack = 2;
					close();
					initialise();
					returntoMain = true;
					break;
				//DOS IMAGE PACK//
				case SDLK_3:
					imgPack = 3;
					close();
					initialise();
					returntoMain = true;
					break;
				}
			}
			else if (optionMenuInput.type == SDL_QUIT)
			{
				returntoMain = true;
				quitGame = true;
			}
		}
	}

}