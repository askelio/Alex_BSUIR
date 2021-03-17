#include <stdio.h>
#include <stdlib.h>
#include "App2.h"

struct eurotrans
{
	int ves;
	int distance;
};

int get_info(struct eurotrans* x)
{
	int n_mach;
	int summ;
	int allsumm;

	n_mach = x->ves / 20;
	if (n_mach > 15)
	{ 	printf("Error, the company cant take this request, need more machines\n");
		return 0;
	}

	printf("The number of machine(s) are (is) %d\n",n_mach);

	allsumm = x->distance * 2;
	summ = 0.05 * allsumm;
	printf("The whole summ is : %d \n", allsumm);
	printf("The insurance amount is : %d\n", summ);

	printf("Do you want to get info about author? 1 - YES, 0 - NO\n");
	int ans = 0;
	scanf("%d", &ans);
	if (ans == 1)
	{
			
		printf("MADE BY ALEX ");
		return 0;
			
	}
				
	if (ans == 0)
	{
		return 0;
	}			
		
};


int main()
{
	struct  eurotrans* x;
	
	x = (struct eurotrans*)calloc(1, sizeof(struct eurotrans));
	printf("Set the weight of the cargo in tonns:\n");
	scanf("%d", &x->ves);
	
	
	if ((x->ves) < 50)
	{
		printf("Error, the company can't take this request \n");
		return 0;
	}

	printf("Set the distance :\n");
	scanf("%d", &x->distance);
	if ((x->distance) > 4000)
	{
		printf("Error, the company can't take this request \n");
		return 0;
	}	
	else
	{
		get_info(x);
	}	
	
	return 0;
}