#include "GlobalVars.h"

XO::XO()
{
	//DEFAULT IMAGE PACK//
	imgPack = 1;

	//CALLS INITIALISE FUNCTION//
	bool init = initialise();

	if (init == false)
	{
		errorLog("Something went wrong while initialising");
		SDL_GetError();
	}

	//VARIABLE USED TO CHECK IF THE PLAYER WANTS TO END GAME//
	quitGame = false;

	mainLoop();

	//QUITS PROGRAM//
	close();
}



//PRINTS ERROR TO FILE//
//Not only does this help me easily spot problems, this function will also help
//you find what errors can happen when you eventually break my game.
//To be honest, the most likely reasons my the game might break is the fact
//that files will get shuffled around the project file i.e. you might end up moving the .dll
//.lib or even the images around, therefore the code will not be able to find those
void XO::errorLog(string error)
{
	ofstream errorlog;
	//OPEN (OR CREATE) errorlog.txt//
	errorlog.open("errorlog.txt", ios::app);
	//APPEND error INTO FILE//
	errorlog << error << endl;
	//CLOSE FILE//
	errorlog.close();
}