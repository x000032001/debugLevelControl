#include "plus.h"

int plus5AAAABBBBCCCC(int a)
{
	// ignored
	log(DEBUG,"I'm at plus5().\n");

	// printed
	log( INFO , "a = %d\n" , a );

	SET_LOG_LEVEL(DEBUG);
	// printed
	log(DEBUG,"Exiting plus5().\n");

	SET_LOG_LEVEL(WARN);
	return a+5;
}
