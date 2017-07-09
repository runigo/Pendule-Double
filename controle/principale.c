#include "../controle/principale.h"

points_t pointsCreation(void)
{
    points_t p;

    p.coord1.x = 0;
    p.coord1.y = 0;
    p.coord2.x = 0;
    p.coord2.y = 0;
    
    return p;
}

int projectionPremierX(pendule_t p1) {
    return (int)(LARGEUR / 2 - sin(p1.theta_actuel) * p1.longueur);
}

int projectionPremierY(pendule_t p1) {
    return (int)(HAUTEUR / 2 + cos(p1.theta_actuel) * p1.longueur);
}

int projectionSecondX(pendule_t p1, pendule_t p2) {
    return (int)(projectionPremierX(p1) - sin(p2.theta_actuel) * p2.longueur);
}

int projectionSecondY(pendule_t p1, pendule_t p2) {
    return (int)(projectionPremierY(p1) + cos(p2.theta_actuel) * p2.longueur);
}

void projectionPendules(pendule_t *p1, pendule_t *p2, points_t *p)
{
    p->coord1.x = (int)projectionPremierX(*p1);
    p->coord1.y = (int)projectionPremierY(*p1);
    
    p->coord2.x = (int)projectionSecondX(*p1, *p2);
    p->coord2.y = (int)projectionSecondY(*p1, *p2);
}

void dessinPendules(SDL_Renderer *rendu, points_t p) {    
    int x1 = p.coord1.x;
    int y1 = p.coord1.y;
    
    int x2 = p.coord2.x;
    int y2 = p.coord2.y;
    
    int xoffset = 1;
    
    SDL_SetRenderDrawColor(rendu, 0, 0, 0, SDL_ALPHA_OPAQUE);

    SDL_Point points1[3] = {
        {LARGEUR/2, HAUTEUR/2},
        {x1,    y1},
        {x2,    y2}
    };
    
    SDL_Point points2[3] = {
        {LARGEUR/2 + xoffset, HAUTEUR/2},
        {x1 + xoffset,    y1},
        {x2 + xoffset,    y2}
    };
    
    SDL_RenderDrawLines(rendu, points1, 3);
    SDL_RenderDrawLines(rendu, points2, 3);
}

void dessinChemin(SDL_Renderer *rendu, points_t p) {
    static SDL_Point point[2048] = {{0}};
    static int       i = 0;
    
    point[i].x = p.coord2.x;
    point[i].y = p.coord2.y;
    
    if(++i > 2048)
        i = 0;
    
    SDL_SetRenderDrawColor(rendu, 0, 0, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLines(rendu, point, i);
}

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
