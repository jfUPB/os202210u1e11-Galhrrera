#include "event.h"
#include <string.h>
#include <stdlib.h>

Event *CreateEvent(char *name)
{
    //Event *event = NULL;
    Event *event = malloc(sizeof(Event));

    //malloc con la cantidad de memoria que ocupa el evento

    
    return event;
}

void DestroyEvent(Event *this)
{
    free(this);
}
