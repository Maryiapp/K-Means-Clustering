#ifndef POINT_H
#define POINT_H

#include <vector>

struct Point {
    std::vector<double> coords; // coordinates
    int cluster = -1;           // cluster
};

#endif
