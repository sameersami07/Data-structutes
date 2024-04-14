#include <stdio.h>
#include <stdlib.h>
struct node
{
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
void display();
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
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d",&item);
            insert_front(item);
            printf("Element inserted sucessfully.\n");
            break;
        case 2:
            printf("Enter the element to be inserted: ");
            scanf("%d",&item);
            insert_last(item);
            printf("Element inserted sucessfully.\n");
            break;
        case 3:
            printf("Enter the element: ");
            scanf("%d",&item);
            printf("Enter the position: ");
            scanf("%d",&pos);
            insert_pos(item,pos);
          printf("Element inserted sucessfully.\n");  
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
            display();
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
void create()
{
	NODE *cur,*temp;
	char ch;
	int item;
	do
	{
		printf("Enter the element:\n");
		fflush(stdin);
		scanf("%d",&item);
		temp=(NODE *)malloc(sizeof(NODE));
		temp->data=item;
		if(head==NULL)
			head=cur=temp;
		else
		{
			cur->next=temp;
			cur=temp;
		}
    getchar();
		printf("Do you want to continue(y/n):");
		scanf("%c",&ch);
	}while(ch=='y');
	cur->next=NULL;
}

    
void insert_front(int item)
{
    NODE* temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = item;
    temp->next = head;
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
    }
    else
    {
        cur=head;
        while(cur->next!=NULL)
        {
            cur = cur->next;
        }
        cur->next = temp;
    }
    temp->next = NULL;
}
void insert_pos(int item,int pos)
{
    int i;
    NODE *cur=head, *temp;
    if(pos==1) insert_front(item);
    else
    {
        for(i=1; i<=(pos-2); i++)
            cur=cur->next;
        if(cur==NULL)
            printf("Invalid Position\n");
        else
        {
            temp = (NODE*)malloc(sizeof(NODE));
            temp->data = item;
            temp->next = cur->next;
            cur->next = temp;
        }
    }
}
void delete_front()
{
    NODE *temp;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;
        head = head->next;
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
        {
            cur = cur->next;
        }
        temp = cur->next;
        cur->next = NULL;
        printf("Deleted element: %d\n",temp->data);
        free(temp);
    }
}
void delete_pos(int pos)
{
    int i;
    NODE *cur=head,*temp;
    if(pos==1) delete_front();
    else
    {
        for(i=1; i<=(pos-2); i++)
            cur=cur->next;
        if(cur->next == NULL)
            printf("Invalid Position\n");
        else
        {
            temp = cur->next;
            cur->next = temp->next;
            printf("Deleted element: %d\n",temp->data);
            free(temp);
        }
    }
}
void display()
{
    NODE *temp=head;
    if(head==NULL)
        printf("List is empty\n");
    else
    {
        printf("List content:\n");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp = temp-> next;
        }
    }
    printf("\n");
}
