#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size = 100;
	char arr[100][100];
	FILE* fp;
	fp = fopen("C:\\Users\\Alex\\source\\repos\\lr4_2\\text.txt","rt");
	if (fp==NULL)
	{
		printf("File have not opened");
		
	}
	rewind(stdin);
	fseek(fp,0,SEEK_SET);

	
	int i = 0;
	int w_num = 0;
	
	char m;
	while ((arr[w_num][i] = fgetc(fp)) != EOF) {
		if (arr[w_num][i] == '\n')
		{
			arr[w_num][i] = '\0';
			
			w_num++;
			i = 0;
		}
		else i++;
	}
	i = 0;

	printf("Text before:\n");
	printf("\n");
	for (int i = 0; i < w_num; i++)
	{
		printf("%s", arr[i]);
		printf("\n");
	}
	printf("\n");
	printf("\n");
	printf("Text after:\n");
	printf("\n");

	char temp;
	int j = 0;
	int w_size=0;
	
	for (int i = 0; i < w_num; i++)
	{
		while (arr[i][j]!='\0')
		{
			
			j++;
		}
		for (int k = j-1; k>0; k--)
		{
			
			if (k-i>0)
			{
				temp = arr[i][k];
				arr[i][k] = arr[i][k - 1 - i];
				arr[i][k - 1 - i] = temp;
			}
			
		}
		for (int k = 0; k <= j-1; k++)
		{
			printf("%c",arr[i][k]);
			
		}
		printf("\n");
		j = 0;
		
	}
}

