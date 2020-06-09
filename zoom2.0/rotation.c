/**
*@file rotation.c
*/

#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL2/SDL_rotozoom.h"
#include "rotation.h"


/**
*@brief fonction de la rotation a gauche
*@param evenement
*@param background
*@param image qui va subir la rotation
*@param rotation
*@param l'ecran
*@param position
*@rien
*
*/
void rotationgauche(SDL_Event event, SDL_Surface *image, SDL_Surface *image2,SDL_Surface *rotation,SDL_Surface *screen, SDL_Rect position1){
int lasttime=0,currenttime=0, angle=0, cont=1;

while (cont)
{
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
      	cont = 0;
     	 break;
	}

	currenttime=SDL_GetTicks();
	if (currenttime-lasttime > 20){//20: le temps entre chaque incrementation
	angle+=4;
	lasttime=currenttime;
	}else
	SDL_Delay(20- (currenttime-lasttime));
	rotation=rotozoomSurface(image2,angle,1.0,1);
	SDL_BlitSurface(image,NULL,screen,NULL);
	SDL_BlitSurface(rotation, NULL, screen, & position1);
	SDL_FreeSurface(rotation);
	SDL_Flip(screen);
}
}

/**
*@brief fonction de la rotation a droite
*@param evenement
*@param background
*@param image qui va subir la rotation
*@param rotation
*@param l'ecran
*@param position
*@rien
*
*/
void rotationdroite(SDL_Event event, SDL_Surface *image, SDL_Surface *image2,SDL_Surface *rotation,SDL_Surface *screen, SDL_Rect position1){
int lasttime=0,currenttime=0, angle=0, cont=1;

while (cont)
{
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
      	cont = 0;
     	 break;
	}

	currenttime=SDL_GetTicks();
	if (currenttime-lasttime > 20){//20: le temps entre chaque incrementation
	angle-=4; // - plutot que + pour droite
	lasttime=currenttime;
	}else
	SDL_Delay(20- (currenttime-lasttime));
	rotation=rotozoomSurface(image2,angle,1.0,1);
	SDL_BlitSurface(image,NULL,screen,NULL);
	SDL_BlitSurface(rotation, NULL, screen, & position1);
	SDL_FreeSurface(rotation);
	SDL_Flip(screen);
}
}
