#ifndef UTILS_H
#define	UTILS_H

#include <fstream>
#include <string>
#include <iostream>
#include <unistd.h>

#define MEMORY_MEGABYTE 1048576.0

typedef double Memory;

class Utils {
public:

    Utils();
    static Memory current_mem_usage();

};

#endif	/* UTILS_H */
