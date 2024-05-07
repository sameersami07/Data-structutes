//implementation of dequeues using arrays
#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int dequeue[MAX];
int front=-1,rear=-1;
void insert_front(int);
void insert_rear(int);
void delete_front();
void delete_rear();
void display();
int main()
{
	int choice,item;
	char ch;
	while(1)
	{
		printf("\nMenu\n1.insert_front\n2.insert_rear\n3.delete_front\n4.delete_rear\n5.display\n6.exit\n");
		printf("enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("inserted element\n");
				scanf("%d",&item);
				insert_front(item);
				break;
			case 2:printf("inserted element\n");
				scanf("%d",&item);
				insert_rear(item);
				break;
			case 3:delete_front();
				break;
			case 4:delete_rear();
				break;
			case 5:display();
				break;
			case 6:exit(0);
			default :printf(" invalid choice");
		}
				
	}
}
void insert_front(int item)
{
	if(front==(rear+1)%MAX)
		printf("DeQueue is full\n");
	else
	{
		if(front==-1)
		{
			front=rear=0;
			dequeue[front]=item;
		}
		else if(front==0)
		{
			front=MAX-1;
			dequeue[front]=item;
		}
		else
		{
		    front--;
			dequeue[front]=item;
		}
	}
}
void insert_rear(int item)
{
	if(front==(rear+1)%MAX)
		printf("dequeue is full\n");
	else if(front==-1)
	{
		front=rear=0;
		dequeue[rear]=item;
	}
	else
	{
		rear=(rear+1)%MAX;
		dequeue[rear]=item;
	}
}
void delete_front()
{
	if(front==-1)
		printf("dequeue is empty\n");
	else
	{
		printf("deleted element is %d",dequeue[front]);
		if(front==rear) front=rear=-1;
		else
			front=(front+1)%MAX;
	}
}
void delete_rear()
{
	if(front==-1)
		printf("dequeue is empty\n");
	else
	{
		printf("deleted element is %d",dequeue[rear]);
		if(front==rear)
			front=rear=-1;
		else if(rear==0)
			rear=MAX-1;
		else
			rear--;
	}
}
void display()
{
	int i;
	if(front==-1)	
		printf("dequeue is empty");
	else
	{
		if(front<=rear)
		{
			for(i=front;i<=rear;++i)
				printf("%4d",dequeue[i]);
			
		}
		else
		{
			for(i=front;i<=MAX-1;++i)
				printf("%4d",dequeue[i]);
			for(i=0;i<=rear;++i)
				printf("%4d",dequeue[i]);
		}
	}
}
