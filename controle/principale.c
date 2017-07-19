#include "../controle/principale.h"

float reelAleatoire(float min, float max) {
    return min + (((float)rand() / (float)(RAND_MAX / (max - min))));
}

int main(int argc, char *argv[]) {
    (void)argc;
    (void)argv;
    
    interfaceT interface;
    
	interfaceInitialisation(&interface);

    srand(time(NULL));
    
    pendule_t p1 = penduleCreation(100, 120, reelAleatoire(0, 1) * PI * 2, (reelAleatoire(0, 1) - 0.5) * 2);
    pendule_t p2 = penduleCreation(100, 120, reelAleatoire(0, 1) * PI * 2, (reelAleatoire(0, 1) - 0.5) * 2);
    points_t p = pointsCreation();
    
    while(interface.continu) {
        while(SDL_PollEvent(&interface.evenement)) {
            if(interface.evenement.type == SDL_QUIT) {
                interface.continu = false;
            }
            
            switch(interface.evenement.type) {
                case SDL_QUIT:
                interface.continu = false;
                break;
                case SDL_KEYDOWN:
                switch(interface.evenement.key.keysym.sym) {
                case SDLK_i:
                    penduleAffiche(p1, 1);
                    penduleAffiche(p2, 2);
                    break;
                }
                break;
            }
        }
    		// Évolution temporelle
        penduleEvolution(&p1, &p2);        

			// Projection angle > entier
        projectionPendules(&p1, &p2, &p);


			// 
	interfaceNettoyage(&interface);
        
        pointsPendules(interface.rendu, p);
        pointsChemin(interface.rendu, p);
        
	interfaceMiseAJour(&interface);
    
        SDL_Delay(5);
    }
    
	interfaceDestruction(&interface);
    return 0;
}
