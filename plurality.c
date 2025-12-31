#include <stdio.h>
#include <string.h>
int main (){
    char candidates[3][20]={"ali","ahmad","abdullah"};
    int votes[3]={0,0,0};
    int n;
    printf("enter number of voters");
    scanf("%d",&n);
    for (int i = 0;i < n;i++){
        char name[20];
        printf("vote:");
        scanf("%s",&name);
        if(strcmp(name,"ali") == 0)
        votes[0]++;
        else if(strcmp(name,"ahmad") == 0)
        votes[1]++;
        else if (strcmp(name,"abdullah") == 0)
        votes[2]++;
        else 
        printf("invalid vote\n");
    }
    int max = votes[0];
    if (votes[1] > max) max = votes[1];
    if (votes[2] > max) max = votes[2];
    printf("winner");
    if (votes[0] == max)
    printf("ali");
    if (votes[1] == max)
    printf("ahmad");
    if (votes[2] == max)
    printf("abdullah");
    return 0;
}