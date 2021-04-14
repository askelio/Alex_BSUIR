
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <malloc.h>
#include <conio.h>

void print_wrds(char *words, int size) 
{
    int i = 0;
    char temp;
    int word_size=0;
    int t_word_size = 0;
    
    

    temp = words[i];
    
    while (i<size)
    {
        
        if (words[i]!=' ' && words[i]!= ',' && words[i] != '.' && words[i] != ';' && words[i] != '!' && words[i] != '?' && words[i] != "\n")
        {
            word_size++;
            
        }
        else
        {        
            
            int k = i - word_size;
            if (words[k]<=90 && words[k]>=65)
            {
                
            }
            for (int m = i- word_size; m < i; m++)
            {
                int bl = 0;
                if (words[m] <= 90 && words[m] >= 65)
                {
                    words[m] += 32;
                    bl = 1;
                }
                if (words[m] < words[m + 1])
                {
                    t_word_size++;
                }
                if (bl==1)
                {
                    words[m] -= 32;
                }
                
                
            }
                     
            
            if (t_word_size == word_size-1)
            {
                for (int k = i - word_size; k < i; k++)
                {
                    printf("%c",words[k]);
                }
                printf("\n");
            }
            
            word_size = 0;
            t_word_size = 0;
        }
        i++;
    }
    

}

int main()
{
    
    
    
    
    int i = 0;
    char str[80], ch;
    puts("\nEnter the text: ");
    while ((ch = getchar()) != '\n') {
        
        str[i++] = ch;
    }
    str[i] = ' ';
    str[++i] = '\0'; 
    
    print_wrds(str,i);
   

}

