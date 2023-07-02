#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define dimTitle 50
#define dimDesc 500

#define fNameIdea "ideasData.bin"

typedef struct{

int id;
char title[dimTitle];
char desc[dimDesc];
char category[dimTitle];
char status[25];

}stIdea;

//prototyped

void addIdea();
void saveIDea(stIdea idea);
int assignID();
void showAllIdeas();
void printIdea(stIdea idea);

void showIdeaByID();
char addTitle();
