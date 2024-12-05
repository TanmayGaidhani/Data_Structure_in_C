#include <stdio.h>

int a[50];
void main() {
    int size, x, low=0, high,temp=0;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements in acending or decendimg order:\n"); // otherwise give the error in the finding element
    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the element to search in the array:"); 
    scanf("%d", &x);

    high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (x == a[mid]) {
            temp=1;
            printf("Element found at index %d\n", mid);
            break;
        } else if (x < a[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;  
        }
    }
    if(temp==0)
    printf("Element not found in the array.\n");
}
