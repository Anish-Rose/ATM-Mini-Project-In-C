#include <stdio.h>


int main(){
    //-------Time--------//
   time_t now;
   time(&now);

   //----------Var-------//
   int pin=123 , userPin , pinChances=5 , userSelection , continueTransactions=1;
   float deposit , withdraw , balance = 5000;
   system("color A");

   while(continueTransactions != 0 ){
   printf("%s \n" , ctime(&now));
   printf("Welcome To State Bank of India ATM \n\n");
   printf("1)Check Balance \n\n");
   printf("2)Withdraw\n\n");
   printf("3)Deposit \n\n");
   printf("Choose : ");
   scanf("%d" , &userSelection);



   //----------Checking For userpin----------//
      while(userPin != pin){
       printf("\nEnter your pin : ");
       scanf("%d" , &userPin);
       if(userPin != pin){
        pinChances--;
        Beep(600,500);
        printf("Invalid Pin Please try again \n");
       }
       if(pinChances <= 0){
        printf("\n--------------------Wrong Pin entered more than 5 times---------------------\n\n\n\n");
        Beep(600,500);
        exit(0);
       }
    }
    //--------------Transactions---------------//
    switch(userSelection){
    case 1 : {
    printf("\n\n------------Checking Balance------------\n\n");
    printf("BALANCE = %.2f" , balance);
    break;
    }

    case 2 : {
     printf("\n\n-----------You Choose To Withdraw Money------------\n\n");
     printf("Enter a Amount to withdraw : ");
     scanf("%f" , &withdraw);

     if(withdraw > balance){
        printf("You dont have enough money to withdraw");
        Beep(600,500);
     }
     else if(withdraw < 100){
        printf("Withdraw Amount Too Low (Min Withdraw Amount = 100) \n\n");
        Beep(600,500);
     }
     else{
        balance = balance - withdraw;
        printf("You Withdraw = %.2f \n\n" , withdraw);
        printf("Your New Balance = %.2f" , balance);
     }
     break;
    }

    case 3 : {
        printf("\n\n-----------You Choose To Deposit Money------------\n\n");
        printf("Your Current Balance is: %.2f\n\n", balance);
        printf("Enter a Amount to Deposit : ");
        scanf("%f" , &deposit);

        if(deposit < 100){
            printf("Deposit Amount Too Low (Min Deposit Amount = 100) \n\n");
            Beep(600,500);
        }
        else {
            balance += deposit ;
            printf("You Deposited = %.2f \n\n" , deposit);
            printf("Your New Balance = %.2f" , balance);
        }
        break;
     }
    default :
        printf("Invalid Selection");
        Beep(600,500);
        break;
   }
    printf("\n\nDo you need to continue Transactions 1(Yes) 0(No) : ");
    scanf("%d" , &continueTransactions);
 }
   printf("\n\n\t\t\t\t------------------------Thanks For Using State Bank of India ATM------------------------\n\n\t\t\t\t");
   return 0;
}

