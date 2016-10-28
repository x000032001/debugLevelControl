#include "Logger.h"
#include "plus.h"

int main()
{
	SET_LOG_LEVEL(DEBUG);

	// ignored
	log(DEBUG,"I'm at main().\n");


	// printed
	log(INFO,"plus5(5) = %d\n",plus5AAAABBBBCCCC(5));


	log(INFO,"You shouldn't see me\n");
	log(WARN,"Change debug Level Successful\n");

	SET_LOG_LEVEL(DEBUG);

    log(DEBUG,"QQ\n");

    log(ERROR,"Bye\n");

	log(INFO,"You shouldn't see me\n");

	return 0;
}
