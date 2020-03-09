#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node
{
    int val;
    int a;
    struct Node *next;
} node;

node *food=NULL;
node *order_food=NULL;
node *served_food=NULL;

typedef struct fname
{
    char name[300];
} hotel;

hotel f[7];

int global;

void food_list()
{
    int a;
    printf("1. BURGER\t\t2. Chicken fry\n\n3. PIZZA\t\t4. NACHOS\n\n5. COFFEE\t\t6. DEW\n\n7. back\n");
    printf("Enter your chose: ");
    scanf("%d",&a);
    system("cls");
    if(a<7)
    {
        food_ditels(a);
        system("cls");
        return;
    }
    else
    {
        return;
    }
}

void create_food(int val, int j)
{
    if(food==NULL)
    {
        food=malloc(sizeof(node));
        food->val=val;
        food->a=j;
        food->next=NULL;
        return;
    }
    node *temp=food;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=malloc(sizeof(node));
    temp->next->val=val;
    temp->next->a=j;
    temp->next->next=NULL;
}

void order_F(int val, int j)
{
    if(order_food==NULL)
    {
        order_food=malloc(sizeof(node));
        order_food->val=val;
        order_food->a=j;
        order_food->next=NULL;
        return;
    }
    node *temp=order_food;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=malloc(sizeof(node));
    temp->next->val=val;
    temp->next->a=j;
    temp->next->next=NULL;
}

int serve_food()
{
    int retrive;
    node *temp=food->next;
    retrive=food->val;
    global=food->a;
    free(food);
    food=temp;
    serve_F(retrive);
    return retrive;

}

void serve_F(int val)
{
    int j=global;
    if(served_food==NULL)
    {
        served_food=malloc(sizeof(node));
        served_food->val=val;
        served_food->a=j;
        served_food->next=NULL;
        return;
    }
    node *temp=served_food;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=malloc(sizeof(node));
    temp->next->val=val;
    temp->next->a=j;
    temp->next->next=NULL;
}

int food_ditels(int i)
{
    int a,b,c;
    strcpy(f[0].name,"NO FOOD\n");
    strcpy(f[1].name,"number 1 Food Name: BURGER.\nSIZE: 10 cm\nQuantity: 100 gm\n");
    strcpy(f[2].name,"number 2 Food Name: Chicken fry.\nSIZE: 1 small bucket\nQuantity: 4 pices\n");
    strcpy(f[3].name,"number 3 Food Name: PIZZA\nSIZE: single pack\nQuantity: 150gm\n");
    strcpy(f[4].name,"number 4 Food Name: NACHOS\nSIZE: full pack\nQuantity:  250gm\n");
    strcpy(f[5].name,"number 5 Food Name: COFFEE\nSIZE: 1 CUP\nQuantity: 150ml\n");
    strcpy(f[6].name,"number 6 Food Name: DEW\nSIZE: 1 BOTTLE\nQuantity: 400ml\n");
    printf("%s\n",f[i].name);
    printf("1. Do you want to order\t\t 2. Back\nEnter your choice: ");
    scanf("%d",&a);
    system("cls");
    if(a==1)
    {
        printf("How many order you want?\n");
        scanf("%d",&c);
        printf("Thanks for ordering\n\nPress 0 to back\n");
        scanf("%d",&b);
        system("cls");
        create_food(i,c);
        order_F(i,c);
        return;

    }
    else if(a==2)
    {
        system("cls");
        return 0;
    }
    else
    {
        system("cls");
        return 0;
    }
}

void food_ditels2(int i)
{
    strcpy(f[0].name,"No food\n");
    strcpy(f[1].name,"number 1 Food Name: BURGER\nSIZE: 10cm\nQuantity: 100gm ");
    strcpy(f[2].name,"number 2 Food Name: Chicken fry\nSIZE: 1 small bucket\nQuantity: 4 pices ");
    strcpy(f[3].name,"number 3 Food Name: PIZZA\nSIZE: single pack\nQuantity: 150gm ");
    strcpy(f[4].name,"number 4 Food Name: NACHOS\nSIZE: full pack\nQuantity:  250gm ");
    strcpy(f[5].name,"number 5 Food Name: COFFEE\nSIZE: 1 CUP\nQuantity: 150ml ");
    strcpy(f[6].name,"number 6 Food Name: DEW\nSIZE: 1 BOTTLE\nQuantity: 400ml ");
    printf("%s",f[i].name);
}

void food_ditels3(int i)
{
    strcpy(f[0].name,"No food\n");
    strcpy(f[1].name,"number 1 Food Name: BURGER\nSIZE: 10cm\nQuantity: 100gm ");
    strcpy(f[2].name,"number 2 Food Name: Chicken fry\nSIZE: 1 small bucket\nQuantity: 4 pices ");
    strcpy(f[3].name,"number 3 Food Name: PIZZA\nSIZE: single pack\nQuantity: 150gm ");
    strcpy(f[4].name,"number 4 Food Name: NACHOS\nSIZE: full pack\nQuantity:  250gm ");
    strcpy(f[5].name,"number 5 Food Name: COFFEE\nSIZE: 1 CUP\nQuantity: 150ml ");
    strcpy(f[6].name,"number 6 Food Name: DEW\nSIZE: 1 BOTTLE\nQuantity: 400ml ");
    printf("%s\n",f[i].name);
}

void status_F(int a)
{
    int b;
    if(a==1)
    {
        node *temp=order_food;
        while(temp!=NULL)
        {
            food_ditels2(temp->val);
            printf(" %d items\n", temp->a);
            temp=temp->next;
        }
        printf("Press 0 back");
        scanf("%d",&b);
        system("cls");
        return;
    }
    else if(a==2)
    {
        node *current=served_food;
        while(current!=NULL)
        {
            food_ditels2(current->val);
            printf(" %d Items\n", current->a);
            current=current->next;
        }
        printf("Press 0 back");
        scanf("%d",&b);
        system("cls");
        return;
    }
    else if(a==3)
    {
        if(food!=NULL)
        {
            node *future=food;
            while(future!=NULL)
            {
                food_ditels2(future->val);
                printf(" %d Items\n", future->a);
                future=future->next;
            }
            printf("Press 0 back");
            scanf("%d",&b);
            system("cls");
            return;

        }
        else
        {
            printf("There is no food\n");
            printf("Press 0 back");
            scanf("%d",&b);
            system("cls");
            return;
        }

    }
    else
    {
        return;
    }
}

void menu()
{
    int a,b,c,i=0;
    printf("\n\n 1. Food list & order them\n 2. Served order food\n 3. Current status\n 4. Back\n Enter your choice: ");
    while(scanf("%d",&a)!=4)
    {
        system("cls");
        if (a==1)
        {
            i++;
            food_list();
        }
        else if(a==2)
        {
            if(i>0)
            {
                b=serve_food();
                food_ditels2(b);
                printf("%d Items\nPress 0 to back: ",global);
                scanf("%d",&c);
                system("cls");
            }
            else
            {
                printf("\n\tThere is no food to served\nPress 0 to back: ");
                scanf("%d",&c);
                system("cls");
            }

        }
        else if(a==3)
        {
            if(i>0)
            {
                printf("\n\n 1. Order food\t\t 2. Served food\n\n 3. Waiting food\t\t 4. Back\n Enter your choice:  ");
                while(scanf("%d",&c)!=4)
                {
                    system("cls");
                    if(c==1)
                    {
                        status_F(c);
                    }
                    else if(c==2)
                    {
                        status_F(c);
                    }
                    else if(c==3)
                    {
                        status_F(c);
                    }
                    else if(c==4)
                    {
                        break;
                    }
                    printf("\n\n 1. Order food\t\t2. Served food\n3. Waiting food\t\t4. Back\n Enter your choice:  ");
                }
            }
            else
            {
                puts("There is no food order, serve & waiting\n");
            }

        }
        else
        {
            break;
        }
        printf("\n\n 1. Food list & order them\n 2. Served order food\n 3. Current status\n 4. Back\n Enter your choice: ");

    }

}
void about()
{
    int a;
    printf("\n\tHello I am Programmer Towheed.\n\tEmail:programmertowheed@gmail.com\n\tWebsite:programmertowheed.com\n\npress 0 to back\n");
    scanf("%d",&a);
    system("cls");
    if(a!=0)
    {
        about();
    }

}
int main()
{
    int a;
    printf("\n\t\t\t\tWelcome to our Restaurant \n\n\n1. Menu\t\t\n2. About\t\t\n3. Exit\n\n\nEnter your choice: ");
    while(scanf("%d",&a)!=3)
    {
        system("cls");
        if(a==1)
        {
            menu();
        }
        else if(a==2)
        {
            about();
        }
        else
        {
            break;
        }
        printf("\n\t\t\t\tWelcome to our Restaurant \n\n\n1. Menu\t\t\n2. About\t\t\n3. Exit\n\nEnter your choice: ");
    }

    printf("\n\t\t\t\tThank you for coming\n\n");
    return 0;
}

