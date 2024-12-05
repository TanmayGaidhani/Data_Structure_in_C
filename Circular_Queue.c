#include<stdio.h>
int Queue[20],Maxsize;
int rear=-1;
int front=-1;
void Enqueue()
{
    int element;
    printf("HEY!!**YOU CHOOSE ENQUEUE OPERATION**\n");
    printf("ENTER THE ELEMENT FOR ENQUUE :");
    scanf("%d",&element);
    if((rear+1)% Maxsize==front)
    {
        printf("******QUEUE IS FULL******");
    }
    else if(rear==-1)
    {
        front=0;
        rear=0;
        Queue[rear]=element;
        printf("ELEMENT IN QUEUE IS:[ %d ]",element);
    }
    else
    {
        rear=(rear+1)% Maxsize;
        Queue[rear]=element;
        printf("ELEMENT IN QUEUE IS:[%d]",element);
    } 
}
void Dqueue()
{
	int item;
	printf("HEY!!**YOU CHOOSE DQUEUE OPERATION**\n");
	if(front==-1)
	{
		printf("******QUEUE IS FULL******");
	}
	else if(front==rear)
	{
		item=Queue[rear];
		front=-1;
		rear=-1;
		printf("DEQUEUE ELEMENT IS :[ %d ]",item);
	}
	else
	{
		item=Queue[front];
		front=(front+1)%Maxsize;
		printf("DEQUEUE ELEMENT IS :[ %d ]",item);
	}
}
void Display()
{
    int i;
	printf("HEY!!**YOU CHOOSE DISPLAY OPERATION**\n");
    if (front == -1) 
    {
        printf("*******QUEUE IS EMPTY*******\n");
    } 
    else 
    {
        printf("ELEMENT IN QUEUE ARE:");
        for(i=front;i!=rear;i=(i+1)%Maxsize)
        {
            printf("[ %d ]",Queue[i]);
        }   
        printf("[ %d ]",Queue[rear]);
    }
}
void main()
{
    int choice;
    printf("**THIS IS CIRCULAR QUEUE**\n");
	printf("ENETR THE SIZE OF QUEUE:");
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
			Enqueue();
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