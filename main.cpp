#include "debugCtrl.h"
#include <dlfcn.h>

typedef int (*func_t)(int);

int main()
{
	dprintf(DEBUG,"I'm at main().\n");

	SET_DEBUG_LEVEL(INFO);

	void* dlhandle = dlopen( "./plus.so" , RTLD_LAZY );

	if( !dlhandle )
	{
		fputs( dlerror() , stderr );
		return 1;
	}


	func_t func = (func_t) dlsym( dlhandle , "plus5" );

	char* error = NULL;
	if( (error = dlerror()) != NULL )
	{
		fputs( error , stderr );
		return 2;
	}
	
	dprintf(INFO,"plus5(5) = %d\n",(*func)(5));

	return 0;
}
