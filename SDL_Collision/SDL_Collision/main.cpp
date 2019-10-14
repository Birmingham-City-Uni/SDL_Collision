#include "GameLoop.h"

#undef main

//this can be accessed in any cpp file by adding "extern GameLoop * gameLoop"
GameLoop * gameLoop;

int main(int argc, char* args[])
{
	//construct a new gameloop object
	gameLoop = new GameLoop();
	if (!gameLoop->init()) {
		return 1;
	}

	//update and draw the game until quit by the user
	while (gameLoop->processInput()) {
		gameLoop->update();
		gameLoop->draw();
	}

	//perform any necessary cleaning up
	gameLoop->clean();

	//delete the gameloop object which has been allocated to memory.
	delete gameLoop;
	return 0;
}