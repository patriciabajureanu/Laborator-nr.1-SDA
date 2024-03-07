#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char name[50];
    char surname[50];
    char group[50];
    int age;
    int subscription;
} DanceStudent;
DanceStudent *alocate_memory(int size_of_list)
{
    DanceStudent *dancer=(DanceStudent *)malloc(size_of_list * sizeof(DanceStudent));
    if(dancer==NULL)
    {printf("Memory allocation failed\n");return NULL; return dancer;}
}
void free_memory(DanceStudent *dancer)
{free(dancer);}
void read_dancer(DanceStudent * dancer,int size_of_list)
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
void read_array_of_dancers(DanceStudent *dancer,int size_of_list)
{printf("Enter dancers data:\n");
    for(int index=0;index<size_of_list;index++)
    {
    printf("Dancer %d:\n",index+1);
    read_dancer(&dancer[index],size_of_list);
    }
}
void display_dancer(DanceStudent *dancer,int size_of_list)
{
    printf("Name:%s\n",dancer->name);
    printf("Surname:%s\n",dancer->surname);
    printf("Group:%s\n",dancer->group);
    printf("Age:%d\n",dancer->age);
    printf("Subscription:%d\n",dancer->subscription);
}
void display_array_of_dancers(DanceStudent *dancer,int size_of_list)
{printf("Dancers array:\n");
    for(int index=0;index<size_of_list;index++)
    {
    printf("Dancer %d:\n",index+1);
    display_dancer(&dancer[index],size_of_list);
    }
}
int search(DanceStudent *dancer,int size_of_list,char searched_name[50])
{
    int index;
    for(index=0;index<size_of_list;index++)
    {
        if(strcmp(dancer[index].name,searched_name)==0)
        {return index;}
    }return -1;
}
void sort_by_age(DanceStudent *dancer,int size_of_list)
{
    int index,index2;
    DanceStudent temp;
    for(index=0;index<size_of_list-1;index++)
    {for(index2=index+1;index2<size_of_list;index2++)
    {if(dancer[index].age>dancer[index2].age)
        {
            temp=dancer[index];
            dancer[index]=dancer[index2];
            dancer[index2]=temp;}}}}
void *add_new_dancer_end(DanceStudent *dancer,int *size_of_list)
{
    DanceStudent *tmp_dancer;
    tmp_dancer=(DanceStudent*)realloc(dancer,(*size_of_list+1)*sizeof(DanceStudent));
    if(!tmp_dancer)
    {printf("no reallocation of memory");return NULL;
    }
    printf("Enter new data:\n");
    read_dancer(&tmp_dancer[*size_of_list],1);
    (*size_of_list)++;
}
void *add_new_dancer_front(DanceStudent *dancer,int *size_of_list)
{
    DanceStudent *tmp_dancer;
    tmp_dancer=(DanceStudent*)realloc(dancer,(*size_of_list+1)*sizeof(DanceStudent));
    if(!tmp_dancer)
    {printf("no reallocation of memory");return NULL;
    }
    for(int index=*size_of_list;index>0;index--)
    {tmp_dancer[index]=tmp_dancer[index-1];}
    printf("Enter new data:\n");
    read_dancer(&tmp_dancer[0],1);
    (*size_of_list)++;
}
void add_dancer_at_position(DanceStudent *dancer,int *size_of_list,int position)
{
    printf("Enter new data at position %d:\n", position);
    read_dancer(&dancer[position-1], 1);
}
void *delete_dancer(DanceStudent *dancer,int *size_of_list,int position)
{
    for(int index=position;index<*size_of_list;index++)
    {dancer[index]=dancer[index+1];}
    (*size_of_list)--;
}
void menu()
{
    printf("Menu:\n");
    printf("1-Read dancers data\n");
    printf("2-Display dancers data\n");
    printf("3-Search for a dancer\n");
    printf("4-Sort dancers by age\n");
    printf("5-Add new dancer to end\n");
    printf("6-Add new dancer to front\n");
    printf("7-Add a new dancer at posion\n");
    printf("8-Delete a dancer at posion\n");
    printf("9-Free memory\n");
    printf("10-Quit\n");
    printf("Enter your choice:");
}
int main()
{
    int size_of_list=0,index,k,position,choice;
    char searched_name[50];
    DanceStudent *dancer=NULL;
    while (1)
    {
    menu();
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
    {
        printf("Enter the number of dancers: ");
        scanf("%d",&size_of_list);
        if(size_of_list<1)
            {
                printf("The number of dancers must be higher than 0");continue;}
        dancer=alocate_memory(size_of_list);
        read_array_of_dancers(dancer,size_of_list);break;}
    case 2:
    {
        if(dancer!=NULL)
        {
            display_array_of_dancers(dancer,size_of_list);}
    else
        {
            printf("no data");}
    break;}
    case 3:
    {
        if(dancer!=NULL)
        {
            printf("Enter the name of the searched dancer:\n");
            scanf("%s", searched_name);
            k=search(dancer, size_of_list, searched_name);
            if(k!=-1)
            {
                printf("The dancer %s was found at position %d\n", searched_name, k+1);}
            else
    {printf("The dancer %s was not found\n", searched_name);}
        }
    else{printf("no data");}break;}
    case 4:
    {
        if(dancer!=NULL)
        {
        sort_by_age(dancer,size_of_list);}
        else
        {
        printf("no data");}break;}
    case 5:
    {
        add_new_dancer_front(dancer,&size_of_list);break;}
    case 6:
    {
        add_new_dancer_end(dancer,&size_of_list);break;}
    case 7:
    {
        if(dancer!=NULL)
        {
            printf("Enter the number(position) of dancer to change: ");
            scanf("%d", &position);
            if(position<1||position>size_of_list)
            {
                printf("invalid position\n");}
            else
    {
        add_dancer_at_position(dancer, size_of_list, position);}
    }
    else
    {
        printf("no data\n");}break;}
    case 8:
    {
        if(dancer!=NULL){printf("Enter the position of dancer to delete:");
        scanf("%d",&position);
            if(position<1||position>size_of_list)
            {
            printf("Invalid position\n");}
            else {delete_dancer(dancer,&size_of_list,position-1);
            printf("The dancer was deleted\n");}
        }
        else{printf("no data");}break;}
    case 9:
    {
        if(dancer!=NULL)
        {free_memory(dancer);
        dancer=NULL;
        printf("Free memory\n");}break;}
    case 10:
    {
        printf("exiting the program\n");
        return 0;}
    default:
    {
        printf("Invalid choice, enter a valid option\n");break;}
    }
    }
    return 0;
    }
