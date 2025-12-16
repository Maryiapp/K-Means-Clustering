#ifndef POINT_H
#define POINT_H

#include <vector>
using namespace std;

// One input line = one point
struct Point {
    vector<double> coords;  // coordinates
    int cluster = -1;       // cluster index
};

#endif


