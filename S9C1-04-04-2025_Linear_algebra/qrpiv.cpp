#include <iostream>
#include <eigen3/Eigen/Dense>
#include <string>

int main(int argc, char **argv)
{
    const int N = std::stoi(argv[1]);
    const int SEED = std::stoi(argv[2]);
    srand(SEED);

    Eigen::MatrixXd A = Eigen::MatrixXd::Random(N,N);
    Eigen::VectorXd b = Eigen::VectorXd::Random(N);
    Eigen::VectorXd x = A.colPivHouseholderQr().solve(b);
    //std::cout << "The solution is:\n" << x << std::endl;
    std::cout << "Verification:\n" << (A*x - b).norm() << std::endl;

    return 0;
}