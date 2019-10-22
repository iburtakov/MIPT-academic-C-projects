//
// Created by Илья on 08.10.2019.
//

#ifndef ENCYCLOPEDIA_FILEIO_H
#define ENCYCLOPEDIA_FILEIO_H



#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


int fileSize (FILE *file);

int textInLines (char **text, int textSize);

int foutputText (char **text, const char *name = "out.txt");

char **createTextCopy (char **text, int lines);

char **createText (char *buf, int lines, int textSize);

char **createTextFromFile (const char *fileName, int *currentFileSize = 0,
                           int *currentFileLines = 0);


#endif //ENCYCLOPEDIA_FILEIO_H
