/**
* @file functions.h
*/

void initialiser (FILE *fichier,char *chaine, TTF_Font * font,SDL_Color color);
void generation (SDL_Surface *screen,SDL_Surface *textbon,SDL_Surface *textfaux,SDL_Event event,SDL_Rect position);
void choisir(FILE *fichier,TTF_Font * font,SDL_Color color,char *chaine,SDL_Rect position);
