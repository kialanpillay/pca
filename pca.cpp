#include "pca.h"
#include <iostream>
#include <fstream>
#include <string>
#include "./Eigen/Dense"

using namespace PLLKIA010;
using namespace Eigen;

PCA::PCA(){}

PCA::PCA(const std::string & r): raw(r){}

void PCA::read(void){
    std::ifstream in(raw);
    std::string line, observations, variables, row;
    for (int i = 0; i < 4; i++){
        getline(in,line);
    };
    in >> observations >> M >> variables >> N;

    data = MatrixXd(M,N);
    for (int i = 0; i < M; i++){
        for (int i = 0; i < 2; i++){
            getline(in,line); //Discard Empty Lines
        };
        float x, y;
        in >> x >> y;
        data(i,0) = x;
        data(i,1) = y;

        for (int i = 0; i < 3; i++){
            getline(in,line); //Discard Empty Lines
        };
    };
}

void PCA::compute(std::ostream& os){
    //Subtract Mean
    VectorXd mean = data.colwise().mean();
    data.rowwise() -= mean.transpose();

    //Covariance Matrix
    cov = data.transpose() * data / (M - 1);
    //Eigenvalues and Eigenvectors
    EigenSolver<MatrixXd> es(cov);
    os << "Question 1)\nThe Eigenvalues for the principal components are: " << std::endl << es.eigenvalues().real() << std::endl << std::endl;
    os << "Question 2)\nThe Eigenvectors for the principal components are:" << std::endl << es.eigenvectors().real() << std::endl << std::endl;
    os << "Col 1 - Principal Component 1 (Eigenvalue = " << es.eigenvalues()[0].real() << "), Col 2 - Principal Component 2 (Eigenvalue = " << es.eigenvalues()[1].real() << ")" << std::endl;
    os << "Row 1 - January (X), Row 2 - July (Y)" << std::endl << std::endl;
    os << "Question 3)\nThe Covariance Matrix is: " << std::endl << cov << std::endl << std::endl;

    //Total Variance
    double totalVariance = cov.coeff(0,0) + cov.coeff(1,1);
    os << "Question 4)\nThe total variance, given by Var(X) + Var(Y), is: " << totalVariance << std::endl << std::endl;

    //Proportional PC Variance
    os << "Question 5)\nThe variance of each principal component is equal to its eigenvalue.\nThe proportion of total variance explained by each principal component is:" << std::endl << std::endl;
    os << "Principal Component 1: " << es.eigenvalues()[0].real()/totalVariance * 100 << "%" << std::endl;
    os << "Principal Component 2: " << es.eigenvalues()[1].real()/totalVariance * 100 << "%" << std::endl << std::endl;
}

std::ostream& PLLKIA010::operator<<(std::ostream& os, const PCA& pca){ 
    PCA p = pca;
    os << "ML Assignment 5: PCA" << std::endl;
    os << "====================" << std::endl;
    os << "Kialan Pillay: PLLKIA010" << std::endl;
    os << "====================" << std::endl;
    p.read();
    p.compute(os);
    return os;
}