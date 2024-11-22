
#include<stdio.h>
int a[50],size,pos,item,i;
void display()
{
	printf("*****DISPLAY ARRAY*****");
	for(int i=0;i<size;i++){
		printf("%d\n",a[i]);
	}
}
void insert_at_position()
{
	printf("HEY ! YOU CHOOCE INSERT OPRATION");
	int i;
	printf("Enter the Position \n");
	scanf("%d",&pos);
	printf("enter the element \n");
	scanf("%d",&item);
	if(pos<=size)
	{
	for(i=size;i>=pos;i--)
	{
	 a[i]=a[i-1];
	}
	a[pos-1]=item;
	size++;
	}
	else
	{
	printf("Invalid");
	}
	display();
}
void delete_from_position()
{
	printf("HEY ! YOU CHOOCE DELETE OPRATION");
	printf("\n Enter the position \n");
        scanf("%d",&pos);
	if(pos>=size)
	{
        printf("NOT POSSIBLE");
	}
        else
	{
	for(i=pos-1;i<size-1;i++)
		{
		a[i]=a[i+1];
    	}
		size--;
    	display();   
	}
}
void search_position()
{
	printf("HEY ! YOU CHOOCE SEARCH OPRATION");
	int flag=0;
	printf("Enter the Element for Searching \n");
	scanf("%d",&item);
	for(i=0;i<size;i++)
	{
	if(a[i]==item)
        { 
	printf("Element is found at Positin:%d \n",i+1);
	flag=1;
	break;
	}
	}
	if(flag==0)
	{
	printf("Element is not found");
	}
	display();
}
void insert_at_endposition()
{ 
	printf("HEY ! YOU CHOOCE INSERT AT END OPRATION");
	printf("Enter the Element\n");
    scanf("%d",&item);
    a[size]=item;
	size++;
	printf("*****DISPLAY*****");
    display();
}
void delete_from_endposition()
{
	printf("HEY ! YOU CHOOCE DELETE FROM END OPRATION");
	for(i=0;i<size;i++)
	{
	printf("%d",a[i]);
	}
	printf("\n");
	size--;
	display();
}
void main()
{
  	int choice;
  	printf("Enter the Size of Array\n");
  	scanf("%d",&size);
  	printf("Enter the Element of Array \n");
  	for(i=0;i<size;i++)
   	{
     	scanf("%d",&a[i]);
   	}
do
{
   printf("\nENTER THE CHOICE \n");
   printf("1.INSERT \n");
   printf("2.DELETE \n");
   printf("3.SEARCH ELEMENT \n");
   printf("4.INSERT AT END \n");
   printf("5.DELETE AT END \n");

   scanf("%d",&choice);
   
   switch(choice)
    { 
     case 1:
     insert_at_position();
     break;

     case 2:
     delete_from_position();
     break;

     case 3:
     search_position();
     break;
      
     case 4:
     insert_at_endposition();
     break;
     
     case 5:
     delete_from_endposition();
     break;

     default:
     printf("invalid choice");
     break;
   }
}while(choice<=5);     	
}

