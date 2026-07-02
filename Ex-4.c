


#include<stdio.h>
#include<string.h>
int main(){
char string[32];
int i, count =0;
printf("\n\n\n\nEnter your string:");
gets(string);

if((string[0] >='a' && string[0] <='z') ||
   ( string[0] >='A' && string[0] <='Z')||
    (string[0] =='_')){

        for(i=1; i<strlen(string); i++){
            if((string[i] >='a' && string[i] <='z') ||
    (string[i] >='A' && string[i] <='Z')||
    (string[i] >='0' && string[i] <='9')||
    (string[i] =='_')){
    count++;
    }
        }
    }
    if(count == (strlen(string)-1)){
        printf("\n\n\n\n    Input string is a valid identifier");
    }
    else{
         printf("\n\n\n\n    Input string is not a valid identifier");
    }

return 0;
}
