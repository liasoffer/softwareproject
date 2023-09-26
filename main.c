#include <stdio.h>
#include "utils.h"

#define GOAL_INDEX (1)
#define FILE_NAME_INDEX (2)

int main(int argc, char** argv){
    int r, c = 0;

    if(argc < 3){
        error("Not enough arguments.");
    }
    
    get_matrix_file_dimensions(argv[FILE_NAME_INDEX], &r, &c);
    printf("Dimensions: %dx%d\n", r, c);

    return 0; 

    /*if (strcmp(argv[GOAL_INDEX], "sym") == 0) 
    {
        sym();
    } 
    else if (strcmp(argv[GOAL_INDEX], "ddg") == 0)
    {
        ddg();
    }
    else if (strcmp(argv[GOAL_INDEX], "norm") == 0)
    {
        norm();
    }
    else {
        error();
    }*/
}