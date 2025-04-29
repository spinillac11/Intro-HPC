#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins);

int main(int argc, char **argv) {
    const int SEED = std::atoi(argv[1]);
    const int NSAMPLES = std::atoi(argv[2]);
    const double MU = std::atof(argv[3]);
    const double SIGMA = std::atof(argv[4]);
    const double XMIN = std::atof(argv[5]);
    const double XMAX = std::atof(argv[6]);
    const int NBINS = std::atoi(argv[7]);

    compute_pdf(SEED, NSAMPLES, MU, SIGMA, XMIN, XMAX, NBINS);
}

void compute_pdf(int seed, int nsamples, double mu, double sigma,double xmin, double xmax, int nbins){

    std::mt19937 gen(seed);
    std::normal_distribution<double> dis{mu, sigma};
    std::vector<int> histogram(nbins, 0);
    double bin_width = (xmax - xmin) / nbins;

    for (int ii = 0; ii < nsamples; ++ii) {
        double n = dis(gen); 
        if (n >= xmin && n <= xmax) {
            int bin_index = (n - xmin) / bin_width; // Calcula el bin en el que cae el número aleatorio
            histogram[bin_index]++;
        }
    }

    for (int i = 0; i < nbins; ++i) {
        double bin_center = xmin + i * bin_width + bin_width / 2;
        double pdf_value = static_cast<double>(histogram[i]) / (nsamples * bin_width);
        std::cout << bin_center << "\t" << pdf_value << "\n";
    }
}