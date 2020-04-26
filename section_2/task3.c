#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

int main()
{
    //read file valid.txt
    FILE *file = fopen("output.txt", "r");
    size_t line_size = 20;
    char line[line_size];
    // arrays to store each hex value red, green...
    char *red = malloc(line_size);
    char *green = malloc(line_size);
    char *blue = malloc(line_size);
    char *alpha = malloc(line_size);

    // read file -- ref : https://stackoverflow.com/questions/3501338/c-read-file-line-by-line
    //check if file is not found
    if (file == NULL)
    {
        printf("\nError --- can not find valid.txt file \n");
        return 1;
    }

    while (fgets(line, line_size, file))
    {
        // need to convert to decimal for each and get sum , if sum is <= 255 * 4 it is valid
        // remove tab at the end of string
        strncpy(red, line, line_size);
        // ----------------- get red value
        red[(strlen(red) - 10)] = '\0';
        // how to convert to hex https://stackoverflow.com/questions/10156409/convert-hex-string-char-to-int
        const char *hexstring_r = red;
        int ishex_r;
        //compile regex
        regex_t regex;
        int tot_line_dec = 0;
        int invalid =1;

        ishex_r = regcomp(&regex, "[0-9][0-9]", 0);
        ishex_r = regexec(&regex, hexstring_r, 0, NULL, 0);
        if (ishex_r == REG_NOMATCH)
        {
            int red_dec = (int)strtol(hexstring_r, NULL, 16);
           //printf("r = %d", red_dec);
            if(red_dec<= 255 && red_dec>0)
            {
                invalid =0;
            }
        }
        else
        {
            int red_dec = atoi(hexstring_r);
            //printf("r = %d ", red_dec);
            if(red_dec<= 255 && red_dec>0)
            {
                invalid =0;
            }
            
        }
        // ----------------- get green value
        //get green value into dec
        strncpy(green, &line[3], line_size);
        green[(strlen(green) - 7)] = '\0';
        //printf("rgba(%s)\n",green);
        const char *hexstring_g = green;
        //check if value contains letter
        int ishex_g;
        //compile regex
        ishex_g = regcomp(&regex, "[0-9][0-9]", 0);
        ishex_g = regexec(&regex, hexstring_g, 0, NULL, 0);
        if (ishex_g == REG_NOMATCH)
        {
            int green_dec = (int)strtol(hexstring_g, NULL, 16);
            //printf(" g = %d ", green_dec);
            if(green_dec<= 255 && green_dec>0)
            {
                invalid =0;
            }
            
        }
        else
        {
            int green_dec = atoi(hexstring_g);
            //printf(" g = %d ", green_dec);
            if(green_dec<= 255 && green_dec>0)
            {
                invalid =0;
            }
            
        }
        // ----------------- get blue value

        //get green value into dec
        strncpy(blue, &line[6], line_size);
        blue[(strlen(blue) - 3)] = '\0';
        //printf("rgba(%s)\n",green);
        const char *hexstring_b = blue;
        //check if value contains letter
        int ishex_b;
        //compile regex
        ishex_b = regcomp(&regex, "[0-9][0-9]", 0);
        ishex_b = regexec(&regex, hexstring_b, 0, NULL, 0);
        if (ishex_b == REG_NOMATCH)
        {
            int blue_dec = (int)strtol(hexstring_g, NULL, 16);
            //printf("b = %d", blue_dec);
            if(blue_dec<= 255 && blue_dec>0)
            {
                invalid =0;
            }
            
        }
        else
        {
            int blue_dec = atoi(hexstring_g);
            //printf(" b = %d", blue_dec); 
            if(blue_dec<= 255 && blue_dec>0)
            {
                invalid =0;
            }
           
        }

        // ----------------- get alpha value

        //get green value into dec
        strncpy(alpha, &line[6], line_size);
        alpha[(strlen(alpha) - 3)] = '\0';
        //printf("rgba(%s)\n",green);
        const char *hexstring_a = alpha;
        //check if value contains letter
        int ishex_a;
        //compile regex
        ishex_a = regcomp(&regex, "[0-9][0-9]", 0);
        ishex_a = regexec(&regex, hexstring_a, 0, NULL, 0);
        if (ishex_a == REG_NOMATCH)
        {
            int alpha_dec = (int)strtol(hexstring_g, NULL, 16);
            //printf(" a = %d\n", alpha_dec);
            if(alpha_dec<= 255 && alpha_dec>0)
            {
                invalid =0;
            }
       
        }
        else
        {
            int alpha_dec = atoi(hexstring_g);
            //printf(" a = %d\n", alpha_dec);        
            if(alpha_dec<= 255 && alpha_dec>0)
            {
                invalid =0;
            }
           
        }
        //printf("%d\n",tot_line_dec);
        if(invalid==0)
        {
            line[(strlen(line)-1)] = '\0';
            printf("rgba(%s)\n",line);
        }
    }

    printf("\n");
    fclose(file);
    free(red);
    return 0;
}
