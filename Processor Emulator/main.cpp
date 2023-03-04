#include "stdafx.h"
using namespace std;

int main(int argc, char** argv)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << SDL_GetError() << endl;
		exit(-1);
	}


	return 0;
}