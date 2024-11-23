#include <stdio.h>
#define MAXSIZE 10

void initializeTable(int table[], int size) {
    for (int i = 0; i < size; i++) {
        table[i] = -1;
    }
}

int hashFunction(int key) {
    return key % MAXSIZE;
}

void displayTable(int table[]) 
{
    printf("Hash Table:\n");
    for (int i = 0; i <  MAXSIZE; i++) {
        if (table[i] == -1) {
            printf("[%d] : NULL\n", i);
        } else {
            printf("[%d] : %d\n", i, table[i]);
        }
    }
}

void linearProbing(int table[], int key) {
    int index = hashFunction(key);
    int i = 0;
    
    while (table[(index + i) %  MAXSIZE] != -1 && i <  MAXSIZE) 
    {
        i++;
    }

    if (i < MAXSIZE) {
        table[(index + i) %  MAXSIZE] = key;
    } else {
        printf("Table is full\n");
    }displayTable(table);
}

void quadraticProbing(int table[], int key) 
{
    int index = hashFunction(key);
    int i = 0;
    
    while (table[(index + i * i) %  MAXSIZE] != -1 && i < MAXSIZE) {
        i++;
    }

    if (i <  MAXSIZE) {
        table[(index + i * i) %  MAXSIZE] = key;
    } else {
        printf("Table is full\n");
    } displayTable(table);
}

int hash2(int key) 
{
    return 7 - (key % 7); 
}
void doubleHashing(int table[], int key) {
    int index = hashFunction(key);
    int stepSize = hash2(key);
    int i = 0;
    
    while (table[(index + i * stepSize) %  MAXSIZE] != -1 && i <  MAXSIZE) {
        i++;
    }

    if (i <  MAXSIZE) {
        table[(index + i * stepSize) %  MAXSIZE] = key;
    } else {
        printf("Table is full\n");
    } displayTable(table);
}

int main() 
{
    int table[ MAXSIZE];
    int choice, key, i;

    initializeTable(table,  MAXSIZE);

    for (i = 0; i <  MAXSIZE; i++) 
    {
        printf("Enter key element %d: \n", i + 1);
        scanf("%d", &key);

        printf("Choose the probing method:\n");
        printf("1. Linear Probing\n");
        printf("2. Quadratic Probing\n");
        printf("3. Double Hashing\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nHEY YOU CHOSE THE LINEAR PROBING\n");
                linearProbing(table, key);
                break;
            case 2:
                printf("\nHEY YOU CHOSE THE QUDRATING PROBING\n");
                quadraticProbing(table, key);
                break;
            case 3:
                printf("\nHEY YOU CHOSE THE DOUBLE HASHING\n");
                doubleHashing(table, key);
                break;
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }
}