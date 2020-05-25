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
float color[4][3] = {{1.0, 1.0, 1.0}, {0.8, 0.0, 0.0, }, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.8}};
int drawstringflag = 0, printflag = 1;

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

// Insert element from Rear of Linked list.
NODE insert_rear(int item, NODE first)
{
    NODE temp;   
    NODE cur;
    temp = getnode();
    temp->info = item;
    temp->link = NULL;
    if(first == NULL)
    return temp;
    cur = first;
    while(cur->link != NULL)
        cur = cur->link;
    cur->link = temp;
    return first;
}

// Insert node at a specified position.
NODE insert_specified(int item, NODE first)
{ 
    NODE next, cur, temp;
    temp = getnode();
    temp->info = item;
    if(first == NULL)
    {
        printf("The list is empty! Inserting node at the front...\n");
        temp->link = NULL;
        first = temp;
        return first;
    }
    printf("Enter the key : "); // Key = Node value after which the new node is to be inserted.
    scanf("%d", &key);
    cur = first;       
    while(cur != NULL)
    {
        next = cur->link;
        if(cur->info == key)
        {
            printf("Key found!\n");
            cur->link = temp;
            temp->link = next;
            return first;
        }
            cur = cur->link;
    }
   if(cur == NULL)
    {
        printf("Search unsuccessful!\n");
        count--;
        ins_succ = 0;
    }
    return first;
}

// Delete node from Front of Linked List.
NODE delete_front(NODE first)
{
    NODE temp;
    if(first == NULL)
    {
        printf("The list is empty,  cannot delete!\n");
        count++;
        succ = 0;
        return first;
    }
    temp = first;
    temp = temp->link;
    printf("Deleted item  =  %d \n", first->info);
    free(first);
    return temp;
}

// Delete node from Rear of Linked List.
NODE delete_rear(NODE first)
{
    NODE cur, prev;
    if(first == NULL)
    {
        printf("The list is empty,  cannot delete!\n");
        count++;
        succ = 0;
        return first;
    }
        if(first->link == NULL)
    {
        printf("Item to be deleted is %d \n", first->info);
        free(first);
        return NULL;
    }
    prev = NULL;
    cur = first;
    while(cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }
    printf("Deleted item  =  %d \n", cur->info);
    free(cur);
    prev->link = NULL;
    return first;
}

// Delete a specified node from Linked List.
NODE delete_specified(NODE first)
{
    NODE prev, cur;
    if(first == NULL)
    {
        printf("The list is empty!");
        count++;
        succ = 0;
        return NULL;
    }
    printf("Enter the key: ");
    scanf("%d", &key);
    if(key == first->info)
    {
        cur = first;
        first = first->link;
        free(cur);
        return first;
    }
    prev = NULL;
    cur = first;
    while(cur != NULL)
    {
        if(key == cur->info)
            break;
        prev = cur;
        cur = cur->link;
    }
    if(cur == NULL)
    {
        printf("Search is unsuccessful!\n");
        count++;
        succ1 = 0;
        succ = 0;     
        return first;    
    }
    prev->link = cur->link;
    free(cur);
    return first;
}

// Option menu for Linked List operations.
void sll_menu(int choice)
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
        case 2:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            first = insert_rear(item, first);
            count++;
            lldisplay();
            printf("NEW NODE INSERTED\n");
            break;
        case 3:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item); 
            ins_succ = 1;
            first = insert_specified(item, first);
            count++;
            lldisplay();
            if(!ins_succ)
                printf("KEY NODE DOESN'T EXIST\n");
            else
                printf("NEW NODE INSERTED\n");
            break;
        case 4:
            succ = 1;
            first = delete_front(first);
            count--;
            lldisplay();
            if(succ)
                printf("NODE DELETED\n");
            break;
        case 5:
            succ = 1;
            first = delete_rear(first);
            count--;
            lldisplay();
            if(succ)           
                printf("NODE DELETED\n");
            break;   
        case 6:
            succ = succ1 = 1;
            first = delete_specified(first);
            count--;
            lldisplay();               
            if(succ)
                printf("NODE DELETED\n");
            if(!succ1)
                printf("KEY NODE DOESN'T EXIST\n");  
            break;   
        case 7:
            exit(0);
        default:    
            printf("\nWrong option selected, please run the program again!");
    }
}

// Initialize window properties. 
void init()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
	glMatrixMode(GL_MODELVIEW);
}

// Function to print strings on rendered window.
void drawstring(float x, float y, char *string, int col, int drawstringflag)
{
    char *c;
    glColor3fv(color[col]);
    glRasterPos2f(x, y);
    if (drawstringflag == 0)
    {
        for(c = string; *c != '\0'; c++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
    else
    {
        for(c = string; *c != '\0'; c++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }
    
}

// Title display function.
void title()
{
    glClearColor(192.0, 192.0, 192.0, 1.0);
    drawstring(190.0, 240.0, (char *)"Singly Linked List Visualizer", 1, 0);
    glFlush();
}

// Main function.
int main(int argc, char** argv)
{
    printf("                     SINGLY LINKED LIST                       \n\n");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Singly Linked List Visualizer");
    glutCreateMenu(sll_menu);
    glutAddMenuEntry("Insert Front", 1);
    glutAddMenuEntry("Insert Rear", 2);
    glutAddMenuEntry("Insert Specified", 3);
    glutAddMenuEntry("Delete Front", 4);
    glutAddMenuEntry("Delete Rear", 5);
    glutAddMenuEntry("Delete Specified", 6);
    glutAddMenuEntry("Exit", 7);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(title);
    init();
    glutMainLoop();   
    return 0;
}