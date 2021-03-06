#include "interface.h"

int interfaceInitialisation(interfaceT * interface)
	{
	assert(SDL_Init(SDL_INIT_VIDEO) == 0);

	(*interface).continu = true;
	(*interface).fond = 255;

	// Création fenêtre et rendu
	//assert(SDL_CreateWindowAndRenderer(LARGEUR, LARGEUR, 0, &(*interface).fenetre, &(*interface).rendu) == 0);

	// Création de la fenêtre
	(*interface).fenetre = SDL_CreateWindow("Pendule double", SDL_WINDOWPOS_UNDEFINED, 
							SDL_WINDOWPOS_UNDEFINED, LARGEUR, LARGEUR, 
							SDL_WINDOW_RESIZABLE);

	// Création du rendu
	(*interface).rendu = SDL_CreateRenderer((*interface).fenetre, -1 , 
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


	//void SDL_GetWindowSize(SDL_Window* window , int* w , int* h);
	//la taille de la fenêtre sera placée dans les pointeurs w et h

	return 0;
	}

int interfaceNettoyage(interfaceT * interface)
	{
	int fond = (*interface).fond;
	SDL_SetRenderDrawColor((*interface).rendu, fond, fond, fond, SDL_ALPHA_OPAQUE);
	SDL_RenderClear((*interface).rendu);
	return 0;
	}

int interfaceMiseAJour(interfaceT * interface)
	{
	SDL_RenderPresent((*interface).rendu);
	return 0;
	}

int interfaceDestruction(interfaceT * interface)
	{
	SDL_DestroyRenderer((*interface).rendu);
	SDL_DestroyWindow((*interface).fenetre);
	SDL_Quit();
	return 0;
	}
