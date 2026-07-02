
#include<stdio.h>

int main()
{
    int arr[100];
    int value, pos, i, n;

    printf("Enter the number of elements in array: ");
    scanf("%d", &n);

    printf("Enter position and element\n");
    scanf("%d%d",&pos,&value);

    if(pos <=n && pos >= 0)
    {
        for(i = n; i > pos; i--)
            arr[i] = arr[i-1];

        arr[pos] = value;


        for(i = 0; i <=n; i++)
            printf("%d ", arr[i]);
    }
    else
        printf("\nInvalid Position");

    return 0;
  }
