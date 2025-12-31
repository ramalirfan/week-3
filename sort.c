#include <stdio.h>
int main (){
    int numbers[10];
    int n;
    printf("enter list of numbers");
    scanf("%d",&n);
    for (int i = 0;i < n;i++){
        printf("Number %i: ", i + 1);
        scanf("%d",&numbers[i]);
    }
    for (int i = 0;i < n-1;i++){
        for(int j = 0;j < n-i-1;j++){
            if(numbers[j]>numbers[j+1]){
                int temp = numbers[j];
                numbers[j]=numbers[j+1];
                numbers[j+1]=temp;
            }
        }
    }
    
    printf("sorted numbers: ");
    for (int i = 0;i < n;i++){
        printf("%d",numbers[i]);
    }
    printf("\n");
    return 0;
}