#ifndef UTILS_H
#define UTILS_H

void error(char* message);

double** new_matrix(int r, int c);

void free_matrix(double** matrix, int r);

void get_matrix_file_dimensions(char* filename, int* r, int* c);

#endif