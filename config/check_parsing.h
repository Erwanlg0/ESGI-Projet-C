#ifndef __CHECK_PARSING_H__
#define __CHECK_PARSING_H__

#include <stdio.h>
#include <stdlib.h>

int check_config(FILE *file, char *language, char *difficulty, char *music);
int check_win_size(FILE *file, int *width, int *height);

#endif
