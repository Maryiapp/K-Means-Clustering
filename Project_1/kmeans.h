#ifndef KMEANS_H
#define KMEANS_H
#include <string>
#include <vector>
#include "point.h"

using namespace std;

struct Centroid {
    vector<double> coords;
};

class KMeans {
public:
    KMeans(int k);
    void loadData(const string& filename);
    void run();
    void saveResults(const string& filename);

private:
    int k;
    int dimensions = 0;

    vector<Point> points;
    vector<Centroid> centroids;

    void initCentroids();
    void assignClusters();
    double distance(const Point& p, const Centroid& c);
};

void printManual();

#endif




