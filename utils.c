#include <stdio.h>
#include <stdlib.h>

void error(char* message){
    printf("An Error Has Occurred\n");
    printf("%s\n", message);
    exit(1);
}

double** new_matrix(int r, int c){
    double** matrix = (double**)malloc(sizeof(double*)*r);
    int i = 0;
    int j = 0;

    if(NULL == matrix){
        error("malloc() failed in matrix");
    }
    for(i=0; i < r; i++){
        matrix[i] = (double*)malloc(sizeof(double)*c);
        if(NULL == matrix[i]){
            error("malloc() failed in matrix[i]");
        }
        for(j = 0; j < c; j++){
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

void free_matrix(double** matrix, int r){
    int i = 0;

    if(NULL != matrix){
        for(i=0; i < r; i++){
            if(NULL != matrix[i]){
                free(matrix[i]);
            }
        }
        free(matrix);
    }

}

void get_matrix_file_dimensions(char* filename, int* rows, int* columns)
{
    FILE* f = NULL; 
    char c = '\0';
    int rows_temp  = 0;
    int columns_temp = 0;

    f = fopen(filename, "r");
    if (NULL == f)
    {
        error("Can't open input file.");
    }

    c = getc(f);

    if (EOF == c)
    {
        *rows = 0;
        *columns = 0;
        return;
    }

    while(EOF != c && '\n' != c)
    {
        if (',' == c)
        {
            columns_temp++;
        } 
        c = getc(f);
    }

    /* Amount of commas is one less than the columns amount. */
    columns_temp++;

    /* Already read first row. */
    if (c == '\n') rows_temp++;
    
    c = getc(f);
    while(EOF != c)
    {
        if ('\n' == c)
        {
            rows_temp++;
        }
        c = getc(f);
    }

    fclose(f);

    *rows = rows_temp;
    *columns = columns_temp;
}

/* double** read_matrix_file(char* filename)
 {
     double** matrix = new_matrix()
 }*/