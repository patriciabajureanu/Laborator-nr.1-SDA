#include <stdio.h>
typedef struct
{
    char name[50];
    char surname[50];
    char group[50];
    int age;
    int subscription;
} DanceStudent;
void read_dancer(DanceStudent * dancer,int size)
{
    printf("Name: ");
    scanf("%s",dancer->name);
    printf("Surname: ");
    scanf("%s",dancer->surname);
    printf("Group: ");
    scanf("%s",dancer->group);
    printf("Age: ");
    scanf("%d",&dancer->age);
    printf("Subscription: ");
    scanf("%d",&dancer->subscription);
}
void read_array_of_dancers(DanceStudent * dancer, int size)
{printf("Enter dancers data:\n");
    for(int i=0;i<size;i++)
    {
        printf("Dancer %d:\n",i+1);
        read_dancer(&dancer[i],size);
    }
}
void display_dancer(DanceStudent *dancer,int size)
{
    printf("Name:%s\n",dancer->name);
    printf("Surname:%s\n",dancer->surname);
    printf("Group:%s\n",dancer->group);
    printf("Age:%d\n",dancer->age);
    printf("Subscription:%d\n",dancer->subscription);
}
void display_array_of_dancers(DanceStudent *dancer,int size)
{
    printf("Dancers array:\n");
    for(int i=0;i<size;i++)
    {
        printf("Dancer %d:\n",i+1);
        display_dancer(&dancer[i],size);
    }
}
int search(DanceStudent *dancer,int size,char searched_name[50])
{
    int i;
    for(i=0;i<size;i++)
    {if(strcmp(dancer[i].name,searched_name)==0)
        {return i;}
    }return -1;
}
void menu()
{
    printf("Menu:\n");
    printf("1-Read dancers data\n");
    printf("2-Display dancers data\n");
    printf("3-Search for a dancer\n");
    printf("4-Quit\n");
    printf("Enter your choice:");
}
int main()
{
    int size=0,i,k,choice;
    char searched_name[50];
    DanceStudent dancer[size];
    while(1)
    {
    menu();
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
    {
        printf("Enter the number of dancers: ");
        scanf("%d",&size);
        if(size<1)
        {printf("The number of dancers must be higher than 0");
        return 1;}
        read_array_of_dancers(dancer,size);break;}
    case 2:
    {
        display_array_of_dancers(dancer,size);break;}
    case 3:
    {
        printf("Enter the name of the searched dancer:\n");
        scanf("%s", searched_name);
        k=search(dancer, size, searched_name);
        if(k!=-1)
        {printf("The dancer %s was found at position %d\n", searched_name, k+1);
        }else
        {printf("The dancer %s was not found\n", searched_name);}break;}
    case 4:
    {
        printf("exiting the program");return 0;break;}
    default:
    {
        printf("Invalid choice, enter a valid option\n");break;}
    }
    }
    return 0;
}




