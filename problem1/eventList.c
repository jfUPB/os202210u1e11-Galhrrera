#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{
    EventList *eventList = malloc(sizeof(eventList));

    return eventList;
}

void DestroyEventList(EventList *this)
{

    free(this);
}

Event *SearchEvent(EventList *this, char *name)
{

    Event *a = this->head;
    if (this->isEmpty == 0)
    {
        return NULL;
    }
    
    else
    {
       
        while (a != NULL)
        {
            if (*(a->eventName + 2) == *(name + 2) && *(a->eventName + 3) == *(name+3))
            {
                return a;
                
            }

            a = a->next;
        }
    }
    return NULL;
}

void AddEvent(EventList *this, Event *event)
{
    Event *a = this->head;

    if (this->isEmpty!=0){
        while (a != NULL)
        {
            if(*(a->eventName+2)==*(event->eventName+2)&& *(a->eventName+3)==*(event->eventName+3)){
                return;
            }

            a = a->next;
        }

        this->last->next=event;
        this->last=event;
    }
    else{
        this->head = event;
        this->last = event;
        this->isEmpty= 1;
    }
}

void RemoveEvent(EventList *this, char *name)
{
    int contador = 0;
    Event *a = this->head;
    if (this->isEmpty == 0)
    {
        return;
    }
    
    else
    {
       
        while (a != NULL)
        {
            if (*(this->head->eventName + 2) == *(name + 2))
            {
                this->head = this->head->next;
                break;
            }

            else if (*(a->next->eventName + 2) == *(name + 2))
            {

                a->next = a->next->next;


                break;
            }
            else{
                contador = contador+1;
                if(contador==7){
                    return;
                }
            }

            a = a->next;
            contador = contador+1;
        }
        if (this->head==NULL)
        {
            this->isEmpty = 0;
        }
    }
    //free(&contador);
}

void ListEvents(EventList *this)
{
    Event *a = this->head;
    
    if (this->isEmpty == 0)
        printf("empty\n");
    else
    {
        while (a != NULL)
        {
            printf("%s\n", a->eventName); // BORRAR OJO
            a = a->next;
        }
    }
}
