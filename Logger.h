#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>

#ifndef DEBUG_CTRL_H
#define DEBUG_CTRL_H

        #define DEBUG 1
        #define INFO  2
        #define WARN  3
        #define ERROR 4
        #define CRIT  5

        extern int xxxDebugLevel __attribute__((unused));

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

    #define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

    #define SET_DEBUG_LEVEL(x)  (xxxDebugLevel=(x))
    #define GET_DEBUG_LEVEL()   (xxxDebugLevel)

#ifndef PRODUCTION
/* colorful message and print to stderr */
        #define open_slog(x)    ((void)0)
        #define slogf(inputLV,format,...)                       \
                do { if((inputLV)>=xxxDebugLevel) {             \
                if(inputLV==INFO) fprintf(stderr,WHT);  \
                if(inputLV==WARN) fprintf(stderr,YEL);  \
                if(inputLV==ERROR) fprintf(stderr,RED); \
                if(inputLV==CRIT) fprintf(stderr,CYN);  \
                fprintf(stderr,"[%5d]%5s|%.12s:%4d %.10s()# " format RESET,getpid(),#inputLV,__FILENAME__,__LINE__,__func__,##__VA_ARGS__);                                        \
                if((inputLV)>=CRIT) { exit(__LINE__); } }               \
            } while(0)
#else
/* in production, send to syslog */
        #define open_slog(x)    openlog(x, LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1)

        #define slogf(inputLV,format,...)                       \
                do { if((inputLV)>=xxxDebugLevel) {             \
                if(inputLV==DEBUG)                              \
                        syslog(LOG_DEBUG,"%5s| %.8s:%3d %.10s()# " format,#inputLV,__FILENAME__,__LINE__,__func__,##__VA_ARGS__);                                           \
                if(inputLV==INFO)                               \
                        syslog(LOG_INFO,"%5s| %.8s:%3d %.10s()# " format,#inputLV,__FILENAME__,__LINE__,__func__,##__VA_ARGS__);                                            \
                if(inputLV==WARN)                               \
                        syslog(LOG_WARNING,"%5s| %.8s:%3d %.10s()# " format,#inputLV,__FILENAME__,__LINE__,__func__,##__VA_ARGS__);                                         \
                if(inputLV==ERROR)                              \
                        syslog(LOG_ERR,"%5s| %.8s:%3d %.10s()# " format,#inputLV,__FILENAME__,__LINE__,__func__,##__VA_ARGS__);                                     \
                if(inputLV==CRIT)                               \
                        syslog(LOG_CRIT,"%5s| %.8s:%3d %.10s()# " format,#inputLV,__FILENAME__,__LINE__,__func__,##__VA_ARGS__);                                            \
                if((inputLV)>=CRIT) { exit(__LINE__); } }               \
            } while(0)
#endif

#endif /* HEADER END */


