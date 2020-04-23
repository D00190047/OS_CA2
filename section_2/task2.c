#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() 
{
    //read file valid.txt
    FILE *file = fopen("valid.txt", "r");
    size_t  line_size = 20;
    char line[line_size]; 

    
     //check if file is not found
     if (file== NULL)
        {
            printf("\nError --- can not find valid.txt file \n");
            return 1;
        }

    while(fgets(line, line_size, file))
    {
        // remove everything after position 4
        line[(strlen(line)-5)] = '\0';
        //print start
        printf("%s;",&line[3]);
        
    }
    printf("\n");
    return 0;
}