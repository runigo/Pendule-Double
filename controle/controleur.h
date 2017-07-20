#ifndef _CONTROLEUR_
#define _CONTROLEUR_

#include "../projection/projection.h"

typedef struct ControleurT controleurT;
struct ControleurT {
	interfaceT interface;
};


int controleurInitialisation(controleurT * controleur);

int controleurSimulation(controleurT * controleur);

int controleurDestruction(controleurT * controleur);

#endif
