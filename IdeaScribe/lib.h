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

void addIdea();                    // Agrega una nueva idea
void saveIDea(stIdea idea);        // Guarda una idea en el archivo
void showIdeaByID();               // Muestra una idea por su ID
void showAllIdeas();               // Muestra todas las ideas
void printIdea(stIdea idea);       // Imprime los detalles de una idea
void modifyStatus();               // Modifica el estado de una idea
void modifyTitle();                // Modifica el título de una idea
void modifyDesc();                 // Modifica la descripción de una idea
void modifyCat();                  // Modifica la categoría de una idea
int selectID();                    // Devuelve un ID válido seleccionado por el usuario
int maxID();                       // Obtiene el ID máximo del archivo
int assignID();                    // Devuelve el último ID asignado
void menuScribe();                 // Muestra el menú principal
