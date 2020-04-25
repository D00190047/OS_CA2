#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //read file valid.txt
    FILE *file = fopen("colours.txt", "r");
    size_t line_size = 20;
    //array to store valid rgb values
    char *line = malloc(line_size);
    size_t size;
    // read file -- ref : https://stackoverflow.com/questions/3501338/c-read-file-line-by-line
    //check if file is not found
    if (file == NULL)
    {
        printf("\nError --- can not find task2.txt file \n");
        return 1;
    }

    while ((size = getline(&line, &line_size, file)) != -1)
    {
        // remove tab at the end of string
        line[(strlen(line) - 1)] = '\0';
        if (size == 10)
        {
            printf("%s\n", line);
            // ++i;
        }
        if (size == 8)
        {
            printf("%sff\n", line);
            //++i;
        }
    }
    printf("\n");
    fclose(file);
    free(line);
    return 0;
}