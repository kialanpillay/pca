#ifndef PCA_H
#define PCA_H
#include <vector>
#include <string>

namespace PLLKIA010
{
    class PCA
    {   
        public: 
            PCA(void);
            PCA(const std::string dataset);
            void read(void);
            void calculateEigenvalues(void);
            void calculateEigenvectors(void);
            void calculateCovarianceMatrix(void);
            void calculateTotalVariance(void);
            void calculatePCVariance(void);
        private: 
            std::string dataset;
            std::vector<std::vector<float>> data;
            std::vector<std::vector<float>> eigenvectors;
            std::vector<std::vector<float>> covariance;
            std::vector<float> eigenvalues;
            float variance;
            
    };
}

#endif