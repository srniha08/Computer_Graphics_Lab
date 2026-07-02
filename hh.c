#include<stdio.h>
void main()
{
int num1,num2;
printf("\n please enter two number :"  );
scanf("%d%d",&num1,&num2);
if(num1>num2)
printf("\n The number %dis greater than %d",num1,num2);
else if(num2>num1)
printf("\n the number %d is greater than %d,num2,num1");
else
printf("/n the number %d is equal to %d",num1,num2);


return 0;
}
