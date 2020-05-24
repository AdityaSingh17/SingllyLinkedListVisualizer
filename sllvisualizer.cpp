// Include necessary header files.
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

// NODE structure for linked list.
struct node
{
    int info;
    struct node *link;
};

// Global Variable section.
typedef struct node* NODE;
static NODE first = NULL; // First node of Linked List.
static int count = 0,  flag = 1;
int succ = 1, succ1 = 1, ins_succ = 1;
int choice, item, key;

// Allocate memory for node.
NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if(x == NULL)
    {
            printf("Insufficient memory!!\n");
            exit(0);
    }
    return x;
}

// Display Linked List.
void lldisplay()
{
    NODE temp;
    int k;
    if(first == NULL)
    {
        printf("The list is empty!\n");
        return;
    }
    printf("\nContents of Singly Linked List: \n");
    temp = first;
    while(temp != NULL)
    {
        for(k = 0;k < count;k++)
        { 
            printf("%d", temp->info);
            temp = temp->link;
            printf("\n");
        }
    }
}

// Insert element from Front of Linked list.
NODE  insert_front(int item, NODE first)
{
    NODE temp;
    temp = getnode();
    temp->info = item;
    temp->link = first;
    return temp;
}

// Action on option.
void option(int choice)
{
    switch(choice)
    {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            first = insert_front(item, first);
            count++;
            lldisplay();
            printf("NEW NODE INSERTED\n");
            break;
        case 2: // TODO
            break;
        case 3: // TODO
            break;
        case 4: // TODO
            break;
        case 5: // TODO
            break;   
        case 6: // TODO     
            break;   
        case 7:
            exit(0);
        default:    
            printf("\nWrong option selected, please run the program again!");
    }
}

// Main function.
int main()
{
    int choice;
    while(1)
    {
        printf("\n1. Insert Front");
        /* TODO
        printf("\n2. Insert Rear");
        printf("\n3. Insert Specified");
        printf("\n4. Delete Front");
        printf("\n5. Delete Rear");
        printf("\n6. Delete Specified");
        */
        printf("\n7. Exit");
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        option(choice);
    }
    return 0;
}