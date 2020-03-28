#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include <vector>
#include <map>

#include "VectorFactory.h"
#include "UnitTests.h"

using namespace std;

using CRat = VECTOR_HORI_VERT::Vector<Rational>;
using Factory = VECTOR_HORI_VERT::Factory<Rational>;
using HoriFactory = VECTOR_HORI_VERT::HoriFactory<Rational>;
using VertFactory = VECTOR_HORI_VERT::VertFactory<Rational>;

int main() {
    // Unit-tests
    TestAll();
    
    // OpenMP test
    CompareSpeed();

    try {
        // Task
        string filename = "test.txt";
        /* cout << "Enter filename ... ";
        cin >> filename; */


        ifstream inputFile(filename);
        if (!inputFile) {
            cerr << "\nError: file not found!" << endl;
            return -1;
        }

        vector<shared_ptr<CRat>> vectors_;
        vector<string> filenames_;

        // factories
        map<string, shared_ptr<Factory>> factories_ = {
                {"Hori", make_shared<HoriFactory>()},
                {"Vert", make_shared<VertFactory>()}
        };

        string inputString;
        while (getline(inputFile, inputString)) {
            stringstream temp(inputString);
            string type, outputFilename;

            temp >> type >> outputFilename;

            if (factories_.count(type) != 1) {
                cerr << "Error: invalid Vector type!" << endl;
                return -1;
            }

            auto resFactory = factories_[type];
            auto newVector = resFactory->Create(0u);

            Rational tmpRational;
            while (temp >> tmpRational) {
                newVector->PushBack(tmpRational);
            }

            vectors_.push_back(newVector);
            filenames_.push_back(outputFilename);
        }

        inputFile.close();

        auto vectorIt = vectors_.begin();
        auto fileIt = filenames_.begin();

        while (vectorIt != vectors_.end() && fileIt != filenames_.end()) {
            ofstream outputFile(*fileIt);
            if (!outputFile) {
                cerr << "Error: can not open file " << (*fileIt) << endl;
                return -1;
            }

            (*vectorIt)->Print(outputFile);

            ++vectorIt;
            ++fileIt;

            outputFile.close();
        }
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
        return -1;
    }

    return 0;
}
