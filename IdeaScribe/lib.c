#include "lib.h"


void addIdea()                      //add a Idea
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
void saveIDea(stIdea idea)          //add idea to archive, if doesnt exist, is created
{
    FILE * archive;
    archive = fopen(fNameIdea, "ab");

    if(archive != NULL)
    {
        fwrite(&idea, sizeof(stIdea), 1, archive);
        fclose (archive);
    }
}
//printFunction
void showIdeaByID()                 //show Idea by ID
{
    FILE * archive;
    archive = fopen(fNameIdea, "rb");
    stIdea idea;
    int ID;
    system("cls");

        ID = selectID();

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
        else
        {
            system("cls");
            printf("No hay ideas cargadas\n");
            system("pause");
        }
    }
void showAllIdeas()                 //shows all ideas
{

    FILE * archive;
    archive = fopen(fNameIdea, "rb");
    stIdea idea;

    if(archive != NULL)         //archive exist?
    {
        if(maxID() > 0)         //second validation
        {
            system("cls");
            while(fread(&idea, sizeof(stIdea), 1, archive) > 0)
            {
                printIdea(idea);
            }
            system("pause");
        }

        fclose(archive);
    }
    else
    {

        system("cls");
        printf("No hay ideas cargadas\n");
        system("pause");
    }
}
void printIdea(stIdea idea)         //print an idea received for parameter
{
    printf("--------------------------------------\n");
    printf("| ID: %i\n", idea.id);
    printf("| Titulo: %s", idea.title);
    printf("| Estado: %s\n", idea.status);
    printf("| Categoria: %s", idea.category);
    printf("| Descripcion:\n > %s", idea.desc);
    printf("--------------------------------------\n");
}

//Modify
void modifyStatus()                 //modify State of Idea
{
    FILE * archive;
    int ID = 0;
    int option = 0;
    stIdea idea;
    archive = fopen(fNameIdea, "r+b");

    if(archive != NULL)
    {
        ID = selectID();
        if(ID != 0)
        {
            while(fread(&idea, sizeof(stIdea),1,archive)>0)
            {
                if(ID == idea.id)
                {
                    fseek(archive, sizeof(stIdea)* -1, SEEK_CUR);
                    break;
                }
            }
            do
            {
                system("cls");
                printIdea(idea);
                printf("\n");
                printf("> Cambiar a: \n");
                printf("1- En concepto. \n");
                printf("2- En proceso. \n");
                printf("3- Finalizado. \n");
                printf("0- Salir. \n>:");
                scanf("%i", &option);

                switch(option)
                {
                case 1:
                    strcpy(idea.status, "En concepto.");
                    break;
                case 2:
                    strcpy(idea.status, "En proceso.");
                    break;
                case 3:
                    strcpy(idea.status, "Finalizado.");
                    break;
                default:
                    if(option == 0)
                    {
                        break;
                    }
                    else
                    {
                        system("cls");
                        printf("Opcion invalida.");
                        system("pause");
                    }
                    break;
                }
            }
            while(option < 0 || option > 3);

            if(option != 0)
            {
                fwrite(&idea, sizeof(stIdea), 1, archive);
            }
        }
        fclose(archive);
    }



}
void modifyTitle()                  //modify Title of Idea
{
    FILE * archive;
    int ID = 0;
    int option = 0;
    stIdea idea;
    archive = fopen(fNameIdea, "r+b");

    if(archive != NULL)
    {

        ID = selectID();

        while(fread(&idea, sizeof(stIdea),1,archive)>0)
        {

            if(ID == idea.id)
            {
                fseek(archive, sizeof(stIdea)* -1, SEEK_CUR);
                break;
            }

        }

        printIdea(idea);

        printf("Titulo: ");
        fflush(stdin);
        fgets(idea.title, dimTitle, stdin);


        fwrite(&idea, sizeof(stIdea), 1, archive);

        fclose(archive);
    }
}
void modifyDesc()                   //modify Desc of Idea
{
    FILE * archive;
    int ID = 0;
    int option = 0;
    stIdea idea;
    archive = fopen(fNameIdea, "r+b");

    if(archive != NULL)
    {

        ID = selectID();

        while(fread(&idea, sizeof(stIdea),1,archive)>0)
        {

            if(ID == idea.id)
            {
                fseek(archive, sizeof(stIdea)* -1, SEEK_CUR);
                break;
            }

        }

        printIdea(idea);

        printf("Descripcion: ");
        fflush(stdin);
        fgets(idea.desc, dimDesc, stdin);


        fwrite(&idea, sizeof(stIdea), 1, archive);

        fclose(archive);
    }
}
void modifyCat()                    //modify Category of Idea
{
    FILE * archive;
    int ID = 0;
    int option = 0;
    stIdea idea;
    archive = fopen(fNameIdea, "r+b");

    if(archive != NULL)
    {

        ID = selectID();

        while(fread(&idea, sizeof(stIdea),1,archive)>0)
        {

            if(ID == idea.id)
            {
                fseek(archive, sizeof(stIdea)* -1, SEEK_CUR);
                break;
            }

        }

        printIdea(idea);

        printf("Categoria: ");
        fflush(stdin);
        fgets(idea.category, dimTitle, stdin);


        fwrite(&idea, sizeof(stIdea), 1, archive);

        fclose(archive);
    }
}

//IDs Functions
int selectID()    //Return a valid ID select by user
{
    int ID = 0;
    int max = maxID();

    do
    {
        if(max != 0)
        {
            system("cls");
            printf("Ingrese el 0 para volver\n");
            printf("ID a buscar: \n");
            fflush(stdin);
            scanf("%i", &ID);
            if(ID < 0 || ID > max)
            {
                system("cls");
                printf("ID invalido / no pertenece a una idea valida\n");
                system("pause");
            }
        }
        else if(ID == 0)
        {
            break;
        }
    }
    while(ID < 0 && ID > max);
    return ID;
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
int assignID()                      //returns last ID.
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
//menu
void menuScribe()
{

    int option = 0;

    do
    {
        system("cls");
        titleDisplay();


        printf("1- Agregar idea\n");
        printf("2- Visualizer Ideas\n");
        printf("3- Editar Ideas\n");
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
            editorMenu();

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
void editorMenu()
{
    int option = 0;
    do
    {
        system("cls");

        printf("1- Modificar Titulo \n");
        printf("2- Modificar Estado\n" );
        printf("3- Modificar Descripcion- \n");
        printf("4- Modificar Categoria \n");
        printf("0- Salir\n");
        fflush(stdin);
        scanf("%i", &option);


        switch(option)
        {

        case 1:
            modifyTitle();
            break;
        case 2:
            modifyStatus();
            break;
        case 3:
            modifyDesc();
            break;
        case 4:
            modifyCat();
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
void titleDisplay(){

    printf("  _____       _                     _____                 _   _            \n");
    printf(" |_   _|     | |                   / ____|               (_) | |           \n");
    printf("   | |     __| |   ___    __ _    | (___     ___   _ __   _  | |__     ___ \n");
    printf("   | |    / _` |  / _ \\  / _` |    \\___ \\   / __| | '__| | | | '_ \\   / _ \\\n");
    printf("  _| |_  | (_| | |  __/ | (_| |    ____) | | (__  | |    | | | |_) | |  __/\n");
    printf(" |_____|  \\__,_|  \\___|  \\__,_|   |_____/   \\___| |_|    |_| |_.__/   \\___|\n");
    printf("                                                                          \n");
    printf("                                                           by Eloy Roldan.\n");
    printf("                                                                          \n");
    printf("                                                                          \n");
    printf("                                                                          \n");

}
