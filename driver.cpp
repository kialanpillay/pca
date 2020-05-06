#include <iostream>
#include <fstream>
#include "pca.h"

using namespace std;

int main(int argc, char *argv[])
{
    ofstream out("output.txt");
    PLLKIA010::PCA module("2018-AvgRainfall_mm_.txt");
    out << module;
    return 0;
}
