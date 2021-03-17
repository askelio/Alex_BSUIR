#include <stdio.h> 
#include <math.h>
#include <conio.h>
#include "App.h"

long int fact (int m)
{
  return (m < 2) ? 1 : m * fact (m - 1);
}
int get_num(double x, double calc_error)
{
     int n=0;
    double sum=0;
    double del=0;  

    while (1)
    {
        n++;
        sum=sum+pow((-1),(n-1))*pow(x,(2*n-1))/fact(2*n-1);        
        printf("%d",n);
        printf("\n");
        del=sum-sin(x);
        if (del<0)
        {
            del*=-1;
        }
        
        if (del<calc_error)
        {            
            return n;
        }        
        
    }
}

int main()
{
    double calc_error=0;
    double x=0;
    printf("Enter the calculation error: ");
    scanf("%Lf",&calc_error);

    printf("Enter the X: ");
    scanf("%Lf",&x);    
    
    if (calc_error>sin(x))
    {
        printf("The calculation error is too large");
        return 0;
    }
    get_num(x,calc_error);    
      
    
    getch();
    return 0;   

}