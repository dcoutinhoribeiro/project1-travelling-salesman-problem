#ifndef BRUTE_FORCE_H
#define BRUTE_FORCE_H
    #include <stdbool.h>
    #include "../distance_list/distance_list.h"
    #include "../../path/path.h"

    PATH *brute_force(DISTANCE_LIST *distance_list, int size, int start);
#endif
