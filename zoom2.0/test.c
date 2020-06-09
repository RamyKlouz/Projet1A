#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL2/SDL_rotozoom.h"
#include "rotation.h"

/**
* @file test.c
* @brief pour tester la rotation automatique
* @author Ramy Klouz
*
*
*
*/


int main(void){

FILE* fichier=NULL;
char c;
SDL_Surface *screen, *image,*image2, *rotation=NULL;
SDL_Rect position1;
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

rotationgauche(event,image,image2,rotation,screen,position1);


	SDL_Quit();
	pause=getchar();	
	
	return 0;

}

