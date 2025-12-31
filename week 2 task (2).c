#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int main (){
    char text[1000];
    int letters=0,words=1,sentences=0;
    printf("write a text:");
    fgets(text,sizeof(text),stdin);
    for (int i=0;i < strlen(text);i++){
        if(isalpha(text[i])){
        letters++;
        }
        else if (text[i] == ' '){
        words++;
        }
        else if (text[i] == '.'|| text[i] == '?' || text[i] == '!'){
        sentences++;
        }
    }
    float L =((float)letters / words) * 100;
    float S =((float)sentences / words) * 100;
    int grade= round(0.0588 * L - 0.296 * S - 15.8);
     if (grade < 1)
     printf("before grade 1\n");
     else if (grade >= 16)
     printf("grade 16+\n");
     else
     printf("grade %d\n",grade);
     return 0;
}