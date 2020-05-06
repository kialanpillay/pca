#include "pca.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace PLLKIA010;

PCA::PCA(){}

PCA::PCA(const std::string d): dataset(d){}

void PCA::read(void){
    std::ifstream in(dataset);
    std::string line, observations;
    int M;
    for (int i = 0; i < 4; i++){
        getline(in,line);
    };
    in >> observations >> M;
}