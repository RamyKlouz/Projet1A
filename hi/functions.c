#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <time.h>
void initialiser (FILE *fichier,SDL_Surface * textenigme, TTF_Font * font,SDL_Color color);
// implementaion 1 (initialisation de l'enigme)
void initialiser (FILE *fichier,SDL_Surface * textenigme, TTF_Font * font,SDL_Color color) {
char chaine[50]="";
if (fichier!=NULL) {
	do{
	c=fgetc(fichier);
	strncat(chaine,&c,1);
	}while (c!=EOF);
	fclose(fichier);
}
textenigme = TTF_RenderText_Solid(font, chaine, color);

}

// implementation 2 (generation de la reponse)
void generation (SDL_Surface *screen,SDL_Surface *textbon,SDL_Surface *textfaux,SDL_Event event,SDL_Rect position){
int cont=1;
while (cont) {

    SDL_WaitEvent(&event);

switch (event.type) {
	case SDL_QUIT:
      cont = 0;
      break;
	case SDL_KEYUP:
      switch (event.key.keysym.sym) {
      case SDLK_a:
	SDL_BlitSurface(textbon, NULL, screen, &position);
          SDL_Flip(screen);
	break;

	case SDLK_b:	
	SDL_BlitSurface(textfaux, NULL, screen, &position);
          SDL_Flip(screen);
	break;}}}

}

// implementation 3 (choix d'enigme aleatoire a partir d'un fichier) +affichage
void choisir(FILE *fichier,TTF_Font * font,SDL_Color color,SDL_Surface *screen,SDL_Rect position){
int newline=0,line;
SDL_Surface * textrand;
    char str[512];
    
    
    srand(time(0));
	line=(rand() % (3-1+1))+1;
       while ( fgets( str, 100, fd ) != NULL ) 
            { 
              newline++;
              if(newline==line)
              {
                textrand=TTF_RenderText_Solid(font, str, color);
		printf("%d",line);
              }
            } 

    
	
		SDL_BlitSurface(textrand, NULL, screen, &position);
          	SDL_Flip(screen);
 	
	fclose(fd);
}

