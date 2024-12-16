#ifndef __PARSE_H__
#define __PARSE_H__

#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 10000

char *get_language(FILE *file, char language[3]);
int check_language(char *language);
char *get_music(FILE *file, char *music);
int check_music(char *music);
char *get_difficulty(FILE *file, char *difficulty);
int check_difficulty(char *difficulty);
int *get_width(FILE *file, int *width);
int check_width(int *width);
int *get_height(FILE *file, int *height);
int check_height(int *height);

#endif
