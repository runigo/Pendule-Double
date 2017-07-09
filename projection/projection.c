#include "../projection/projection.h"

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

