#include "kmeans.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

KMeans::KMeans(int k) : k(k) {}

/*
    loads points from a text file
    skips empty lines and reads all numbers from each line
*/
void KMeans::loadData(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Can't open input file: " << filename << "\n";
        exit(1);
    }

    string line;
    while (getline(file, line)) {

        
        if (line.find_first_not_of(" \t") == string::npos) // skip empty or space-only lines
            continue;

        stringstream ss(line);
        double number;
        Point p;

        
        while (ss >> number) {     // read numbers from this line
            p.coords.push_back(number);
        }

        if (!p.coords.empty()) {
            points.push_back(p);
        }
    }

    cout << "Loaded " << points.size() << " points.\n";
}

void KMeans::run() {
    // later
}

void KMeans::saveResults(const string& filename) {
    // later
}

  // printed when no arguments are given
void printManual() {
    cout << "Simple K-Means Program\n\n";
    cout << "Usage:\n";
    cout << "  program.exe -i <input_file> -o <output_file> -k <clusters>\n\n";
    cout << "Example:\n";
    cout << "  program.exe -i data.txt -o out.txt -k 3\n\n";
    cout << "Make sure your input file is in the same folder as the .exe.\n";
}
