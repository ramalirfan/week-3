int main(){
int amount;
int coins=0;
printf("enter amount in cents");
scanf("%d",&amount);
coins+=amount/25;
amount=amount%25;
coins+=amount/10;
amount=amount%10;
coins+=amount/5;
amount=amount%5;
coins+=amount/1;
printf("minimum coins needed:%d\n",coins);
return 0;
}