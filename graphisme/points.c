#include "points.h"

points_t pointsCreation(void)
{
    points_t p;

    p.coord1.x = 0;
    p.coord1.y = 0;
    p.coord2.x = 0;
    p.coord2.y = 0;
    
    return p;
}

void pointsPendules(SDL_Renderer *rendu, points_t p) {    
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


    // Affiche une BMP avec le coin en haut à gauche du renderer ren, en 0,0

  //SDL_Texture * texture = 0;
  SDL_Rect dst;
 
    //texture = SDLS_loadTexture("particule.bmp",rendu);
    //SDL_Texture* SDLS_loadTexture(char * filename, SDL_Renderer *ren){
        SDL_Texture *texture = 0;
        SDL_Surface *loadedImage = 0;
        loadedImage = SDL_LoadBMP("particule.bmp");
        if (!loadedImage)
          {
          fprintf(stderr,"Erreur chargement image : %s\n",SDL_GetError());
          return;
          }
 
        texture = SDL_CreateTextureFromSurface(rendu, loadedImage);
        SDL_FreeSurface(loadedImage);
        if (texture == 0)
          {
          fprintf(stderr,"Erreur creation texture : %s\n",SDL_GetError());
          return;
          }
        //return texture;

  //if (texture == 0) return;
 
  // Récupération de la taille de la texture 
  //SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
 
    //SDLS_affiche_image("particule.bmp",rendu,x1-2,y1-2);
    //SDLS_affiche_image("particule.bmp",rendu,x2-2,y2-2);

  // Centrage
  dst.x = x2-2; //(WIDTH - dst.w)/2;
  dst.y = y2-2; //(HEIGHT- dst.h)/2;
 
  // Affichage
  SDL_RenderCopy(rendu, texture, NULL, &dst);
  // Centrage
  dst.x = x1-2; //(WIDTH - dst.w)/2;
  dst.y = y1-2; //(HEIGHT- dst.h)/2;
 
  // Affichage
  SDL_RenderCopy(rendu, texture, NULL, &dst);
  //SDL_RenderPresent(ren);

  return;
}

void pointsChemin(SDL_Renderer *rendu, points_t p) {
    static SDL_Point point[2048] = {{0}};
    static int       i = 0;
    
    point[i].x = p.coord2.x;
    point[i].y = p.coord2.y;
    
    if(++i > 2048)
        i = 0;
    
    SDL_SetRenderDrawColor(rendu, 0, 0, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLines(rendu, point, i);
}

