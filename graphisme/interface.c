#include "interface.h"

int interfaceInitialisation(interfaceT * interface)
	{
	assert(SDL_Init(SDL_INIT_VIDEO) == 0);

	(*interface).continu = true;

	assert(SDL_CreateWindowAndRenderer(LARGEUR, LARGEUR, 0, 
				&(*interface).fenetre, &(*interface).rendu) == 0);
	return 0;
	}

int interfaceNettoyage(interfaceT * interface)
	{
	SDL_SetRenderDrawColor((*interface).rendu, 255, 255, 255, SDL_ALPHA_OPAQUE);
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
