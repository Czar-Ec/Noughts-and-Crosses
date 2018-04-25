#include "GlobalVars.h"

void XO::GameAI()
{	
	//CHECKS IF THE PLAYER HAS ALREADY WON IF THE PLAYER HAS//
	//ALREADY WON, THE AI IS SHUT//
	if (checkWin() != 0)
	{
		hasAImoved = true;
	}
	
	//SETS UP THE AI'S ATTACK PATTERN//
	if (AIsetup == false)
	{
		AIsetup = true;

		//CHECKS IF THE PLAYER STARTED IN THE CORNER//
		if (grid[0][0] == 1 ||
			grid[0][2] == 1 ||
			grid[2][0] == 1 ||
			grid[2][2] == 1)
		{
			//SET ATTACK PATTERN TO CORNER GAME I.E. 1//
			AIattackPattern = 1;
		}

		//CHECKS IF THE PLAYER STARTED IN CENTER//
		if (grid[1][1] == 1)
		{
			//SET ATTACK PATTERN TO CENTER GAME I.E. 2//
			AIattackPattern = 2;
		}

		//CHECKS IF PLAYER STARTED IN THE EDGES//
		if (grid[1][0] == 1 ||
			grid[0][1] == 1 ||
			grid[2][1] == 1 ||
			grid[1][2] == 1)
		{
			//SETS ATTACK PATTERN TO EDGE GAME I.E. 3//
			AIattackPattern = 3;
		}

	}

		//CORNER GAME I.E. HUMAN STARTED ON A CORNER//
		if (AIattackPattern == 1)
		{
			attPattern1();
		}


		//CENTER GAME I.E. HUMAN STARTED IN CENTER//
		if (AIattackPattern == 2)
		{
			attPattern2();
		}

		//EDGE GAME I.E. HUMAN STARTED IN EDGE//
		if (AIattackPattern == 3)
		{
			//THIS IS ALL THE CONTENTS OF ATTACK PATTERN 3//
			if (hasAImoved == false)
			{
				AIattack();
			}

			if (hasAImoved == false)
			{
				AIdefend();
			}

			if (hasAImoved == false)
			{
				AIfailsafe();
			}
		}
	

}

//CORNER GAME ATTACK PATTERN//
//THIS IS THE FUNCTION TO BE USED WHEN THE PLAYER CHOOSES TO START IN A CORNER//
void XO::attPattern1()
{
	//THE AI WILL ALWAYS PLAY IN THE CENTER FOR THIS ATTACK PATTERN//
	if (attStep == 0)
	{
		grid[1][1] = 2;
		hasAImoved = true;
	}

	//CHECK IF THERES A CHANCE THE PLAYER COULD WIN, IF NOT//
	//THE NEXT STEP OF THE ATTACK PATTERN IS TO CHOOSE A NON CORNER//
	//THE AI CAN CHOOSE ANY//
	if (attStep == 1)
	{
		if (hasAImoved == false)
		{
			AIdefend();
		}
		
		while (!hasAImoved)
		{
			int choice = rand() % 4 + 1;
			if (choice == 1 && grid[1][0] == 0)
			{
				grid[1][0] = 2;
				hasAImoved = true;
				break;
			}

			if (choice == 2 && grid[0][1] == 0)
			{
				grid[0][1] = 2;
				hasAImoved = true;
				break;
			}

			if (choice == 3 && grid[2][1] == 0)
			{
				grid[2][1] = 2;
				hasAImoved = true;
				break;
			}

			if (choice == 4 && grid[1][2] == 0)
			{
				grid[1][2] = 2;
				hasAImoved = true;
				break;
			}
		}
	}

	else
	{
			AIattack();

			AIdefend();

			AIfailsafe();
	}

	attStep++;
}

//CENTER GAME ATTACK PATTERN//
//THIS IS THE FUNCTION TO BE USED WHEN THE PLAYER CHOOSES TO START IN THE CENTER//
void XO::attPattern2()
{
	//IF THE FIRST STEP OF THE ATTACK PATTERN, THE AI TAKES A RANDOM CORNER//
	if (attStep == 0)
	{
		while (!hasAImoved)
		{
			int choice = rand() % 4 + 1;

			if (choice == 1 && grid[0][0] == 0)
			{
				grid[0][0] = 2;
				hasAImoved = true;
				break;
			}

			if (choice == 2 && grid[2][0] == 0)
			{
				grid[2][0] = 2;
				hasAImoved = true;
				break;
			}

			if (choice == 3 && grid[0][2] == 0)
			{
				grid[0][2] = 2;
				hasAImoved = true;
				break;
			}

			if (choice == 4 && grid[2][2] == 0)
			{
				grid[2][2] = 2;
				hasAImoved = true;
				break;
			}

		}
	}

	if (attStep == 1)
	{
		if (hasAImoved == false)
		{
			AIattack();
		}

		if (hasAImoved == false)
		{
			AIdefend();
		}

		if (hasAImoved == false)
		{
			while (!hasAImoved)
			{
				int choice = rand() % 4 + 1;

				if (choice == 1 && grid[0][0] == 0)
				{
					grid[0][0] = 2;
					hasAImoved = true;
					break;
				}

				if (choice == 2 && grid[2][0] == 0)
				{
					grid[2][0] = 2;
					hasAImoved = true;
					break;
				}

				if (choice == 3 && grid[0][2] == 0)
				{
					grid[0][2] = 2;
					hasAImoved = true;
					break;
				}

				if (choice == 4 && grid[2][2] == 0)
				{
					grid[2][2] = 2;
					hasAImoved = true;
					break;
				}

			}
		}
	}

	else
	{
		if (hasAImoved == false)
		{
			AIattack();
		}

		if (hasAImoved == false)
		{
			AIdefend();
		}

		if (hasAImoved == false)
		{
			AIfailsafe();
		}
	}

	attStep++;
}

void XO::AIattack()
{
	//HORIZONTAL//
	//////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i <= 2; i++)
	{
		//LOOKS AT THE LEFT OF ROW I//
		if (grid[i][0] == 0 &&
			grid[i][1] == 2 &&
			grid[i][2] == 2 &&
			hasAImoved == false)
		{
			grid[i][0] = 2;
			hasAImoved = true;
			break;
		}

		//LOOKS AT THE MIDDLE OF ROW I//
		if (grid[i][1] == 0 &&
			grid[i][0] == 2 &&
			grid[i][2] == 2 &&
			hasAImoved == false)
		{
			grid[i][1] = 2;
			hasAImoved = true;
			break;
		}

		//LOOKS AT THE RIGHT OF ROW I//
		if (grid[i][2] == 0 &&
			grid[i][0] == 2 &&
			grid[i][1] == 2 &&
			hasAImoved == false)
		{
			grid[i][2] = 2;
			hasAImoved = true;
			break;
		}
	}

	//VERTICAL//
	//////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i <= 2; i++)
	{
		//LOOKS AT THE TOP OF COLUMN I//
		if (grid[0][i] == 0 &&
			grid[1][i] == 2 &&
			grid[2][i] == 2 &&
			hasAImoved == false)
		{
			grid[0][i] = 2;
			hasAImoved = true;
			break;
		}

		//LOOKS AT THE MIDDLE OF COLUMN I//
		if (grid[1][i] == 0 &&
			grid[0][i] == 2 &&
			grid[2][i] == 2 &&
			hasAImoved == false)
		{
			grid[1][i] = 2;
			hasAImoved = true;
			break;
		}

		//LOOKS AT THE BOTTOM OF COLUMN I//
		if (grid[2][i] == 0 &&
			grid[0][i] == 2 &&
			grid[1][i] == 2 &&
			hasAImoved == false)
		{
			grid[2][i] = 2;
			hasAImoved = true;
			break;
		}
	}

	//DIAGONAL//
	//////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////
	//LOOK AT TOP LEFT//
	if (grid[0][0] == 0 &&
		grid[1][1] == 2 &&
		grid[2][2] == 2 &&
		hasAImoved == false)
	{
		grid[0][0] = 2;
		hasAImoved = true;
	}
	
	//LOOK AT TOP RIGHT//
	if (grid[0][2] == 0 &&
		grid[1][1] == 2 &&
		grid[2][0] == 2 &&
		hasAImoved == false)
	{
		grid[0][2] = 2;
		hasAImoved = true;
	}

	//LOOK AT BOTTOM LEFT//
	if (grid[2][0] == 0 &&
		grid[1][1] == 2 &&
		grid[0][2] == 2 &&
		hasAImoved == false)
	{
		grid[2][0] = 2;
		hasAImoved = true;
	}

	//LOOK AT BOTTOM RIGHT//
	if (grid[2][2] == 0 &&
		grid[1][1] == 2 &&
		grid[0][0] == 2 &&
		hasAImoved == false)
	{
		grid[2][2] = 2;
		hasAImoved = true;
	}

	//LOOK AT CENTER//
	if (grid[1][1] == 0 &&
		((grid[0][0] == 2 && grid[2][2] == 2) ||
			(grid[2][0] == 2 && grid[0][2] == 2)) &&
		hasAImoved == false)
	{
		grid[1][1] = 2;
		hasAImoved = true;
	}
}

void XO::AIdefend()
{
	//THE DEFENCE IS THE EXACT SAME AS THE ATTACK, 
	//EXCEPT LOOKS FOR THE VALUE OF GRID AS 1 INSTEAD OF 2//
	//HORIZONTAL//
	//////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i <= 2; i++)
	{
		//LOOKS AT THE LEFT OF ROW I//
		if (grid[i][0] == 0 &&
			grid[i][1] == 1 &&
			grid[i][2] == 1 &&
			hasAImoved == false)
		{
			grid[i][0] = 2;
			hasAImoved = true;
			break;
		}

		//LOOKS AT THE MIDDLE OF ROW I//
		if (grid[i][1] == 0 &&
			grid[i][0] == 1 &&
			grid[i][2] == 1 &&
			hasAImoved == false)
		{
			grid[i][1] = 2;
			hasAImoved = true;
			break;
		}

		//LOOKS AT THE RIGHT OF ROW I//
		if (grid[i][2] == 0 &&
			grid[i][0] == 1 &&
			grid[i][1] == 1 &&
			hasAImoved == false)
		{
			grid[i][2] = 2;
			hasAImoved = true;
			break;
		}
	}

	//VERTICAL//
	//////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i <= 2; i++)
	{
		//LOOKS AT THE TOP OF COLUMN I//
		if (grid[0][i] == 0 &&
			grid[1][i] == 1 &&
			grid[2][i] == 1 &&
			hasAImoved == false)
		{
			grid[0][i] = 2;
			hasAImoved = true;
			break;
		}

		//LOOKS AT THE MIDDLE OF COLUMN I//
		if (grid[1][i] == 0 &&
			grid[0][i] == 1 &&
			grid[2][i] == 1 &&
			hasAImoved == false)
		{
			grid[1][i] = 2;
			hasAImoved = true;
			break;
		}

		//LOOKS AT THE BOTTOM OF COLUMN I//
		if (grid[2][i] == 0 &&
			grid[0][i] == 1 &&
			grid[1][i] == 1 &&
			hasAImoved == false)
		{
			grid[2][i] = 2;
			hasAImoved = true;
			break;
		}
	}

	//DIAGONAL//
	//////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////
	//LOOK AT TOP LEFT//
	if (grid[0][0] == 0 &&
		grid[1][1] == 1 &&
		grid[2][2] == 1 &&
		hasAImoved == false)
	{
		grid[0][0] = 2;
		hasAImoved = true;
	}

	//LOOK AT TOP RIGHT//
	if (grid[0][2] == 0 &&
		grid[1][1] == 1 &&
		grid[2][0] == 1 &&
		hasAImoved == false)
	{
		grid[0][2] = 2;
		hasAImoved = true;
	}

	//LOOK AT BOTTOM LEFT//
	if (grid[2][0] == 0 &&
		grid[1][1] == 1 &&
		grid[0][2] == 1 &&
		hasAImoved == false)
	{
		grid[2][0] = 2;
		hasAImoved = true;
	}

	//LOOK AT BOTTOM RIGHT//
	if (grid[2][2] == 0 &&
		grid[1][1] == 1 &&
		grid[0][0] == 1 &&
		hasAImoved == false)
	{
		grid[2][2] = 2;
		hasAImoved = true;
	}

	//LOOK AT CENTER//
	if (grid[1][1] == 0 &&
		((grid[0][0] == 1 && grid[2][2] == 1) ||
			(grid[2][0] == 1 && grid[0][2] == 1)) &&
		hasAImoved == false)
	{
		grid[1][1] = 2;
		hasAImoved = true;
	}
}

//THIS FUNCTION IS HERE SHOULD THE PLAYER CONFUSE THE AI//
//OR IF YOU HACK (CHANGE VARIABLES WITHOUT PERMISSION) THE PROGRAM//
void XO::AIfailsafe()
{	

	//WILL KEEP LOOPING UNTIL THE AI HAS CHOSEN A VALID MOVE//
	while (!hasAImoved)
	{
		//CHOOSES FROM RANGE 1 - 9//
		int choice = rand() % 9 + 1;
		//CHECKS WHICH VALUE THE AI CHOSE AND CHECKS WHETHER THOSE SPOTS ARE FREE//
		if (choice == 1 && grid[0][0] == 0)
		{
			grid[0][0] = 2;
			hasAImoved = true;
		}

		if (choice == 2 && grid[1][0] == 0)
		{
			grid[1][0] = 2;
			hasAImoved = true;
		}

		if (choice == 3 && grid[2][0] == 0)
		{
			grid[2][0] = 2;
			hasAImoved = true;
		}

		if (choice == 4 && grid[0][1] == 0)
		{
			grid[0][1] = 2;
			hasAImoved = true;
		}

		if (choice == 5 && grid[1][1] == 0)
		{
			grid[1][1] = 2;
			hasAImoved = true;
		}

		if (choice == 6 && grid[2][1] == 0)
		{
			grid[2][1] = 2;
			hasAImoved = true;
		}

		if (choice == 7 && grid[0][2] == 0)
		{
			grid[0][2] = 2;
			hasAImoved = true;
		}

		if (choice == 8 && grid[1][2] == 0)
		{
			grid[1][2] = 2;
			hasAImoved = true;
		}

		if (choice == 9 && grid[2][2] == 0)
		{
			grid[2][2] = 2;
			hasAImoved = true;
		}
	}

}

