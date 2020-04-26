#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //read file valid.txt
    FILE *file = fopen("output.txt", "r");
    size_t line_size = 20;
    char line[line_size];
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
        //get red value
        red[(strlen(red) - 10)] = '\0';
        // how to convert to hex https://stackoverflow.com/questions/10156409/convert-hex-string-char-to-int  
        const char *hexstring_r = red;
        int red_dec = (int)strtol(hexstring_r, NULL, 16);
        printf(" r = %d ", red_dec);

        //get green value into dec
        strncpy(green, &line[3], line_size);
        green[(strlen(green) - 7)] = '\0';
        //printf("rgba(%s)\n",green);
        const char *hexstring_g = green;
        int green_dec = (int)strtol(hexstring_g, NULL, 16);
        printf("g = %d\n", green_dec);

        //int dec_red = hex2int(red,2);
        //printf("%d\n",dec_red);
    }
    // printf("rgba(%s)\n",red);
    printf("\n");
    fclose(file);
    free(red);
    return 0;
}

// // Taken from Ref -- https://stackoverflow.com/questions/10324/convert-a-hexadecimal-string-to-an-integer-efficiently-in-c
// int hex2int(char *a, unsigned int len)
// {
//     int i = 0;
//     int val = 0;

//     //printf("%s\n",a);
//     for (i = 0; i < len; i++)
//     {
//         if (a[0] <= 57)
//         {
//             val += (a[i] - 48) * (1 << (4 * (len - 1 - i)));
//             printf("%d\n", &val);
//         }
//         else
//         {
//             val += (a)[i] - 55) * (1 << (4 * (len - 1 - i)));
//             printf("%d\n", val);
//         }
//     }

//     return val;
// }
