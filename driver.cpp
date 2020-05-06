#include <iostream>
#include <string>
#include "pca.h"

using namespace std;

int main(int argc, char* argv[])
{   
    string dataset = "2018-AvgRainfall_mm_.txt";
    PLLKIA010::PCA p(dataset);
    p.read();
    return 0;
}
