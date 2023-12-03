#include <iostream>
#include "Game.hpp"
using namespace std;
// void Game::initializePlayers() {
// 	for (int i = 0; i < 4; ++i) {
// 		for (int j = 0; j < 6; ++j) {
// 			//TreasureCards card = treasureDeck.pop();
// 			//players[i].addTreasureCard(&card);
// 		}
// 	}
// }
bool Game::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "The A-MAZE-ing Labyrinth", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

			}
		}
	}

	return success;
}
int Game::highlightElements(SDL_Renderer*gRenderer, SDL_Texture* asset, bool highlightActiveRight, bool highlightActiveLeft){
	
		// cout << highlightActive << " highlight elements" <<  endl;
		static int i = 0;
		// int j = i-1;
		//cout<<i<<endl;
		std::vector <SDL_Rect> arrow = {{672, 158, 45, 45},{672, 158, 45, 45},{672, 158, 45, 45},
										{518, 656, 45, 45},{518, 656, 45, 45},{518, 656, 45, 45},
										{0, 507, 45, 45},{0, 507, 45, 45},{0, 507, 45, 45},
										 {162, 3, 45, 45},{162, 3, 45, 45},{162, 3, 45, 45}};
		std::vector <SDL_Rect> arrow_dest = {{672, 158, 45, 45},{672, 337, 45, 45}, {672, 510, 45, 45}, {518, 656, 45, 45},
											{345, 656, 45, 45}, {162, 653, 45, 45}, {0, 507, 45, 45}, {0, 328, 45, 45},
											{0, 155, 45, 45}, {162, 3, 45, 45}, {345, 4, 45, 45}, {518, 5, 45, 45} };
		SDL_RenderCopy(gRenderer, asset, &arrow[i%12], &arrow_dest[i%12]);
		if (highlightActiveRight){
			i+=1;
		}
		if (highlightActiveLeft)
		{
			i-=1;
		}
		if (i <0)
		{
			i+=12;
		}
		return (i%12)+1;
}
bool Game::handleKeyboardEvent(SDL_Event& e) {
    if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
            case SDLK_RIGHT:
				highlightActiveRight = true;
				cout << highlightActiveRight << endl;
                //highlightElements(gRenderer, asset); 
				return false;
                break;
			case SDLK_LEFT:
				highlightActiveLeft = true;
				return false;
				break;
			case SDLK_r:
				rotate = true;
				return false;
				break;
			case SDLK_v:
				showCard = true;
				tick = SDL_GetTicks();
				return false;
				break;
            case SDLK_RETURN:
                //enter key pressed
				cout << "enter pressed\n";
                return true;
                break;
            default:
				return false;
                break;
        }
    }
}
bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;
	
	assets = loadTexture("mazecards.png");
	assets1 = loadTexture("highlightedarrow.png");
    cards1 = loadTexture("1.png");
    cards2 = loadTexture("2.png");
    cards3 = loadTexture("3.png");
	treasureTexture = loadTexture("treasuresallinone.png");
	ShowTreasure = loadTexture("treasurecardsallinone.png");
    gTexture = loadTexture("gamescreen.png");
	if(assets==NULL || gTexture==NULL || cards1==NULL || cards2==NULL || cards3==NULL || treasureTexture == NULL || ShowTreasure == NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	return success;
}

void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(assets);
	assets=NULL;
	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

    // cout path
    cout << path << endl;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    cout << path.c_str() << endl;
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}
void Game::startGame( )
{
	bool enter_key_pressed = false; 
	bool quit = false;
	SDL_Event e;

	board.initializeBoard();
	board.AllocateCards(players);
	Player current = players[0];

	while( !quit )
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}

			if(e.type == SDL_MOUSEBUTTONDOWN){
			
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);
				cout << xMouse << " " << yMouse << endl;
				//createObject(xMouse, yMouse);
			}
			if (e.type == SDL_KEYDOWN) {
                // Handle keyboard events
				//cout << "Keyboard key pressed"<< endl;
                enter_key_pressed = handleKeyboardEvent(e);
				cout << "key pressed\n";
            }
		}

		SDL_RenderClear(gRenderer); //removes everything from renderer
		SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		//***********************draw the objects here********************
		board.DrawBoard(gRenderer, assets, treasureTexture);
		
		int arrow_number = highlightElements(gRenderer, assets1, highlightActiveRight, highlightActiveLeft);
		highlightActiveRight = false;
		highlightActiveLeft = false;
		if(showCard)
		{
			board.showTreasure(current, gRenderer, ShowTreasure);
			if (SDL_GetTicks() >= tick + 2000)
			{
				showCard = false;
			}
		}
		if (rotate)
		{
			board.rotateUsable();
			rotate = false;
		}
		if (enter_key_pressed)
		{
			board.insertMazeCard(arrow_number);
			enter_key_pressed = false;
		}
		//drawObjects(gRenderer, assets);

		//****************************************************************
    	SDL_RenderPresent(gRenderer); //displays the updated renderer

	    SDL_Delay(200);	//causes sdl engine to delay for specified miliseconds
	}
			
}

Game::Game() {
    //Todo: Initialize players with their treasure cards
	
}

// void Game::startGame() {
//Todo: Logic to initialize the game, distribute cards, set up the board
// }

void Game::playTurn() {
    //Todo: Logic for playing a turn, handling player actions, moving pieces, determining the correct move.
}

bool Game::isGameOver() {
    // Todo: Logic to determine if the game is over
    return false;
}

void Game::displayWinner() {
    //Todo: Logic to display the winner of the game
}