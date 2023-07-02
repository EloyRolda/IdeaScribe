#include "lib.h"


void addIdea(){ //Modularizar

    stIdea actualIdea;

    actualIdea.id = assignID();

    printf("Titulo: ");
    fflush(stdin);
    fgets(actualIdea.title, dimTitle, stdin);

    printf("Desc: ");
    fflush(stdin);
    fgets(actualIdea.desc, dimDesc, stdin);

    printf("Categoria: ");
    fflush(stdin);
    fgets(actualIdea.category, dimTitle, stdin);

    strcpy(actualIdea.status, "En concepto");
    saveIDea(actualIdea);

}

void saveIDea(stIdea idea)
{
    FILE * archive;
    archive = fopen(fNameIdea, "ab");

    if(archive != NULL)
    {
        fwrite(&idea, sizeof(stIdea), 1, archive);
        fclose (archive);
    }
}
int assignID()      //returns last ID.
{
    int ID = 1;
    stIdea lastIdea;
    FILE * archive;
    archive = fopen(fNameIdea, "rb");

    if(archive != NULL)
    {
        fseek(archive, sizeof(stIdea) * -1, SEEK_END);
        fread(&lastIdea, sizeof(stIdea), 1, archive);
        ID = lastIdea.id + 1;
        fclose (archive);
    }
    return ID;
}

void showAllIdeas()         //shows all ideas
{

    FILE * archive;
    archive = fopen(fNameIdea, "rb");
    stIdea idea;
    if(archive != NULL)
    {
        system("cls");
        while(fread(&idea, sizeof(stIdea), 1, archive) > 0)
        {
            printIdea(idea);
        }
        system("pause");
        fclose(archive);
    }
}

void showIdeaByID()          //show Idea by ID
{
    FILE * archive;
    archive = fopen(fNameIdea, "rb");
    stIdea idea;
    int ID;

    do
    {
        system("cls");
        printf("Ingrese el ID de la idea a imprimir\n");
        fflush(stdin);
        scanf("%i", &ID);
        if(ID <= 0 || ID > maxID())
        {

            system("cls");
            printf("ID invalido / no pertenece a una idea valida\n");
            system("pause");


        }


    }
    while(ID <= 0 || ID > maxID());


    if(archive != NULL)
    {
        while(fread(&idea, sizeof(stIdea), 1, archive) > 0)
        {
            if(idea.id == ID)
            {
                printIdea(idea);
                system("pause");
                break;
            }
        }
        fclose(archive);
    }
}

void printIdea(stIdea idea)     //print an idea received for parameter
{
    printf("--------------------------------------\n");
    printf("ID: %i\n", idea.id);
    printf("Categoria: %s", idea.category);
    printf("Titulo:%s", idea.title);
    printf("Descripcion:\n%s", idea.desc);
    printf("Estado: %s\n", idea.status);
    printf("--------------------------------------\n");
}

int maxID()
{
    FILE * archive;
    archive = fopen(fNameIdea, "rb");
    stIdea idea;
    int max = 0;
    if(archive != NULL)
    {
        fread(&idea, sizeof(stIdea), 1, archive);
        fseek(archive, sizeof(stIdea) * -1, SEEK_END);
        max = idea.id;
        fclose(archive);
    }
    return max;
}
