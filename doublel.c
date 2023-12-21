#include<stdio.h>
#include<stdlib.h>
struct node {
        int data;
        struct node *next;
        struct node* prev;

};
 void insert_beg(int n);
 void insert_end(int n);
 void insert_position(int n,int pos);
 void delete_beg();
 void delete_end();
 void delete_position(int pos);
 void display();
 struct node *head=NULL;


void main()
{
int ch,n,pos;
do
{
printf("\n\n\n\n****ENTER AN OPTION***\n");
printf("1.INSERT AT BEG\n2.INSERT AT A POSITION\n3.INSERT AT END\n4.DELETE AT BEG\n5.DELETE AT POSITION\n6.DELETE AT END\n7.EXIT");
printf("\nEnter your choice: ");
scanf("%d",&ch);
switch(ch){
        case 1:printf("\nEnter number to insert at beg: ");
                scanf("%d",&n);
                insert_beg(n);
                display();break;
        case 2:printf("\nEnter number to be inserted: ");
                scanf("%d",&n);
                printf("\nEnter the position: ");
                scanf("%d",&pos);
                insert_position(n,pos);
                display();break;
        case 3:printf("\nEnter number to insert at end: ");
                scanf("%d",&n);
                insert_end(n);
                display();break;

         case 4:
                delete_beg();
                display();break;

        case 5:printf("\nEnter the position of number to be deleted: ");
               scanf("%d",&pos);
               delete_position(pos);
                display();break;
        case 6:
            delete_end();
            display();break;
  case 7:exit(0);break;
 default:printf("\ninvalid choice\n.");break;
}
}while(ch!=8);
}

void insert_beg(int n)
{
struct node *newnode=(struct node*)malloc(sizeof(struct node*));
newnode->data=n;
newnode->prev=NULL;
if(head==NULL)
{
        newnode->next=NULL;

        head=newnode;
        printf("first node created.\n");
}
else
{
        newnode->next=head;
        head=newnode;
        printf("node inserted at begining successfully.\n");
}
}

void insert_end(int n)
{
        struct node *newnode=(struct node*)malloc(sizeof(struct node*));
        newnode->data=n;
       newnode->next=NULL;
        if(head==NULL)
{
head=newnode;



}
else{        struct node *ptr=head;

while(ptr->next!=NULL)
        {ptr=ptr->next;}
        newnode->prev=ptr;
        ptr->next=newnode;}
        printf("\nnode inserted at end successfully");
}
void insert_position(int n,int pos)
{int i;
        struct node *ptr=head;
        struct node *newnode=(struct node*)malloc(sizeof(struct node*));
        newnode->data=n;
        for(i=2;i<pos;i++)
{
        ptr=ptr->next;
}
newnode->next=ptr->next;
(newnode->next)->prev=newnode;
ptr->next=newnode;
newnode->prev=ptr;


printf("inserted node at %d\n ",pos);
}


void delete_beg()
{
struct node *temp=head;

if(temp==NULL){printf("\n no nodes\n");}else{

head=head->next;
head->prev=NULL;
free(temp);}


}
void display()
{
struct node *ptr=head;
printf("\current nodes\n");
if(ptr==NULL)
{
printf("\n no nodes to display.");
}
else{

while(ptr!=NULL)
{
printf("%d->",ptr->data);

ptr=ptr->next;
}
}}


void delete_end()
{
struct node *temp=head;
while((temp->next)->next!=NULL)
{
temp=temp->next;
}

struct node *ptr=temp->next;
ptr->prev=NULL;
temp->next=NULL;
free(ptr);
}

void delete_position(int pos)
{int i;
struct node *ptr=head;
for(i=2;i<pos;i++)
{
ptr=ptr->next;

}

struct node *temp=ptr->next;
(temp->next)->prev=ptr;
ptr->next=temp->next;
free(temp);
}
