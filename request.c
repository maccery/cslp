//
// Created by Tom Macmichael on 19/11/2015.
//
#include "request.h"

/**
 * Creates a request struct
 */
struct Request *Request_create(int startStop, int destinationStop, int desiredBoardingTime) {
    // Allocate enough memory to create a new struct and check we have enough memory
    struct Request *request = malloc(sizeof(struct Request));
    assert(request != NULL);

    request->startStop = startStop;
    request->destinationStop = destinationStop;
    request->desiredBoardingTime = desiredBoardingTime;

    return request;
}

/**
 * Frees the memory of a given request struct
 */
void Request_destroy(struct Request *request) {
    assert(request != NULL);
    free(request);
}

/**
 * Generates a random request
 */
struct Request* Request_random(int numberOfBusStops) {

    // Generates a number between 0 and the largest bus stop number (numberOfBusStops)
    int startStop = rand() % numberOfBusStops;
    int destinationStop = rand() % numberOfBusStops;

    // Generates a random boarding time
    int desiredBoardingTime = 0000;

    return Request_create(startStop, destinationStop, desiredBoardingTime);
}