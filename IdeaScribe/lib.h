#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define dimTitle 50
#define dimDesc 500

#define fileNameIdea "ideasData.bin"

typedef struct{

int id;
char title[dimTitle];
char desc[dimDesc];
char category[];

}stIdea;

//prototyped

void addIdea();
void saveIDea(stIdea idea);
int assignID();
void showAllIdeas();
void printIdea(stIdea idea);

