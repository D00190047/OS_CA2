#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() 
{
     

    FILE *file = fopen("colours.txt", "r");
    // var to store line size
    size_t size;
    //max size of line
    size_t line_size = 20;
    //array to store valid rgb values 
    char* line = malloc(line_size);
   
   	
  
    //check if file is not found
     if (file== NULL)
        {
            printf("\nError --- can not find colours.txt file \n");
            return 1;
        }
    // read lenght of lines -- ref : https://stackoverflow.com/questions/3501338/c-read-file-line-by-line
      while ((size = getline(&line, &line_size, file)) != -1) {
          // remove tab at the end of string
          line[(strlen(line)-1)] = '\0';
          if(size == 10)
          {
                printf("%s\n", line); 
               
          }
          if(size == 8)
          {
                printf("%sff\n", line); 
             
          }      
       
    }
    // close and free memory
   free(line);
   fclose(file);
    return 0;
}
