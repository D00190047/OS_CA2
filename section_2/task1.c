#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() 
{
     

    FILE *file = fopen("colours.txt", "r");
    //array to store valid rgb values 
    size_t size;
    size_t line_size = 20;
    char* line = malloc(line_size);
    // to check valid rgb count
    //int i=0;
   	
  
    //check if file is not found
     if (file== NULL)
        {
            printf("\nError --- can not find colours.txt file \n");
            return 1;
        }
    // read lenght of lines -- ref : https://stackoverflow.com/questions/3501338/c-read-file-line-by-line
      while ((size = getline(&line, &line_size, file)) != -1) {
          line[(strlen(line)-1)] = '\0';
          if(size == 10)
          {
                printf("%s\n", line); 
               // ++i;
          }
          if(size == 8)
          {
                printf("%sff\n", line); 
                //++i;
          }      
       
    }
   //printf("valid lines = %d\n",i);
   free(line);
   fclose(file);

}
