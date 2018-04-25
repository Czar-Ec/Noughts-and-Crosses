#include "GlobalVars.h"

//LOAD IMAGES AS SURFACE//
bool XO::loadImg()
{
	bool success = true;


	if (imgPack == 1)
	{
		gameBackground = SDL_LoadBMP("images/pack1/XOBoard.bmp");
		if (gameBackground == NULL)
		{
			errorLog("Image could not be loaded: XOBoard.bmp");
			SDL_GetError();
			success = false;
		}

		Nought = SDL_LoadBMP("images/pack1/Nought.bmp");
		if (Nought == NULL)
		{
			errorLog("Image could not be loaded: Nought.bmp");
			SDL_GetError();
			success = false;
		}

		Cross = SDL_LoadBMP("images/pack1/Cross.bmp");
		if (Cross == NULL)
		{
			errorLog("Image could not be loaded: Cross.bmp");
			SDL_GetError();
			success = false;
		}

		MainMenu = SDL_LoadBMP("images/pack1/MainMenu.bmp");
		if (MainMenu == NULL)
		{
			errorLog("Image could not be loaded: MainMenu.bmp");
			SDL_GetError();
			success = false;
		}

		OptionMenu = SDL_LoadBMP("images/pack1/OptionMenu.bmp");
		if (OptionMenu == NULL)
		{
			errorLog("Image could not be loaded: OptionMenu.bmp");
			SDL_GetError();
			success = false;
		}

		XTurn = SDL_LoadBMP("images/pack1/XTurn.bmp");
		if (XTurn == NULL)
		{
			errorLog("Image could not be loaded: XTurn.bmp");
			SDL_GetError();
			success = false;
		}

		OTurn = SDL_LoadBMP("images/pack1/OTurn.bmp");
		if (XTurn == NULL)
		{
			errorLog("Image could not be loaded: OTurn.bmp");
			SDL_GetError();
			success = false;
		}

		Win = SDL_LoadBMP("images/pack1/Win.bmp");
		if (Win == NULL)
		{
			errorLog("Image could not be loaded: Win.bmp");
			SDL_GetError();
			success = false;
		}

		Draw = SDL_LoadBMP("images/pack1/Draw.bmp");
		if (Draw == NULL)
		{
			errorLog("Image could not be loaded: Draw.bmp");
			SDL_GetError();
			success = false;
		}
	}

	if (imgPack == 2)
	{
		gameBackground = SDL_LoadBMP("images/pack2/XOBoard2.bmp");
		if (gameBackground == NULL)
		{
			errorLog("Image could not be loaded: XOBoard2.bmp");
			SDL_GetError();
			success = false;
		}

		Nought = SDL_LoadBMP("images/pack2/Nought2.bmp");
		if (Nought == NULL)
		{
			errorLog("Image could not be loaded: Nought2.bmp");
			SDL_GetError();
			success = false;
		}

		Cross = SDL_LoadBMP("images/pack2/Cross2.bmp");
		if (Cross == NULL)
		{
			errorLog("Image could not be loaded: Cross2.bmp");
			SDL_GetError();
			success = false;
		}

		MainMenu = SDL_LoadBMP("images/pack2/MainMenu2.bmp");
		if (MainMenu == NULL)
		{
			errorLog("Image could not be loaded: MainMenu2.bmp");
			SDL_GetError();
			success = false;
		}

		OptionMenu = SDL_LoadBMP("images/pack2/OptionMenu2.bmp");
		if (OptionMenu == NULL)
		{
			errorLog("Image could not be loaded: OptionMenu2.bmp");
			SDL_GetError();
			success = false;
		}

		XTurn = SDL_LoadBMP("images/pack2/XTurn2.bmp");
		if (XTurn == NULL)
		{
			errorLog("Image could not be loaded: XTurn2.bmp");
			SDL_GetError();
			success = false;
		}

		OTurn = SDL_LoadBMP("images/pack2/OTurn2.bmp");
		if (XTurn == NULL)
		{
			errorLog("Image could not be loaded: OTurn2.bmp");
			SDL_GetError();
			success = false;
		}

		Win = SDL_LoadBMP("images/pack2/Wins2.bmp");
		if (Win == NULL)
		{
			errorLog("Image could not be loaded: Wins2.bmp");
			SDL_GetError();
			success = false;
		}

		Draw = SDL_LoadBMP("images/pack2/Draw2.bmp");
		if (Draw == NULL)
		{
			errorLog("Image could not be loaded: Draw2.bmp");
			SDL_GetError();
			success = false;
		}
	}

	if (imgPack == 3)
	{
		gameBackground = SDL_LoadBMP("images/pack3/XOBoardDOS.bmp");
		if (gameBackground == NULL)
		{
			errorLog("Image could not be loaded: XOBoardDOS.bmp");
			SDL_GetError();
			success = false;
		}

		Nought = SDL_LoadBMP("images/pack3/NoughtDOS.bmp");
		if (Nought == NULL)
		{
			errorLog("Image could not be loaded: NoughtDOS.bmp");
			SDL_GetError();
			success = false;
		}

		Cross = SDL_LoadBMP("images/pack3/CrossDOS.bmp");
		if (Cross == NULL)
		{
			errorLog("Image could not be loaded: CrossDOS.bmp");
			SDL_GetError();
			success = false;
		}

		MainMenu = SDL_LoadBMP("images/pack3/MainMenuDOS.bmp");
		if (MainMenu == NULL)
		{
			errorLog("Image could not be loaded: MainMenuDOS.bmp");
			SDL_GetError();
			success = false;
		}

		OptionMenu = SDL_LoadBMP("images/pack3/OptionMenuDOS.bmp");
		if (OptionMenu == NULL)
		{
			errorLog("Image could not be loaded: OptionMenuDOS.bmp");
			SDL_GetError();
			success = false;
		}

		XTurn = SDL_LoadBMP("images/pack3/XTurnDOS.bmp");
		if (XTurn == NULL)
		{
			errorLog("Image could not be loaded: XTurnDOS.bmp");
			SDL_GetError();
			success = false;
		}

		OTurn = SDL_LoadBMP("images/pack3/OTurnDOS.bmp");
		if (XTurn == NULL)
		{
			errorLog("Image could not be loaded: OTurnDOS.bmp");
			SDL_GetError();
			success = false;
		}

		Win = SDL_LoadBMP("images/pack3/WinsDOS.bmp");
		if (Win == NULL)
		{
			errorLog("Image could not be loaded: WinsDOS.bmp");
			SDL_GetError();
			success = false;
		}

		Draw = SDL_LoadBMP("images/pack3/DrawDOS.bmp");
		if (Draw == NULL)
		{
			errorLog("Image could not be loaded: DrawDOS.bmp");
			SDL_GetError();
			success = false;
		}
	}

	return success;
}

void XO::windowUpdate()
{
	if (quitPlay == false)
	{
		SDL_Rect rect;
		//1 ON GRID//
		//THE RECT VALUES ARE THE POSITION WHERE TO DRAW ON//
		//&rect IS THE COORDINATES AS TO WHERE THE IMAGE WILL BE DRAWN ON//
		rect.x = 132;
		rect.y = 10;
		rect.w = 75;
		rect.h = 75;

		//IF THE GRID REFERED = 2, DRAWS A CROSS ON IT//
		if (grid[0][0] == 2)
		{
			SDL_BlitSurface(Cross, NULL, screen, &rect);
		}
		//IF THE GRID REFERED = 1, DRAWS A NOUGHT ON IT//
		else if (grid[0][0] == 1)
		{
			SDL_BlitSurface(Nought, NULL, screen, &rect);
		}


		//2//
		rect.x = 212;
		rect.y = 10;

		if (grid[1][0] == 2)
		{
			SDL_BlitSurface(Cross, NULL, screen, &rect);
		}
		else if (grid[1][0] == 1)
		{
			SDL_BlitSurface(Nought, NULL, screen, &rect);
		}


		//3//
		rect.x = 292;
		rect.y = 10;

		if (grid[2][0] == 2)
		{
			SDL_BlitSurface(Cross, NULL, screen, &rect);
		}
		else if (grid[2][0] == 1)
		{
			SDL_BlitSurface(Nought, NULL, screen, &rect);
		}


		//4//
		rect.x = 132;
		rect.y = 90;

		if (grid[0][1] == 2)
		{
			SDL_BlitSurface(Cross, NULL, screen, &rect);
		}
		else if (grid[0][1] == 1)
		{
			SDL_BlitSurface(Nought, NULL, screen, &rect);
		}

		//5//
		rect.x = 212;
		rect.y = 90;

		if (grid[1][1] == 2)
		{
			SDL_BlitSurface(Cross, NULL, screen, &rect);
		}
		else if (grid[1][1] == 1)
		{
			SDL_BlitSurface(Nought, NULL, screen, &rect);
		}

		//6//
		rect.x = 292;
		rect.y = 90;

		if (grid[2][1] == 2)
		{
			SDL_BlitSurface(Cross, NULL, screen, &rect);
		}
		else if (grid[2][1] == 1)
		{
			SDL_BlitSurface(Nought, NULL, screen, &rect);
		}

		//7//
		rect.x = 132;
		rect.y = 170;

		if (grid[0][2] == 2)
		{
			SDL_BlitSurface(Cross, NULL, screen, &rect);
		}
		else if (grid[0][2] == 1)
		{
			SDL_BlitSurface(Nought, NULL, screen, &rect);
		}

		//8//
		rect.x = 212;
		rect.y = 170;

		if (grid[1][2] == 2)
		{
			SDL_BlitSurface(Cross, NULL, screen, &rect);
		}
		else if (grid[1][2] == 1)
		{
			SDL_BlitSurface(Nought, NULL, screen, &rect);
		}

		//9//
		rect.x = 292;
		rect.y = 170;

		if (grid[2][2] == 2)
		{
			SDL_BlitSurface(Cross, NULL, screen, &rect);
		}
		else if (grid[2][2] == 1)
		{
			SDL_BlitSurface(Nought, NULL, screen, &rect);
		}
	}

	//UPDATES WINDOW SURFACE//
	SDL_UpdateWindowSurface(window);

}

//CLOSE WINDOW, USED TO RESET THE IMAGES ON SCREEN AFTER THE GAME//
void XO::close()
{
	//CLOSE WINDOW//
	SDL_DestroyWindow(window);


	//QUIT SDL//
	SDL_Quit();
}
