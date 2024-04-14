#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
typedef struct node NODE;
void create();
void insert_front(int);
void insert_last(int);
void insert_pos(int,int);
void delete_front();
void delete_last();
void delete_pos();
void traversalLtoR();
void traversalRtoL();
NODE *head = NULL;
int main()
{
    int choice, item, pos;
    create();
    while(1)
    {
        printf("\nMENU\n");
        printf("1. Insert front\n");
        printf("2. Insert Last\n");
        printf("3. Insert at the specified Position\n");
        printf("4. Delete front\n");
        printf("5. Delete Last\n");
        printf("6. Delete at the specified position\n");
        printf("7. Traversal (left to right)\n");
        printf("8. Traversal (right to left\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d",&item);
            insert_front(item);
            break;
        case 2:
            printf("Enter the element to be inserted: ");
            scanf("%d",&item);
            insert_last(item);
            break;
        case 3:
            printf("Enter the element: ");
            scanf("%d",&item);
            printf("Enter the position: ");
            scanf("%d",&pos);
            insert_pos(item,pos);
            break;
        case 4:
            delete_front();
            break;
        case 5:
            delete_last();
            break;
        case 6:
            printf("Enter the position: ");
            scanf("%d",&pos);
            delete_pos(pos);
            break;
        case 7:
            traversalLtoR();
            break;
        case 8:
            traversalRtoL();
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
void create()
{
    NODE *cur, *temp;
    int ch;
    int item;
    do
    {
        printf("Enter the element: ");
        scanf("%d",&item);
        temp = (NODE *)malloc(sizeof(NODE));
        temp->data = item;
        if(head==NULL)
        {
            head = cur = temp;
        }
        else
        {
            cur->next = temp;
            temp->prev = cur;
            cur = temp;
        }
         getchar();
		printf("Do you want to continue(y/n):");
		scanf("%c",&ch);
	}while(ch=='y');
     
    head->prev = NULL;
    cur->next = NULL;
}
void insert_front(int item)
{
    NODE* temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = item;
    temp->next = head;
    temp->prev = NULL;
    head->prev = temp;
    head = temp;
}
void insert_last(int item)
{
    NODE *temp, *cur;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = item;
    if(head==NULL)
    {
        head=temp;
        temp->prev = NULL;
    }
    else
    {
        cur=head;
        while(cur->next!=NULL)
        {
            cur = cur->next;
        }
        cur->next = temp;
        temp->prev = cur;
    }
    temp->next = NULL;
}
void delete_front()
{
    NODE *temp;
    if(head==NULL) printf("List is empty\n");
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        printf("Element deleted: %d\n",temp->data);
        free(temp);
    }
}
void delete_last()
{
    NODE *temp, *cur;
    if(head==NULL) printf("List is empty\n");
    else if(head->next==NULL)
    {
        temp = head;
        head = NULL;
        printf("Deleted element: %d\n",temp->data);
        free(temp);
    }
    else
    {
        cur = head;
        while(cur->next->next != NULL)
            cur = cur->next;
        temp = cur->next;
        cur->next = NULL;
        printf("Deleted element: %d\n",temp->data);
        free(temp);
    }
}
void insert_pos(int item,int pos)
{
    int i;
    NODE *cur1=head, *cur2, *temp;
    if(pos==1) insert_front(item);
    else
    {
        for(i=1; i<=(pos-2); i++)
            cur1=cur1->next;
        if(cur1==NULL)
            printf("Invalid Position\n");
        else
        {
            cur2 = cur1->next;
            temp = (NODE*)malloc(sizeof(NODE));
            temp->data = item;
            temp->next = cur2;
            cur2->prev = temp;
            cur1->next = temp;
            temp->prev = cur1;
        }
    }
}
void delete_pos(int pos)
{
    int i;
    NODE *cur1=head, *cur2, *temp;
    if(pos==1) delete_front();
    else
    {
        for(i=1; i<=(pos-2); i++)
            cur1=cur1->next;
        if(cur1->next == NULL) printf("Invalid Position\n");
        else
        {
            temp = cur1->next;
            cur2 = temp->next;
            cur1->next = cur2;
            cur2->prev = cur1;
            printf("Deleted element: %d\n",temp->data);
            free(temp);
        }
    }
}
void traversalLtoR()
{
    NODE *cur=head;
    if(head==NULL)
        printf("List is empty\n");
    else
    {
        printf("List content:\n");
        while(cur!=NULL)
        {
            printf("%d ",cur->data);
            cur = cur-> next;
        }
    }
}
void traversalRtoL()
{
    NODE *cur=head;
    if(head==NULL)
        printf("List is empty\n");
    else
    {
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
        while(cur!=NULL)
        {
            printf("%d ",cur->data);
            cur=cur->prev;
        }
    }
}
