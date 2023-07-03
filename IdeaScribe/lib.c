#include "lib.h"


void addIdea()  //Modularizar
{

    stIdea actualIdea;

    actualIdea.id = assignID();
    system("cls");

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

//Mostrar
void showAllIdeas()                 //shows all ideas
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
void showIdeaByID()                 //show Idea by ID
{
    FILE * archive;
    archive = fopen(fNameIdea, "rb");
    stIdea idea;
    int ID;
    system("cls");
    do
    {
        system("cls");
        printf("Ingrese el 0 para volver\n");
        printf("ID a buscar: \n");
        fflush(stdin);
        scanf("%i", &ID);
        if(ID < 0 || ID > maxID())
        {

            system("cls");
            printf("ID invalido / no pertenece a una idea valida\n");
            system("pause");


        }else if(ID == 0){

        break;
        }


    }
    while(ID < 0 || ID > maxID());


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
void printIdea(stIdea idea)         //print an idea received for parameter
{
    printf("--------------------------------------\n");
    printf("ID: %i\n", idea.id);
    printf("Categoria: %s", idea.category);
    printf("Titulo:%s", idea.title);
    printf("Descripcion:\n%s", idea.desc);
    printf("Estado: %s\n", idea.status);
    printf("--------------------------------------\n");
}
int maxID()                         //obtain max id from the file
{
    FILE * archive;
    archive = fopen(fNameIdea, "rb");
    stIdea idea;
    int max = 0;
    if(archive != NULL)
    {
        fseek(archive, sizeof(stIdea) * (-1), SEEK_END);
        fread(&idea, sizeof(stIdea), 1, archive);
        max = idea.id;
        fclose(archive);
    }
    return max;
}

//Modify
void modifyStatus(){






}



//menu
void menuScribe()
{

    int option = 0;

    do
    {
        system("cls");
        printf("Idea Scribe.\n");

        printf("1- Agregar idea\n");
        printf("2- Visualizer Ideas\n");
        printf("3- \n");
        printf("0- Salir\n");
        fflush(stdin);
        scanf("%i", &option);


        switch(option)
        {

        case 1:
            addIdea();
            break;
        case 2:
            visualizerMenu();
            break;
        case 3:

            break;
        case 3107:

            break;
        default:
            if(option == 0)
            {

            }
            else
            {
                system("cls");
                printf("Ingrese una opcion valida");
                system("pause");


            }
            break;
        }
    }
    while(option != 0);


}

void visualizerMenu()
{
    int option = 0;
    do
    {
        system("cls");
        printf("1- Ver todas <%i>\n", maxID());
        printf("2- Ver por ID\n");
        printf("0- Salir\n");
        fflush(stdin);
        scanf("%i", &option);


        switch(option)
        {

        case 1:
            showAllIdeas();
            break;
        case 2:
            showIdeaByID();
            break;
        default:
            if(option == 0)
            {

            }
            else
            {
                system("cls");
                printf("Ingrese una opcion valida");
                system("pause");


            }
            break;
        }
    }
    while(option != 0);



}
