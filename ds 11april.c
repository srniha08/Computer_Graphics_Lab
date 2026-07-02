#include<stdio.h>
void main()
{
int arry[20],position,n,j;

printf(" enter number of elements in arry");
scanf("%d",&n);

   printf("Enter a number");

for(j=0;j<n;j++)
scanf("%d",&arry[j]);

printf("\n Enter the location where you wish to delete element");
scanf("%d",&position);

printf("\n deletion not possible");
else
{
for(j=position-1;j<n-1;j++);
arry[j]=arry[j+1];
printf("\n Resultant arry is");

for(j=0;j<n-1;j++)
printf("\n %d",arry[j]);
  }
}

