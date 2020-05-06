#ifndef PCA_H
#define PCA_H
#include <vector>
#include <string>
#include "./Eigen/Dense"
 
using namespace Eigen;

namespace PLLKIA010
{
    class PCA
    {   
        public: 
            PCA(void);
            PCA(const std::string raw);
            void read(void);
            void compute(std::ostream& os);
        private: 
            std::string raw;
            int M;
            int N;
            MatrixXd data;
            MatrixXd cov;
    };
    std::ostream& operator<<(std::ostream& os, const PCA& p);  
}

#endif