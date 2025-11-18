#include <iostream>
#include <string>
#include "kmeans.h"

using namespace std;


    // reads arguments and loads the data
int main(int argc, char* argv[]) {

    if (argc == 1) {
        printManual();
        return 0;
    }

    string inputFile, outputFile;
    int k = 0;

    // simple argument parsing
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];

        if (arg == "-i" && i + 1 < argc) {
            inputFile = argv[++i];
        }
        else if (arg == "-o" && i + 1 < argc) {
            outputFile = argv[++i];
        }
        else if (arg == "-k" && i + 1 < argc) {
            k = stoi(argv[++i]);
        }
        else {
            cout << "Unknown argument: " << arg << "\n";
            printManual();
            return 1;
        }
    }

    if (inputFile.empty() || outputFile.empty() || k <= 0) {
        printManual();
        return 1;
    }

    // create KMeans object
    KMeans model(k);

    // load data
    model.loadData(inputFile);

    // later
    model.run();
    model.saveResults(outputFile);

    return 0;
}

