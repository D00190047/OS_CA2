#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //read file valid.txt
    FILE *file = fopen("output.txt", "r");
    size_t line_size = 20;
    char line[line_size];

    // read file -- ref : https://stackoverflow.com/questions/3501338/c-read-file-line-by-line
    //check if file is not found
    if (file == NULL)
    {
        printf("\nError --- can not find valid.txt file \n");
        return 1;
    }

    while (fgets(line, line_size, file))
        {
            // remove tab at the end of string
            line[(strlen(line) - 1)] = '\0';
            printf("rgba(%s)\n",line);
        }
    printf("\n");
    fclose(file);
    return 0;
}
