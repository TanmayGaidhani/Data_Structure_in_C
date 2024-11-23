#include <stdio.h>
int main() 
{
    int a[100][100], i, j, rows, columns;
    int count = 0; 
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &rows, &columns);

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) 
    {
        for (j = 0; j < columns; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] != 0)
            count++; 
        }
    }

    printf("Matrix is:\n");
    for (i = 0; i < rows; i++) 
    {
        for (j = 0; j < columns; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    if (count <= (rows * columns) / 2) 
    {
        printf("\nThe matrix is a sparse matrix.\n");
        printf("\n Triple representation:\n");
        printf("\nRow\tColumn\tValue\n");
        for (i = 0; i < rows; i++) 
        {
            for (j = 0; j < columns; j++)
            {
                if (a[i][j] != 0)
                    printf("%d\t%d\t%d\n", i, j, a[i][j]);
            }
        }
    } 
    else 
    {
        printf("\nThe matrix is not a sparse matrix.\n");
    }
}
