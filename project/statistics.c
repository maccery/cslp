//
// Created by Tom Macmichael on 17/12/2015.
//

#include <assert.h>
#include <stdlib.h>
#include "statistics.h"

Statistics *Statistics_create() {
    Statistics *statistics = malloc(sizeof(Statistics));
    assert(statistics != NULL);

    statistics->tripTotalLength = 0;
    statistics->totalTrips = 0;
    statistics->totalMissed = 0;
    statistics->totalWaitingTime = 0;
    statistics->totalRequests = 0;

    return statistics;
}

int averageDuration(Statistics *statistics) {
    return statistics->tripTotalLength / statistics->totalTrips;
}

float averageOccupancy(Statistics *statistics) {
    return 1.00;
}

int averageWaitingTime(Statistics *statistics) {
    return statistics->totalWaitingTime / statistics->totalTrips;
}

float percentageMissed(Statistics *statistics) {
    return statistics->totalMissed * 100 / statistics->totalRequests;
}

void formatTimeToMins(int seconds)
{
    int hours = seconds / 3600;
    int remainder = seconds % 3600;
    int minutes = remainder / 60;
    int secs = remainder % 60;

    printf("%d:%d", minutes, secs);
}


void printStatistics(Statistics *statistics)
{
    printf("\n---\naverage trip duration ");
    formatTimeToMins(averageDuration(statistics));
    printf("\n");

    printf("trip efficiency %f\n", averageOccupancy(statistics));

    printf("percentage of missed requests %f\n", percentageMissed(statistics));

    printf("average waiting time %d seconds\n", averageWaitingTime(statistics));

    printf("average trip deviation 0.00\n---\n");

}