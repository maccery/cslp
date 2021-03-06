//
// Created by Tom Macmichael on 16/12/2015.
//

#include "event.h"
#include "request.h"
#include "simulation.h"

void formatTime(int seconds)
{
    int hours = seconds / 3600;
    int remainder = seconds % 3600;
    int minutes = remainder / 60;
    int secs = remainder % 60;

    printf("<%d:%d:%d> <%d> ", hours, minutes, secs, seconds);
}


// creates an event

Event *createEvent(int executionTime, int (*callbackFunction)(void*), void* data)
{
    Event *event = malloc(sizeof(Event));
    event->executionTime = executionTime;
    event->callbackFunction = callbackFunction;
    event->data = data;

    return event;
}

EventQueue *head = NULL;
EventQueue *curr = NULL;

EventQueue* create(Event event)
{
    EventQueue *ptr = (EventQueue*)malloc(sizeof(EventQueue));
    if(NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    ptr->event = event;
    ptr->next = NULL;

    head = curr = ptr;
    return ptr;
}

/*
 * Executes all events at the current time of simulation
 */
void executeEvents(int executionTime) {

    EventQueue *tmp = head;
    while (tmp != NULL) {
        if (tmp->event.executionTime == executionTime) {
            formatTime(executionTime);
            tmp->event.callbackFunction(tmp->event.data);
        }

        tmp = tmp->next;
    }
}

/* Given a minibus, returns all the events for it, with an additional request on top */
Request * stopsForMinibus(Minibus *minibus, Simulation *simulation, Request *request)
{
    //printf("\nChecking which stops minibus %d needs to visit\n", minibus->id);
    Request *requests = malloc(12 * sizeof(Request*));
    requests[0] = *request;

    int i = 1;
    EventQueue *tmp = head;
    while (tmp != NULL) {
        Request *request = (Request*) tmp->event.data;
        if (request) {
        if (request->minibus) {
            if (request->minibus->id)
            {
            if (request->minibus->id == minibus->id) {
                //if(tmp->event.callbackFunction == busArrived)
                {
                    if (tmp->event.executionTime >= simulation->currentTime)
                    {
                        requests[i] = *(Request*) tmp->event.data;
                        i++;
                       // printf("Minibus %d has an upcoming stop %d, desired boarding time %d\n", minibus->id, request->startStop, request->desiredBoardingTime);

                    }
                }
            }}
        }}

        tmp = tmp->next;
    }

    for (int j = i; j <12; j++) {
        requests[j] = *Request_create(0,0,0);
    }
    return requests;
}

void removeFromEventQueue(Minibus *minibus)
{
    EventQueue *tmp = head;
    while (tmp != NULL) {
        Request *request = (Request*) tmp->event.data;
        if (request) {
            if (request->minibus) {
                if (request->minibus->id == minibus->id) {
                    tmp->event.executionTime = 0;

                }
            }
        }

        tmp = tmp->next;
    }
}

EventQueue* addToEventQueue(Event event, Simulation *simulation)
{
    if (event.executionTime == simulation->currentTime)
    {
        event.executionTime = event.executionTime+1;
    }
    printf("added to event queue for execution at %d\n", event.executionTime);
    if(NULL == head)
    {
        return (create(event));
    }

    EventQueue *ptr = (EventQueue*)malloc(sizeof(EventQueue));
    if(NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }

    ptr->event = event;
    ptr->next = NULL;

    ptr->next = head;
    head = ptr;

    return ptr;
}