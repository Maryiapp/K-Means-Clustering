#include "kmeans.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

KMeans::KMeans(int k) : k(k) {}

void KMeans::loadData(const string& filename) {

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Cannot open input file: " << filename << "\n";
        exit(1);
    }

    string line;
    while (getline(file, line)) {

        if (line.find_first_not_of(" \t") == string::npos)
            continue;

        stringstream ss(line);
        double value;
        Point p;

        while (ss >> value) {
            p.coords.push_back(value);
        }

        if (!p.coords.empty()) {
            if (points.empty()) {
                dimensions = p.coords.size();
                points.push_back(p);
            }
            else if (p.coords.size() == dimensions) {
                points.push_back(p);
            }
            else {
                cout << "Skipping point with different dimension: ";
                for (double v : p.coords)
                    cout << v << " ";
                cout << "\n";
            }
        }

    }

    file.close();

    cout << "Loaded points: " << points.size() << "\n";

    if (!points.empty()) {
        cout << "Detected dimensions: " << dimensions << "\n";
    }
    initCentroids();
}




void KMeans::initCentroids() {

    if (points.size() < k) {
        cout << "Error: k > number of points\n";
        exit(1);
    }
    centroids.resize(k);
    for (int i = 0; i < k; i++) {
        int index = rand() % points.size();
        centroids[i].coords = points[index].coords;
    }

    cout << "Initialized " << k << " centroids\n";
}



double KMeans::distance(const Point& p, const Centroid& c) {

    double sum = 0.0;
    for (size_t i = 0; i < p.coords.size(); i++) {
        double diff = p.coords[i] - c.coords[i];
        sum += diff * diff;
    }
    return sum;
}


void KMeans::assignClusters() {

    for (auto& p : points) {

        double bestDist = distance(p, centroids[0]);
        int bestCluster = 0;

        for (int i = 1; i < k; i++) {
            double d = distance(p, centroids[i]);
            if (d < bestDist) {
                bestDist = d;
                bestCluster = i;
            }
        }

        p.cluster = bestCluster;
    }
}

void KMeans::run() {
    assignClusters();   // visualization
}


void KMeans::saveResults(const string& filename) {

    ofstream out(filename);
    if (!out.is_open()) {
        cout << "Cannot open output file: " << filename << "\n";
        return;
    }

    out << "K-Means Clustering\n";

    out << "Centroids:\n";
    for (int i = 0; i < k; i++) {
        out << "Centroid " << i << ": ";
        for (double v : centroids[i].coords)
            out << v << " ";
        out << "\n";
    }

    out << "\nPoints and clusters:\n";

    for (size_t i = 0; i < points.size(); i++) {
        out << "Point " << i << ": (";
        for (size_t j = 0; j < points[i].coords.size(); j++) {
            out << points[i].coords[j];
            if (j + 1 < points[i].coords.size())
                out << ", ";
        }
        out << ") -> cluster " << points[i].cluster << "\n";
    }
    out.close();
}


void printManual() {
    cout << "Simple K-Means Program\n\n";
    cout << "Usage:\n";
    cout << "  program.exe -i data.txt -o out.txt -k 2\n\n";
}



