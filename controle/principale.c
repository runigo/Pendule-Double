#include "../controle/principale.h"

float reelAleatoire(float min, float max) {
    return min + (((float)rand() / (float)(RAND_MAX / (max - min))));
}

int main(int argc, char *argv[]) {
    (void)argc;
    (void)argv;
    
    assert(SDL_Init(SDL_INIT_VIDEO) == 0);
    
    SDL_Window   *fenetre = NULL;
    SDL_Renderer *rendu = NULL;
    SDL_Event     evenement;
    
    bool          continu = true;
 
    assert(SDL_CreateWindowAndRenderer(LARGEUR, LARGEUR, 0, 
                                       &fenetre, &rendu) == 0);
 
    srand(time(NULL));
    
    pendule_t p1 = penduleCreation(100, 120, reelAleatoire(0, 1) * PI * 2, (reelAleatoire(0, 1) - 0.5) * 2);
    pendule_t p2 = penduleCreation(100, 120, reelAleatoire(0, 1) * PI * 2, (reelAleatoire(0, 1) - 0.5) * 2);
    points_t p = pointsCreation();
    
    while(continu) {
        while(SDL_PollEvent(&evenement)) {
            if(evenement.type == SDL_QUIT) {
                continu = false;
            }
            
            switch(evenement.type) {
                case SDL_QUIT:
                continu = false;
                break;
                case SDL_KEYDOWN:
                switch(evenement.key.keysym.sym) {
                case SDLK_a:
                    p1.longueur -= 1;
                    break;
                case SDLK_z:
                    p1.longueur += 1;
                    break;
                case SDLK_e:
                    p2.longueur -= 1;
                    break;
                case SDLK_r:
                    p2.longueur += 1;
                    break;
                case SDLK_q:
                    p1.masse -= 5;
                    break;
                case SDLK_s:
                    p1.masse += 5;
                    break;
                case SDLK_d:
                    p2.masse -= 5;
                    break;
                case SDLK_f:
                    p2.masse += 5;
                    break;
                case SDLK_n:
                    p1 = penduleCreation(100, 120, reelAleatoire(0, 1) * PI * 2, (reelAleatoire(0, 1) - 0.5) * 2);
                    p2 = penduleCreation(100, 120, reelAleatoire(0, 1) * PI * 2, (reelAleatoire(0, 1) - 0.5) * 2);
                    break;
                case SDLK_i:
                    penduleAffiche(p1, 1);
                    penduleAffiche(p2, 2);
                    break;
                }
                break;
            }
        }
    
        penduleEvolution(&p1, &p2);        
       
        projectionPendules(&p1, &p2, &p);
        
        SDL_SetRenderDrawColor(rendu, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(rendu);
        
        dessinPendules(rendu, p);
        dessinChemin(rendu, p);
        
        SDL_RenderPresent(rendu);
    
        SDL_Delay(5);
    }
    
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(fenetre);
    
    SDL_Quit();
    return 0;
}
