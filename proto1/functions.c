/**
* @file functions.c
*/

#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <time.h>
#include "functions.h"


// implementaion 1 (initialisation de l'enigme)

/**
* @brief pour initialiser l'enigme
* @param le fichier contenant l'enigme
* @param la chaine qui recevra l'enigme
* @return rien
*
*/
void initialiser (FILE *fichier,char *chaine) {
char c;
fichier=fopen("enigme.txt","r");
if (fichier!=NULL) {
	do{
	c=fgetc(fichier);
	strncat(chaine,&c,1);
	}while (c!=EOF);
	fclose(fichier);
}


}

// implementation 2 (generation de la reponse)

/**
* @brief pour generer la reponse (vrai/faux)
* @param l'ecran
* @param le text a generer si vrai
* @param le text a generer si faux
* @param l'evenement
* @param la position
* @return rien
*/
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

// implementation 3 (choix d'enigme aleatoire a partir d'un fichier) 

/**
* @brief pour generer une question aleatoire a partir d'un fichier
* @param le fichier en question
* @param la chaine qui contiendra l'enigme
* @return rien
*/
void choisir(FILE *fichier,char *chaine){
int newline=0,line;
    char str[512];
    fichier = fopen("enigmes.txt", "r");
    
    srand(time(0));
	line=(rand() % (3-1+1))+1;
       while ( fgets( str, 100, fichier ) != NULL ) 
            { 
              newline++;
              if(newline==line)
              {
		strcpy(chaine,str);
		printf("%d",line); //Pour verifier srand
              }
            } 

 	
	fclose(fichier);
}

