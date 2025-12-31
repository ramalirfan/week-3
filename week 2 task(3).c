#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main (){
    int key;
    char text[1000];
    printf("enter a key");
    scanf("%d",&key);
    printf("enter text");
    scanf("%s",text);
    for (int i = 0;i < strlen(text);i++){
        char c= text[i];
        if(isupper(c)){
            text[i]=(c - 'A'+key) % 26 + 'A';
        }
        else if (islower(c)){
            text[i] = (c - 'a' + key) % 26 + 'a';
        }
        }
        printf("ciphertext: %s\n",text);
        return 0;
    }