//
// Created by Tom Macmichael on 19/11/2015.
//

#ifndef CSLP_PARSER_H
#define CSLP_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

#define MATRIX_WIDTH 12
#define MATRIX_HEIGHT 12

typedef struct ParsedFile {
    int busCapacity;
    int boardingTime;
    double requestRate;
    float pickupInterval;
    int maxDelay;
    int noBuses;
    int noStops;
    int stopTime;
    int map[MATRIX_HEIGHT][MATRIX_WIDTH]; // Max size of the map is 6x6
    struct Graph* graph;
    int edgeCount;
} ParsedFile;

ParsedFile *ParsedFile_create(int busCapacity, int boardingTime, float requestRate, float pickupInterval,
                                     int maxDelay, int noBuses, int noStops, int stopTime);
void ParsedFile_destroy(ParsedFile *file);
void ParsedFile_print(ParsedFile *file);
void ParsedFile_mapPrint(ParsedFile *file);
void printParsedFile(ParsedFile *parsedFile);
ParsedFile * parseFile(FILE *file);

#endif //CSLP_PARSER_H
