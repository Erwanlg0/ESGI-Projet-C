#ifndef __PARSE_H__
#define __PARSE_H__

#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 10000

char *file_to_buffer(FILE *file, char *buffer);
char *is_language(char *buffer, char language[3]);
int is_valid_language(char *language);

#endif
