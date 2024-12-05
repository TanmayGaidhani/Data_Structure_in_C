#include<stdio.h>
int front=-1,rear=-1;
int Maxsize;
int Queue[100];
void Enque()
{
	int element;
	printf("HEY!!! YOU CHOOSE THE ENQUEUE OPERATION");
	printf("\n ENTER THE ELEMENT:");
	scanf("%d",&element);
	if(rear==Maxsize-1)
	{		
		printf("*******QUEUE IS FULL*******");
	}
	else
	{
		if(front==-1)
		{
			front=0;
		}
		rear++;
		Queue[rear]=element;
		printf("ENQUEUE ELEMENT IS [ %d ]:",element);
	}
}

void Dqueue()
{
	printf("\nHRY!!! YOU CHOOSE DQUEUE OPERATION \n");
	int item;
	if(front==-1)
	{
		printf("*******QUEUE IS EMPTY*******\n");
	}
	else if(front==rear)
	{
		item=Queue[front];
		front=-1;
		rear=-1;
		printf("DQUEUE ELEMENT IS: [ %d ]\n",item);
	}
	else
	{
		item=Queue[front];
		front++;
		printf("DQUEUE ELEMENT IS: [ %d ]\n",item);
	}
}

void Display()
{
	int i;
	if(front==-1)
	{
		printf("*******QUEUE IS EMPTY*******\n");
	}
	else
	{
		printf("ELEMENT IN QUEUE IS:");
		for(i=front;i<=rear;i++)
		{
			
			printf("[ %d ]",Queue[i]);
		}
	}
}
void main()
{
	int choice;
	printf("ENETR THE SIZE OF QUEUE: ");
	scanf("%d",&Maxsize);
	do{
		printf("\nENTER THE CHOICE:");
		printf("\n1.Enqueue");
		printf("\n2.Dequeue");
		printf("\n3.displayed\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			Enque();
			break;
			case 2:
			Dqueue();
			break;
	 		case 3:
			Display();
			break;
			default:
			printf("invalid choice");
			break;
		}
	}while(choice!=4);
}