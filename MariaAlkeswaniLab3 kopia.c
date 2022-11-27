#include <stdio.h>
#include <math.h>


int main(int argc, char** argv) {
  double i;
  
  while(i)
  { 
    printf("Enter an option: ");
   scanf("%lf",&i);
  
     if (i <= 4)
     {
     int number1, number2;  
     int summation, subtraction, multiplication, division;
      printf("Enter two integers\n");
     scanf("%d%d", &number1, &number2);
     summation = number1 + number2;
     subtraction = number1 - number2;
     multiplication = number1 * number2;
     division = number1 / number2;

     printf("The summation of %d and %d are %d\n",number1, number2, summation);
     printf("The subtraction of %d and %d are %d\n",number1, number2, subtraction);
     printf("The multiplication of %d and %d are %d\n",number1, number2, multiplication);
     printf("The division of %d and %d are %d\n",number1, number2, division);
        
     }   
     else if (i==5)
     {
     double nummer;
     double squareroot;
     printf("Enter a nummer ");
     scanf("%lf", &nummer);
     squareroot = sqrt(nummer);

     printf("The square root of %.3lf are %.3lf\n",nummer,squareroot);
   
     }
     else if (i==6)
     {
     int first_number, second_number;
     long long result = 1;
     printf("The base nummer: ");
     scanf("%d",&first_number);
     printf("The power nummer: ");
     scanf("%d",&second_number);

     while(second_number != 0) {
     result *= first_number;
     --second_number;
     }
     printf("The answer is %lld\n",result);

     }
     else if (i==7)
     {
     int x, n;
     float num[100], sum= 0.0 , average;
     printf("Enter the numbers of elements: ");
     scanf("%d", &n);
       for (x = 0; x<n ;++x){
       printf("%d. Enter number:\n",x + 1);
        scanf("%f", &num[x]);
        sum += num[x];
     }
      average = sum / n;
     printf("Average = %.2f\n", average);
     }
     else if (i==8)
     {
       printf("exit");
     break;
     }
 continue;
  }

 return 0;
}
