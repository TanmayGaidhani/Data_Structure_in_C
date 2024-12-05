/*
Name : Tanmay Sanjay Gaidhani
Class : SY 'A'
Batch : 1
ROll No. : 114
*/
#include <stdio.h>
#include <stdlib.h> 

struct Node {
    int data;
    struct Node* next;
};
int element;                        //gobal declartion
struct Node *temp,*temp1;           //gobal declartion

struct Node* head = NULL;

void Insert_at_begining() {
    printf("\nHEY!! YOU CHOICE TNSERT AT BEGINING\n");
    printf("Enter the number to insert: ");
    scanf("%d", &element);

    temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    temp->data = element;
    temp->next = head;
    head = temp;
}
void Insert_at_end(){
    printf("\nHEY!! YOU CHOICE TNSERT AT END\n");
    printf("Enter the number to insert: ");
    scanf("%d", &element);

    temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data=element;
    temp->next=NULL;
    if(head==NULL)
    {
        head = temp;
    }
    else
    {
        temp1 = head;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=temp;
    } 
}
void Insert_at_nTH_position(){
    printf("\nHEY!! YOU CHOICE TNSERT AT N^TH BEGINING\n");
    int number,position;

    temp=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the position: \n");
    scanf("%d",&position);
    printf("Enter the number to insert:\n");
    scanf("%d",&number);
    temp->data=number;
    if(position==1)
    {
        temp->next=head;
        head = temp;
    }
    else{
        temp1=head;
        for(int i=1;i<position-1;i++){
            temp1=temp1->next;
        }
        temp->next= temp1 ->next;
        temp1->next=temp;
    }
}
void Delete_form_Begnning()
{
    printf("\nHEY!! YOU CHOICE DELETE FROM BEGINING\n");
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp=head;
        head=temp->next;
        free(temp);                     // free the memory  
    }
}
void Delete_form_End(){
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp=head;
        while(temp-> next !=NULL)
        {
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=NULL;
        free(temp);
    }
}
void Delete_at_nTH_position(){
    printf("\nHEY!! YOU CHOICE DELETE AT N^TH POSITION\n");
    int number,position;

    printf("Enter the position: \n");
    scanf("%d",&position);
   
    if(head==NULL)
    {
       printf("List is empty");
    }
    else{
        temp1=head;
        for(int i=1;i<position-1;i++){
            temp1=temp1->next;
        }
        temp= temp1 ->next;
        temp1->next=temp->next;
        free(temp);
    }
}
void Search_element()
{
    printf("\nHEY!! YOU CHOICE SEARCHING OPERATION\n");
    int number;
    printf("Enter The Searching Number :");
    scanf("%d",&number);
    if(head==NULL)
    {
        printf("list is empty");
    }
    else{
        temp=head;
        while(temp!=NULL)
        {
            if(number==temp->data)
            {
                printf("*****ELEMENT IS FOUND*****");
                return;
            }
            temp=temp->next; 
        }
        printf("ELEMENT IS NOT FOUND");
    }
}
void Display()
{
    printf("\nHEY!! YOU CHOICE DISPLAY OPERATION\n");
    if(head==NULL)
    {
        printf("list is empty");
    }
    else
    {
        temp=head;
        while(temp !=NULL)
        {
           printf("[%p][%d][%p]->", temp,temp->data,temp->next); 
           temp =temp->next;
        }
    }
}
void main() {
    int choice;

    do {
        printf("\nENTER THE CHOICE :\n");
        printf("1. INSERT AT BEGINNING\n");
        printf("2. INSERT AT END\n");
        printf("3. INSERT AT nTH POSTION\n");
        printf("4. DELETE FORM BEGINNING\n");
        printf("5. DELETE FORM END\n");
        printf("6. DELETE AT nTH POSTION\n");
        printf("7. SEARCHING ELEMENT\n");
        printf("8. Display\n");
        printf("9. EXIT\n");
        printf("CHOICE IS : ");
        scanf("%d", &choice); 
        switch (choice) {
            case 1: 
                Insert_at_begining();
                break;

            case 2:
                Insert_at_end();
                break;

            case 3:
                Insert_at_nTH_position();
                break;
            
            case 4:
                Delete_form_Begnning();
                break;

            case 5:
                Delete_form_End();
                break;
            
            case 6:
                Delete_at_nTH_position();
                break;

            case 7:
                Search_element();
                break;

            case 8:
                Display();
                break;

            case 9:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 9); 
}
/*
======OUTPUT======
ENTER THE CHOICE :
1. INSERT AT BEGINNING
2. INSERT AT END
3. INSERT AT nTH POSTION
4. DELETE FORM BEGINNING
5. DELETE FORM END
6. DELETE AT nTH POSTION
7. SEARCHING ELEMENT
8. Display
9. EXIT
CHOICE IS : 1

HEY!! YOU CHOICE TNSERT AT BEGINING
Enter the number to insert: 22

ENTER THE CHOICE :
1. INSERT AT BEGINNING
2. INSERT AT END
3. INSERT AT nTH POSTION
4. DELETE FORM BEGINNING
5. DELETE FORM END
6. DELETE AT nTH POSTION
7. SEARCHING ELEMENT
8. Display
9. EXIT
CHOICE IS : 1

HEY!! YOU CHOICE TNSERT AT BEGINING
Enter the number to insert: 33

ENTER THE CHOICE :
1. INSERT AT BEGINNING
2. INSERT AT END
3. INSERT AT nTH POSTION
4. DELETE FORM BEGINNING
5. DELETE FORM END
6. DELETE AT nTH POSTION
7. SEARCHING ELEMENT
8. Display
9. EXIT
CHOICE IS : 1

HEY!! YOU CHOICE TNSERT AT BEGINING
Enter the number to insert: 44

ENTER THE CHOICE :
1. INSERT AT BEGINNING
2. INSERT AT END
3. INSERT AT nTH POSTION
4. DELETE FORM BEGINNING
5. DELETE FORM END
6. DELETE AT nTH POSTION
7. SEARCHING ELEMENT
8. Display
9. EXIT
CHOICE IS : 8

HEY!! YOU CHOICE DISPLAY OPERATION
[010D1640][44][010D1630]->[010D1630][33][010D1620]->[010D1620][22][00000000]->
ENTER THE CHOICE :
1. INSERT AT BEGINNING
2. INSERT AT END
3. INSERT AT nTH POSTION
4. DELETE FORM BEGINNING
5. DELETE FORM END
6. DELETE AT nTH POSTION
7. SEARCHING ELEMENT
8. Display
9. EXIT
CHOICE IS : 2

HEY!! YOU CHOICE TNSERT AT END
Enter the number to insert: 22

ENTER THE CHOICE :
1. INSERT AT BEGINNING
2. INSERT AT END
3. INSERT AT nTH POSTION
4. DELETE FORM BEGINNING
5. DELETE FORM END
6. DELETE AT nTH POSTION
7. SEARCHING ELEMENT
8. Display
9. EXIT
CHOICE IS : 2

HEY!! YOU CHOICE TNSERT AT END
Enter the number to insert: 33

ENTER THE CHOICE :
1. INSERT AT BEGINNING
2. INSERT AT END
3. INSERT AT nTH POSTION
4. DELETE FORM BEGINNING
5. DELETE FORM END
6. DELETE AT nTH POSTION
7. SEARCHING ELEMENT
8. Display
9. EXIT
CHOICE IS :
2

HEY!! YOU CHOICE TNSERT AT END
Enter the number to insert: 44

ENTER THE CHOICE :
1. INSERT AT BEGINNING
2. INSERT AT END
3. INSERT AT nTH POSTION
4. DELETE FORM BEGINNING
5. DELETE FORM END
6. DELETE AT nTH POSTION
7. SEARCHING ELEMENT
8. Display
9. EXIT
CHOICE IS : 8

HEY!! YOU CHOICE DISPLAY OPERATION
[010A1620][22][010A1630]->[010A1630][33][010A1640]->[010A1640][44][00000000]->
ENTER THE CHOICE :
1. INSERT AT BEGINNING
2. INSERT AT END
3. INSERT AT nTH POSTION
4. DELETE FORM BEGINNING
5. DELETE FORM END
6. DELETE AT nTH POSTION
7. SEARCHING ELEMENT
8. Display
9. EXIT
CHOICE IS : 1

HEY!! YOU CHOICE TNSERT AT BEGINING
Enter the number to insert: 22

ENTER THE CHOICE :
1. INSERT AT BEGINNING
2. INSERT AT END
3. INSERT AT nTH POSTION
4. DELETE FORM BEGINNING
5. DELETE FORM END
6. DELETE AT nTH POSTION
7. SEARCHING ELEMENT
8. Display
9. EXIT
CHOICE IS : 1

HEY!! YOU CHOICE TNSERT AT BEGINING
Enter the number to insert: 33

ENTER THE CHOICE :
1. INSERT AT BEGINNING
2. INSERT AT END
3. INSERT AT nTH POSTION
4. DELETE FORM BEGINNING
5. DELETE FORM END
6. DELETE AT nTH POSTION
7. SEARCHING ELEMENT
8. Display
9. EXIT
CHOICE IS : 1

HEY!! YOU CHOICE TNSERT AT BEGINING
Enter the number to insert: 44

ENTER THE CHOICE :
1. INSERT AT BEGINNING
2. INSERT AT END
3. INSERT AT nTH POSTION
4. DELETE FORM BEGINNING
5. DELETE FORM END
6. DELETE AT nTH POSTION
7. SEARCHING ELEMENT
8. Display
9. EXIT
CHOICE IS : 3

HEY!! YOU CHOICE TNSERT AT N^TH POSTION
Enter the position:
2
Enter the number to insert:
6666

ENTER THE CHOICE :
1. INSERT AT BEGINNING
2. INSERT AT END
3. INSERT AT nTH POSTION
4. DELETE FORM BEGINNING
5. DELETE FORM END
6. DELETE AT nTH POSTION
7. SEARCHING ELEMENT
8. Display
9. EXIT
CHOICE IS : 8

HEY!! YOU CHOICE DISPLAY OPERATION
[009A1640][44][009A1650]->[009A1650][6666][009A1630]->[009A1630][33][009A1620]->[009A1620][22][00000000]->
ENTER THE CHOICE :
1. INSERT AT BEGINNING
2. INSERT AT END
3. INSERT AT nTH POSTION
4. DELETE FORM BEGINNING
5. DELETE FORM END
6. DELETE AT nTH POSTION
7. SEARCHING ELEMENT
8. Display
9. EXIT
CHOICE IS : 4

HEY!! YOU CHOICE DELETE FROM BEGINING

ENTER THE CHOICE :
1. INSERT AT BEGINNING
2. INSERT AT END
3. INSERT AT nTH POSTION
4. DELETE FORM BEGINNING
5. DELETE FORM END
6. DELETE AT nTH POSTION
7. SEARCHING ELEMENT
8. Display
9. EXIT
CHOICE IS : 8

HEY!! YOU CHOICE DISPLAY OPERATION
[009A1650][6666][009A1630]->[009A1630][33][009A1620]->[009A1620][22][00000000]->
ENTER THE CHOICE :
1. INSERT AT BEGINNING
2. INSERT AT END
3. INSERT AT nTH POSTION
4. DELETE FORM BEGINNING
5. DELETE FORM END
6. DELETE AT nTH POSTION
7. SEARCHING ELEMENT
8. Display
9. EXIT
CHOICE IS : 5

ENTER THE CHOICE :
1. INSERT AT BEGINNING
2. INSERT AT END
3. INSERT AT nTH POSTION
4. DELETE FORM BEGINNING
5. DELETE FORM END
6. DELETE AT nTH POSTION
7. SEARCHING ELEMENT
8. Display
9. EXIT
CHOICE IS : 8

HEY!! YOU CHOICE DISPLAY OPERATION
[009A1650][6666][009A1630]->[009A1630][33][00000000]->
ENTER THE CHOICE :
1. INSERT AT BEGINNING
2. INSERT AT END
3. INSERT AT nTH POSTION
4. DELETE FORM BEGINNING
5. DELETE FORM END
6. DELETE AT nTH POSTION
7. SEARCHING ELEMENT
8. Display
9. EXIT
CHOICE IS : 1

HEY!! YOU CHOICE TNSERT AT BEGINING
Enter the number to insert: 33

ENTER THE CHOICE :
1. INSERT AT BEGINNING
2. INSERT AT END
3. INSERT AT nTH POSTION
4. DELETE FORM BEGINNING
5. DELETE FORM END
6. DELETE AT nTH POSTION
7. SEARCHING ELEMENT
8. Display
9. EXIT
CHOICE IS : 1

HEY!! YOU CHOICE TNSERT AT BEGINING
Enter the number to insert: 44

ENTER THE CHOICE :
1. INSERT AT BEGINNING
2. INSERT AT END
3. INSERT AT nTH POSTION
4. DELETE FORM BEGINNING
5. DELETE FORM END
6. DELETE AT nTH POSTION
7. SEARCHING ELEMENT
8. Display
9. EXIT
CHOICE IS : 6

HEY!! YOU CHOICE DELETE AT N^TH BEGINING
Enter the position:
2

ENTER THE CHOICE :
1. INSERT AT BEGINNING
2. INSERT AT END
3. INSERT AT nTH POSTION
4. DELETE FORM BEGINNING
5. DELETE FORM END
6. DELETE AT nTH POSTION
7. SEARCHING ELEMENT
8. Display
9. EXIT
CHOICE IS : 8

HEY!! YOU CHOICE DISPLAY OPERATION
[010B1640][44][010B1620]->[010B1620][22][00000000]->
ENTER THE CHOICE :
1. INSERT AT BEGINNING
2. INSERT AT END
3. INSERT AT nTH POSTION
4. DELETE FORM BEGINNING
5. DELETE FORM END
6. DELETE AT nTH POSTION
7. SEARCHING ELEMENT
8. Display
9. EXIT
CHOICE IS : 7

HEY!! YOU CHOICE SEARCHING OPERATION
Enter the searching number:44
*****ELEMENT IS FOUND*****
ENTER THE CHOICE :
1. INSERT AT BEGINNING
2. INSERT AT END
3. INSERT AT nTH POSTION
4. DELETE FORM BEGINNING
5. DELETE FORM END
6. DELETE AT nTH POSTION
7. SEARCHING ELEMENT
8. Display
9. EXIT
CHOICE IS : 9
Exiting...
*/