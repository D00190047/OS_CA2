#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define MIN 0

int main()
{
    //read file valid.txt
   // https://www.w3resource.com/c-programming-exercises/file-handling/c-file-handling-exercise-4.php
    FILE *file = fopen("access.moreThan5.txt", "r");
    size_t line_size = 20;
    char line[line_size];
    char portfolio[15] = "/portfolio";
    char videos[10] = "/videos";

    //pf = portfolio, vid = videos
    int total_pf_rq = 0, total_vid_rq = 0, total_pf_time = 0, total_vid_time = 0, avg_pf_time = 0, avg_vid_time = 0;
    int shortest_pf_time = MAX, longest_pf_time = MIN, shortest_vid_time = MAX, longest_vid_time = MIN;
    char *pf_time, *vid_time;

    //check if file is not found
    if (file == NULL)
    {
        printf("Error --- could not locate file\n");
        return 1;
    }

    while (fgets(line, line_size, file))
    {
        // remove tab at the end of string
        line[(strlen(line) - 1)] = '\0';
        //check if line equals to portfolio
        //https://stackoverflow.com/questions/12784766/check-substring-exists-in-a-string-in-c/12784812
        if (strstr(line, "/portfolio") != NULL)
        {
            pf_time = &line[(strlen(line) - 2)];
            
            //count the number of request
            total_pf_rq++;

            //get shortest time
            if (atoi(pf_time) < shortest_pf_time)
            {
                shortest_pf_time = atoi(pf_time);
            }
            //get longest time
            if (atoi(pf_time) > longest_pf_time)
            {
                longest_pf_time = atoi(pf_time);
            }
            total_pf_time += atoi(pf_time);
        }
        //check if line equals to videos
        else if (strstr(line, "/videos") != NULL)
        {
            vid_time = &line[(strlen(line) - 2)];
            total_vid_rq++;
            if (atoi(vid_time) < shortest_vid_time)
            {
                shortest_vid_time = atoi(vid_time);
            }
            if (atoi(vid_time) > longest_vid_time)
            {
                longest_vid_time = atoi(vid_time);
            }
            total_vid_time += atoi(vid_time);
        }
    }

    printf("\nRequest path: %s\n", portfolio);
    //printf("%d\n", total_pf_time);
    printf("Total number of request: %d\n", total_pf_rq);
    printf("Shortest processing time: %d\n", shortest_pf_time);
    printf("Longest processing time: %d\n", longest_pf_time);
    avg_pf_time = total_pf_time / total_pf_rq;
    printf("Average processing time: %d\n", avg_pf_time);

    printf("\n");

    printf("Request Path: %s\n", videos);
    //printf("%d\n", total_vid_time);
    printf("Total number of request: %d\n", total_vid_rq);
    printf("Shortest processing time: %d\n", shortest_vid_time);
    printf("Longest processing time: %d\n", longest_vid_time);
    avg_vid_time = total_vid_time / total_vid_rq;
    printf("Average processing time: %d\n", avg_vid_time);

    fclose(file);
    return 0;
}