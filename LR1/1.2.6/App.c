
#include "App.h"
#include <stdio.h>
#include <conio.h>
#include <math.h>

/* 
	Getting the first three numbers after the dot 
*/
int Get_Sum(float num)
{
	int a;
	if (num<0)
	{
		num=-num;
	}
	a = round(num*1000);
	
	int s = 0;
	int i; 
	for( i = 0 ; i < 3; i++)
	{
		s += a % 10;
		a-=a%10;
		a /= 10;
	}
	return s;

}

int main()
{
	printf("Set the number:\n");
	float n;
	scanf("%f",&n);
	
	int Sum=Get_Sum(n);
	

	printf("The sum of the first three numbers after the dot: ");
	printf("%d",Sum);
    getch();
	return 0;
}
