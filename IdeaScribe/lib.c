#include "lib.h"


void addIdea(){

    stIdea actualIdea;

    actualIdea.id = assignID();
    printf("Titulo: ");
    gets(&actualIdea.title);
    printf("Desc: ");
    gets(&actualIdea.desc);
    printf("Categoria: ");
    gets(&actualIdea.category);

    saveIDea(actualIdea);

}

void saveIDea(stIdea idea)
{
    FILE * archive;
    archive = fopen(fileNameIdea, "ab");

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
    archive = fopen(fileNameIdea, "rb");

    if(archive != NULL)
    {
        fseek(archive, sizeof(stIdea) * -1, SEEK_END);
        fread(&lastIdea, sizeof(stIdea), 1, archive);
        ID = lastIdea.id + 1;
        fclose (archive);
    }



    return ID;
}


void showAllIdeas()
{

    FILE * archive;
    archive = fopen(fileNameIdea, "rb");
    stIdea idea;
    if(archive != NULL)
    {


        while(fread(&idea, sizeof(stIdea), 1, archive) > 0)
        {
            printIdea(idea);
        }
        fclose(archive);
    }
}
void printIdea(stIdea idea)
{

    printf("ID: %i\n", idea.id);
    printf("Categoria: %s\n", idea.category);
    printf("Titulo:%s\n", idea.title);
    printf("Descripscion:\n%s\n", idea.desc);
    printf("--------------------------------------\n");
}

