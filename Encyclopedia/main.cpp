//------------------------------------------------------------------------------
/*!
//  \file Encyclopedia of Russian life.cpp
//
//
//  \brief Main file which contains main body of the program
*/
/*!
//  \mainpage Description

// - main.cpp
// - FileIO.cpp
// - Sort.cpp
//
//  \author Ilya Burtakov
//  \version 1.0
//  \date October 2019
//
//  This project gets text from file, sort its lines  by alphabet, by the end by
//  alphabet, and then inputes sorted texts and its (inputed) copy
*/
//------------------------------------------------------------------------------
#define DEBUG

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "UNITTESTS.h"
#include "FileIO.h"
#include "Sort.h"


int main ()
{
    printf (" # Hello, this program sort lines, ignoring not letters from\n"
            " # file NAMEIN and put the sorted lines into file NAMEOUT\n");

    printf (" # Press any button if you want to start\n");
    //char startProgram = getchar();

    /* creates text parameters */
    int tSize = 0;
    int tLines = 0;

    /* creates text and finds it's size and lines */
    char **text = createTextFromFile ("Input.txt", &tSize, &tLines);

    //UNITTEST
    UNITTEST(tSize, ==, 28381);
    UNITTEST(tLines, ==, 756);
    //UNITTEST

    /* creates a copy of the text */
    char **textCopy = createTextCopy (text, tLines);

    /* remembers the text seen in line */
    char *buf = text[0];

    /* sorts text by alphabet */
    qsort(text, tLines, sizeof (text), strCompare);

    /* outputs sorted text into .txt file */
    int checkFirst = foutputText(text, "FullEndFile.txt");
    assert (checkFirst == 0);

    /* sorts text by it's end */
    qsort(text, tLines, sizeof (text), strCompareFromEnd);

    /* outputs text into .txt file*/
    int checkEnd = foutputText (text, "FullEndFile.txt");
    assert (checkEnd == 0);

    /* outputs created copy into .txt file */
    int checkCopy = foutputText (textCopy, "FullEndFile.txt");
    assert (checkCopy == 0);


    /* frees used memory */
    memset (text, 0, tLines);
    free (text);
    text = NULL;

    memset (textCopy, 0, tLines);
    free (textCopy);
    textCopy = NULL;

    memset (buf, 0, tSize);
    free (buf);
    buf = NULL;

    printf (" # Sorting has succeeded\n");

    return 0;
}
