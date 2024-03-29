#include <bits/stdc++.h>
using namespace std;

/*
 all insertion function for candidate

*/
struct Node
{
    char name[30];
    int VoteCus=0;
    struct Node *next;
};

struct Node *head;

void insertFirst(char data[30])
{
    struct Node *newNode;
    newNode =(struct Node*) malloc(sizeof(struct Node));
    strcpy(newNode->name,data);
    if(head==NULL)
    {
        newNode->next=NULL;
        head=newNode;
    }
    else
    {
        newNode->next=head;
        head=newNode;
    }
}

//insert end
void insertEnd(char data[30])
{
    struct Node *newNode;
    newNode =(struct Node*) malloc(sizeof(struct Node));
    strcpy(newNode->name,data);
    newNode->next=NULL;
    if(head==NULL)
    {
        head=newNode;
    }
    else
    {
        struct Node *temp=head;
        while(temp->next!=NULL)
        {
            temp= temp->next;
        }
        temp->next=newNode;
    }
}


//insert any position

void insertAnyPosition(char data[30],int position)
{
    struct Node *newNode;
    newNode=(struct Node*) malloc(sizeof(struct Node));
    strcpy(newNode->name,data);
    if(position==1)
    {
        newNode->next=head;
        head=newNode;
        return ;
    }
    else
    {
        struct Node *temp=head;
        for(int i=0; i<position-2; i++)
        {
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
}

void calculatingVote(int position){
    struct Node *temp=head;


    if(position==1)
    {
        temp->VoteCus=temp->VoteCus+1;
    }
    else
    {
        for(int i=2; i<= position; i++)
        {
            if(temp->next!=NULL)
            {
                temp = temp->next;
            }
        }
        temp->VoteCus++;
    }
}

void delete_First ()
{
    head = head->next;
}




void winner(){
   struct Node *i,*j;
   int tempData;

   for(i=head;i->next!=NULL;i=i->next){
     for(j=i->next;j!=NULL;j=j->next){
        if(i->VoteCus>j->VoteCus){
            tempData=i->VoteCus;
            i->VoteCus=j->VoteCus;
            j->VoteCus=tempData;

        }
     }
   }
}


//display
void display()
{
    if(head==NULL)
    {
        printf("empty");
    }
    else
    {
        int count=1;
        printf("*********Welcome to the voting system project*********\n\n");
        printf("                        CR election                        \n\n");
        printf("*************************************************************\n");

        struct Node *temp=head;
        while (temp->next!=NULL)
        {
            printf("================   %d.%s  ==vote %d================\n",count,temp->name,temp->VoteCus);
            temp=temp->next;
            count++;
        }
        printf("================   %d.%s  ==vote %d================\n",count,temp->name,temp->VoteCus);
        printf("\n");
    }
}


int main()
{

    int choice,target,position;
    char name[30];

    while(1)
    {
mainmenu :
        printf("1---insert the name of voters \n2---Display \n3---CalculatingVote \n0-----exits \n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("insert student Name\n");
            fflush(stdin);
            fgets(name, sizeof(name), stdin);
            while(1)
            {
                printf("1---insertFirst \n2---insertEnd \n3--insertAnyPosition \n");
                scanf("%d",&target);
                switch(target)
                {
                case 1 :
                    insertFirst(name);
                    goto mainmenu;
                    break;

                case 2 :
                    insertEnd(name);
                    goto mainmenu;
                    break;

                case 3 :
                    printf("please select the position where you can insert the element\n");
                    scanf("%d",&position);
                    insertAnyPosition(name,position);
                    goto mainmenu;
                    break;
                default :
                    goto mainmenu;
                }
            }
        case 2 :
            display();
            break;
        case 3 :
        while(1){
        secondMenu:
        printf("select 1 for vote 2 for sorting 3 for main menu\n");
        scanf("%d",&target);
        if(target==1){
            printf("whom do you want to vote ?\n");
            scanf("%d",&position);
            calculatingVote(position);
            goto secondMenu;
        }
        else if (target==2){
            winner();
            goto secondMenu;
        }
        else{
            goto mainmenu;
            break;
        }
        }

        case 0 :
            exit(0);
        }
    }

}

