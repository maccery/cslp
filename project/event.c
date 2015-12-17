//
// Created by Tom Macmichael on 16/12/2015.
//

#include "event.h"
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

EventQueue* addToEventQueue(Event event, Simulation *simulation)
{
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