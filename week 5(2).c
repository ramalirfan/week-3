#include <stdio.h>
#include <string.h>
int main (){
    char candidates[3][20]={"ali","ahmad","abdullah"};
    int votes[3]={0,0,0};
    int voters =3;
    char prefs[3][3][10]={
        {"ali","ahmad","abdullah"},{"abdullah","ahmad","ali"},{"ahmad","abdullah","ali"}
    };
    for (int i = 0;i < voters; i++){
        if (strcmp(prefs[i][0],"ali") == 0) votes[0]++;
        if (strcmp(prefs[i][0],"abdullah") == 0) votes[1]++;
        if (strcmp(prefs[i][0],"ahmad") == 0) votes[2]++;
    }
    printf("round 1 votes:\n");
    printf("ali = %d\nabdullah = %d\nahmad = %d\n",votes[0],votes[1],votes[2]);
    votes[0] = 0;
    votes[1]++;
    printf("\nafter elimination:\n");
    printf("abdullah = %d\nahmad = %d\n",votes[1],votes[2]);
    printf("\nwinner: abdullah\n");
    return 0;
    }