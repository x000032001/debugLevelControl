#include "plus.h"

int plus5(int a)
{
	// ignored
	dprintf(DEBUG,"I'm at plus5().\n");

	// printed
	dprintf( INFO , "a = %d\n" , a );

	SET_DEBUG_LEVEL(DEBUG);
	// printed
	dprintf(DEBUG,"Exiting plus5().\n");

	SET_DEBUG_LEVEL(WARN);
	return a+5;
}
