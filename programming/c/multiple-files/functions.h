#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "field.h"

void init_field(field *f, int nx, int ny);
void laplacian(field *f);
void print_field(field *f);

#endif
