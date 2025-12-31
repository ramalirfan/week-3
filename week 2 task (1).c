#include <stdio.h>
#include <string.h>
#include <ctype.h>
int comp_score(char word[]);
int main() {
        char word1[50],word2[50];
        printf("enter first word");
        scanf("%s",word1);
        printf("enter a second word");
        scanf("%s",word2);
        int score1=comp_score(word1);
        int score2=comp_score(word2);
        if (score1>score2){
            printf("player1 wins\n");
        }
        else if (score2>score1){
            printf("player2 wins\n");
        }
        else{
            printf("tie");
        }
        return 0;
    }
    int comp_score(char word[]){
    int score=0;
    for (int i=0;i<strlen(word);i++){
        char c=toupper(word[i]);
        if (c == 'A' || c == 'E' || c == 'I' || c == 'L' || c == 'N' || c == 'O' || c == 'R' || c == 'S' || c == 'T' || c == 'U')
        score+=1;
        else if (c == 'B'|| c == 'C' || c == 'M' || c == 'P')
        score+=3;
        else if (c == 'D'|| c=='G')
        score+=2;
        else if (c == 'F' || c == 'H' || c == 'V' || c == 'W' || c == 'Y')
        score+=4;
        else if (c == 'K')
        score+=5;
        else if (c == 'J' || c == 'X')
        score+=8;
        else if (c == 'Q'|| c == 'Z')
        score+=10;  
    }
  return score;
}