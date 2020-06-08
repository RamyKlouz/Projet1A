#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <time.h>
int main(void){

FILE* fichier=NULL;
char c;
SDL_Surface *screen;
SDL_Surface *image;
SDL_Rect position1;
SDL_Rect position2;
SDL_Rect position3;
int cont=1;
SDL_Event event;

SDL_Init(SDL_INIT_VIDEO);
TTF_Init();
char pause;
TTF_Font * font = TTF_OpenFont("pixels.ttf", 30);
SDL_Surface * textenigme;
SDL_Surface * textbon;
SDL_Surface * textfaux;

SDL_Color color = {
    200,
    200,
    0
  };
SDL_Color color2 = {
    200,
    200,
    200
  };
position1.x = 50;
position1.y = 200;
position2.x = 200;
position2.y = 400;
position3.x = 50;
position3.y = 300;

textbon = TTF_RenderText_Solid(font, "bonne reponse!", color);
textfaux = TTF_RenderText_Solid(font, "mauvaise reponse!", color);

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


SDL_FreeSurface(image);
// implementaion 1 (initialisation de l'enigme)
fichier=fopen("enigme.txt","r");
initialiser (&fichier,&textenigme,&font,&color);
textenigme = TTF_RenderText_Solid(font, chaine, color);

/*
SDL_BlitSurface(textenigme, NULL, screen, &position1); //affichage pour verifier
SDL_Flip(screen);
// implementation 3 (choix d'enigme aleatoire a partir d'un fichier)
int newline=0,line;
SDL_Surface * textrand;
    char str[512];
    FILE *fd = fopen("enigmes.txt", "r");
    
    srand(time(0));
	line=(rand() % (3-1+1))+1;
       while ( fgets( str, 100, fd ) != NULL ) 
            { 
              newline++;
              if(newline==line)
              {
                textrand=TTF_RenderText_Solid(font, str, color2);
		printf("%d",line);
              }
            } 

    
	
		SDL_BlitSurface(textrand, NULL, screen, &position3);
          	SDL_Flip(screen);
 	
	fclose(fd);
// implementation 2 (generation de la reponse)
while (cont) {

    SDL_WaitEvent(&event);

switch (event.type) {
	case SDL_QUIT:
      cont = 0;
      break;
	case SDL_KEYUP:
      switch (event.key.keysym.sym) {
      case SDLK_a:
	SDL_BlitSurface(textbon, NULL, screen, &position2);
          SDL_Flip(screen);
	break;

	case SDLK_b:	
	SDL_BlitSurface(textfaux, NULL, screen, &position2);
          SDL_Flip(screen);
	break;}}}

	pause=getchar();	
	return 0;

}
*/
