#ifndef KMEANS_H
#define KMEANS_H
#include <string>
#include <vector>
#include "point.h"

using namespace std;

class KMeans {
public:
    KMeans(int k);
    void loadData(const string& filename); // load points from file

    void run(); // algorithm placeholder

    void saveResults(const string& filename); // output placeholder
     
private:
    int k;
    vector<Point> points;
};

void printManual(); // prints a basic help message

#endif



