#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    //read file valid.txt
    FILE *file = fopen("access.moreThan5.txt", "r");
    size_t line_size = 20;
    char line[line_size];
    int total_p = 0, total_v = 0;
    int total_p_time = 0, total_v_time = 0, avg_p_time, avg_v_time, shortest_p_time = MAX, longest_p_time, shortest_v_time = MAX, longest_v_time;
    char *p_time;
    char *v_time;

    //check if file is not found
    if (file == NULL)
    {
        printf("\nError --- can not find task2.txt file \n");
        return 1;
    }

    while (fgets(line, line_size, file))
    {
        // remove tab at the end of string
        //gets rid of new line
        line[(strlen(line) - 1)] = '\0';
        //check line equals to portfolio
        if (strstr(line, "/portfolio") != NULL)
        {

            p_time = &line[(strlen(line) - 2)];

            total_p++;

            if (atoi(p_time) < shortest_p_time)
            {
                shortest_p_time = atoi(p_time);
            }
            if (atoi(p_time) > longest_p_time)
            {
                longest_p_time = atoi(p_time);
            }

            total_p_time += atoi(p_time);
        }
        //check line equals to videos
        else if (strstr(line, "/videos") != NULL)
        {
            v_time = &line[(strlen(line) - 2)];
            total_v++;

            if (atoi(v_time) < shortest_v_time)
            {
                shortest_v_time = atoi(v_time);
            }
            if (atoi(v_time) > longest_v_time)
            {
                longest_v_time = atoi(v_time);
            }

            total_v_time += atoi(v_time);
        }
    }

    printf("Request Path: /portfolio\n");
    //printf("%d\n", total_p_time);
    printf("Total number of request: %d\n", total_p);
    avg_p_time = total_p_time / total_p;
    printf("Average processing time: %d\n", avg_p_time);
    printf("Shortest processing time: %d\n", shortest_p_time);
    printf("Longest processing time: %d\n", longest_p_time);

    printf("\n");

    printf("Request Path: /videos\n");
    //printf("%d\n", total_v_time);
    printf("Total number of request: %d\n", total_v);
    avg_v_time = total_v_time / total_v;
    printf("Average processing time: %d\n", avg_v_time);
    printf("Shortest processing time: %d\n", shortest_v_time);
    printf("Longest processing time: %d\n", longest_v_time);

    //printf("%d\n %d;", total_p, total_v);
    //  printf("%d\n %d;", total_p_time, total_v_time);
    printf("\n");
    fclose(file);
    return 0;
}