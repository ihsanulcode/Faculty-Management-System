#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure - Menon pranto
struct faculty
{
    char name[50];
    char initial[50];
    char course[50];
    char time[50];
    char room[50];
};

void ADD();
void LIST();
void SEARCH();

//main function - Ihsanul Haque Asif
int main(void)
{


main:

    system("cls");

    printf("\n\t **** Welcome to Faculty Management System ****");
    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add\n\t\t[2] Search\n\t\t[3] List faculty\n\t\t[0] Exit\n\t\t=================\n\t\t");

    printf("Enter the choice: ");
    int n;
    scanf("%d",&n);

    switch(n)
    {
        case 0:
            printf("\n\n\t\tAre you sure you want to exit?");
            break;

        case 1:
            ADD(); //ADD Function - Ihsanul Haque Asif
            break;
        case 2:
            SEARCH(); //SEARCH Function - Menon Pranto
            break;
        case 3:
            LIST(); //LIST Function - Sarwar Khalid
            break;

        default:
             printf("Invalid choice!");
             break;
    }

    printf("\n\n\t\t::::Enter the Choice:\n\n\t\t[1] Main Menu\n\t\t[0] Exit\n");
    int ch;
    scanf("%d",&ch);

    switch (ch)

    {
        case 1:
            goto main;
        case 0:
            break;
        default:
            printf("Invalid choice!");
            break;
    }
    return 0;



}

//ADD Function - Ihsanul Haque Asif
void ADD()
{

    system("cls");
    int n;
    printf("How many faculty's info you want to add?\n");
    scanf("%d",&n);
    struct faculty f[n];

    FILE *faculty;
    faculty = fopen("info.txt","a");
    if(faculty == NULL){
         printf("\nFile not found!\n");
         exit(1);
    }


    printf("\n----- Insert faculty info -----\n");
    int i;
    for(i=0;i<n;i++)
    {
        printf("Faculty #%d\n",i+1);

        fflush(stdin);
        printf("Name: ");
        scanf("%[^\n]",f[i].name);
        fflush(stdin);


        printf("Initial: ");
         scanf("%[^\n]",f[i].initial);
        fflush(stdin);


        printf("course name: ");
         scanf("%[^\n]",f[i].course);
        fflush(stdin);


        printf("Time: ");
         scanf("%[^\n]",f[i].time);
        fflush(stdin);


        printf("Room no: ");
         scanf("%[^\n]",f[i].room);
        fflush(stdin);

        printf("\n");

        fprintf(faculty, "%s\n%s\n%s\n%s\n%s\n",f[i].name,f[i].initial,f[i].course,f[i].time,f[i].room);

    }
    fclose(faculty);

}

//LIST Function - Sarwar Khalid
void LIST()
{
    system("cls");
    FILE* ptr = fopen("info.txt","r");


    struct faculty fac;
    while((fgets(fac.name,50,ptr))!=NULL)
    {

        fgets(fac.initial,50,ptr);
        fgets(fac.course,50,ptr);
        fgets(fac.time,50,ptr);
        fgets(fac.room,50,ptr);

        printf("-------------------------------------\n");

        printf("Name: %s",fac.name);
        printf("Initial: %s",fac.initial);
        printf("Course: %s",fac.course);
        printf("Time: %s",fac.time);
        printf("Room: %s",fac.room);


    }
    fclose(ptr);

    return;

}

//SEARCH Function - Menon Pranto
void SEARCH()
{
    system("cls");
    struct faculty f;
    char Name[60];
    {
    FILE *fp;
    fp = fopen("info.txt","r");
    if (fp==NULL)       //Change the name
    {
        printf("Error! File not found.");
    }
    else
    {
        fflush(stdin);
        printf("Enter the name you want to search: ");
        fgets(Name,60,stdin);
        system("cls");
        fflush(stdin);
            while((fgets(f.name,50,fp))!=NULL)
        {


            fgets(f.initial,50,fp);
            fgets(f.course,50,fp);
            fgets(f.time,50,fp);
            fgets(f.room,50,fp);


            if (strcmp(Name,f.name)==0)
            {
                printf("Name: %sInitial: %sCourse: %sTime: %sRoom: %s",f.name,f.initial,f.course,f.time,f.room);
                fclose(fp);
                return;
            }

        }
        fclose(fp);


            printf("Name not found in the directory.");

    }
}




}
