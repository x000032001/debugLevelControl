#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef DEBUG_CTRL_H
#define DEBUG_CTRL_H
#define DEBUG_CTRL_CONTINUE

	#define DEBUG 1
	#define INFO  2
	#define WARN  3
	#define ERROR 4

#endif

#ifndef AUTHER_x000032001

	extern int xxxDebugLevel __attribute__((unused));

#endif

#ifdef DEBUG_CTRL_CONTINUE


#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

    #define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
	#define SET_LOG_LEVEL(x) (xxxDebugLevel=(x))

	#define log(inputLV,format,...)			\
			do { if((inputLV)>=xxxDebugLevel) {		\
                if(inputLV==DEBUG) fprintf(stderr,CYN); \
                if(inputLV==INFO) fprintf(stderr,WHT); \
                if(inputLV==WARN) fprintf(stderr,YEL); \
                if(inputLV==ERROR) fprintf(stderr,RED); \
                fprintf(stderr,"[%5d]%5s| %.8s:%3d %.10s()# " format RESET,getpid(),#inputLV,__FILENAME__,__LINE__,__func__,##__VA_ARGS__);	\
			} \
            if((inputLV)>=ERROR) { exit(__LINE__); } \
            } while(0)

#endif
