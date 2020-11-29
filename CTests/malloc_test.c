#include <stdlib.h>
#include "spike_util.c"

// Default nosys implementation of _sbrk
void *
_sbrk (incr)
     int incr;
{
   extern char   end; /* Set by linker.  */
   static char * heap_end;
   char *        prev_heap_end;

   if (heap_end == 0)
     heap_end = & end;

   prev_heap_end = heap_end;
   heap_end += incr;

   return (void *) prev_heap_end;
}

int main() {

    int *i = malloc(sizeof(int));
    *i = 1;
    
    int j = *i;
    free(i);

    __spike_return(j);
}
