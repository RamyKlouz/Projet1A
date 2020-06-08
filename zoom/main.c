#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL2/SDL_rotozoom.h"

/**
* @file main.c
* @brief prog test
* @author Ramy Klouz
*
* Programme pour tester la fonction rotozoomSurface()
*
*/


int main(void){

FILE* fichier=NULL;
char c;
double angle=0,zooming=1.0;
SDL_Surface *screen, *image,*image2, *rotation=NULL;
SDL_Rect position1;
int cont=1;
SDL_Event event;

SDL_Init(SDL_INIT_VIDEO);
char pause;
position1.x = 200;
position1.y = 200;


screen = SDL_SetVideoMode (800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
if (screen==NULL){
    printf ("unable to set video mode: %s\n",SDL_GetError());
    return 1;
    }


     image = IMG_Load("bgg.jpg");
        if (image==NULL){
        printf ("Unable to load Bitmap:%s\n",SDL_GetError());
        return 1;
    }
	SDL_BlitSurface(image,NULL,screen,NULL);
	SDL_Flip(screen); 




image2=IMG_Load("PLAY.png");
SDL_BlitSurface(image2, NULL, screen, & position1);
SDL_Flip(screen);


while (cont)
{
	SDL_WaitEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
      	cont = 0;
     	 break;
	case SDL_KEYUP:
     	 switch (event.key.keysym.sym) {
	case SDLK_a: //rotation a gauche
	angle+=30;
	rotation=rotozoomSurface(image2,angle,zooming,1);
	SDL_BlitSurface(image,NULL,screen,NULL);
	SDL_BlitSurface(rotation, NULL, screen, & position1);	
	SDL_FreeSurface(rotation);
        SDL_Flip(screen);
	break;
	case SDLK_b:  //rotation a droite
	angle-=30;
	rotation=rotozoomSurface(image2,angle,zooming,1);
	SDL_BlitSurface(image,NULL,screen,NULL);
	SDL_BlitSurface(rotation, NULL, screen, & position1);
	SDL_FreeSurface(rotation);
        SDL_Flip(screen);
	break;
	case SDLK_c:  //zoom
	zooming*=2;
	rotation=rotozoomSurface(image2,angle,zooming,1);
	SDL_BlitSurface(image,NULL,screen,NULL);
	SDL_BlitSurface(rotation, NULL, screen, & position1);
	SDL_FreeSurface(rotation);
        SDL_Flip(screen);
	break;
	case SDLK_d:  //unzoom
	zooming *=0.5;
	rotation=rotozoomSurface(image2,angle,zooming,1);
	SDL_BlitSurface(image,NULL,screen,NULL);
	SDL_BlitSurface(rotation, NULL, screen, & position1);
	SDL_FreeSurface(rotation);
        SDL_Flip(screen);
	break;
	default:
	break;}}
	
}

	SDL_Quit();
	pause=getchar();	
	
	return 0;

}

