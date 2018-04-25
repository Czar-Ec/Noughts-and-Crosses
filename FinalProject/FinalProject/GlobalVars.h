#pragma once

#include "SDL.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

class XO
{
public:
	//CONSTRUCTOR//
	XO();
	
	//FUNCTION PROTOTYPES//
	////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////
	//LOADER FUNCTIONS//
	bool initialise();
	bool loadImg();
	void windowUpdate();

	//LOOP FUNCTIONS//
	void mainLoop();
	void optionLoop();
	void gameLoop();

	//CHECK FUNCTIONS//
	bool checkGridEmpty(int, int);
	int checkWin();
	int whosTurn();

	//RESET FUNCTIONS//
	void resetGrid();
	void close();

	//ERROR FUNCTION//
	void errorLog(string error);

	//THE GAME'S AI//
	void GameAI();
	void attPattern1();
	void attPattern2();
	void AIattack();
	void AIdefend();
	void AIfailsafe();
	////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////


	//NOTE TO READER//
	//there's a reason why there seems to be a lot of images...
	//I initially tried to use SDL_ttf.h to write text but it proved
	//too difficult for me, so the alternative was to create the text externally
	//as an image and treat it as such

	//WINDOW AND SCREEN//
	SDL_Window* window = NULL;
	SDL_Surface* screen = NULL;
	//GAME IMAGES//
	SDL_Surface* gameBackground = NULL;
	SDL_Surface* Nought = NULL;
	SDL_Surface* Cross = NULL;
	SDL_Surface* MainMenu = NULL;
	SDL_Surface* OptionMenu = NULL;
	SDL_Surface* XTurn = NULL;
	SDL_Surface* OTurn = NULL;
	SDL_Surface* Draw = NULL;
	SDL_Surface* Win = NULL;

	//WINDOW SIZE//
	int winWidth = 500;
	int winHeight = 500;

private:
	//GLOBAL VARIABLES//
	////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////

	//VARIABLE WHICH DETERMINES WHICH IMAGE PACK TO LOAD//
	int imgPack;

	//GRID GLOBAL VARIABLE//
	char grid[3][3];

	//PLAYER VALUE VARIABLES//
	int player1;
	int player2;

	//MULTIPLE FUNCTIONS NEED TO REFER TO THIS THEREFORE NEEDS TO BE GLOBAL//
	//DON'T GIVE ME SASS ABOUT THIS//
	bool quitPlay = false;
	bool quitGame;

	//AI RELATED//
	bool hasAImoved = false;
	bool playAI = false;
	bool AIsetup = false;
	int AIattackPattern = NULL;	//DETERMINES HOW THE AI WILL SET ITS MOVES ON THE GRID//
	int attStep = 0;
	////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////
};