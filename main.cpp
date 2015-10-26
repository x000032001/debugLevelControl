#include "debugCtrl.h"
#include "plus.h"

int main()
{
	SET_DEBUG_LEVEL(INFO);

	// ignored
	dprintf(DEBUG,"I'm at main().\n");


	// printed
	dprintf(INFO,"plus5(5) = %d\n",plus5(5));

	dprintf(INFO,"You shouldn't see me\n");
	dprintf(WARN,"Change debug Level Successful\n");

	return 0;
}
