#include <iostream>
#include <vector>
#include <random>
#include <Eigen/Dense>

std::vector<std::vector<int>> generateSamples(double mean_A, double std_A, double mean_B, double std_B, double mean_C, double std_C, double mean_D, double std_D, double correlation_AB, double correlation_AC, double correlation_AD, double correlation_BC, double correlation_BD, double correlation_CD, int numSamples) {
    std::vector<std::vector<int>> samples;
    std::random_device rd;
    std::mt19937 generator(rd());

    // Calculate the covariance matrix
    Eigen::Matrix4d covarianceMatrix;
    covarianceMatrix << std_A * std_A, correlation_AB * std_A * std_B, correlation_AC * std_A * std_C, correlation_AD * std_A * std_D,
                        correlation_AB * std_A * std_B, std_B * std_B, correlation_BC * std_B * std_C, correlation_BD * std_B * std_D,
                        correlation_AC * std_A * std_C, correlation_BC * std_B * std_C, std_C * std_C, correlation_CD * std_C * std_D,
                        correlation_AD * std_A * std_D, correlation_BD * std_B * std_D, correlation_CD * std_C * std_D, std_D * std_D;

    // Create a multivariate normal distribution
    Eigen::LLT<Eigen::Matrix4d> llt(covarianceMatrix);
    Eigen::Matrix4d L = llt.matrixL();
    Eigen::Matrix4d A = L * L.transpose();
    Eigen::Vector4d mean(mean_A, mean_B, mean_C, mean_D);
    Eigen::MatrixXd samplesMatrix = Eigen::MatrixXd::Zero(numSamples, 4);

    std::normal_distribution<double> distribution(0.0, 1.0);

    // Generate samples
    for (int i = 0; i < numSamples; i++) {
        Eigen::Vector4d randomVec;
        randomVec << distribution(generator), distribution(generator), distribution(generator), distribution(generator);
        Eigen::Vector4d sample = mean + L * randomVec;
        samplesMatrix.row(i) = sample.transpose();
    }

    // Convert samples to vector<vector<int>>
    for (int i = 0; i < samplesMatrix.rows(); i++) {
        std::vector<int> sample = { static_cast<int>(std::round(samplesMatrix(i, 0))),
                                    static_cast<int>(std::round(samplesMatrix(i, 1))),
                                    static_cast<int>(std::round(samplesMatrix(i, 2))),
                                    static_cast<int>(std::round(samplesMatrix(i, 3))) };
        samples.push_back(sample);
    }

    return samples;
}

int main() {
    double mean_A = 34.0;
    double std_A = 6.0;
    double mean_B = 54.0;
    double std_B = 7.0;
    double mean_C = 56.0;
    double std_C = 12.0;
    double mean_D = 28.0;
    double std_D = 6.0;
    double correlation_AB = 0.984;
    double correlation_AC = 0.979;
    double correlation_AD = -0.985;
    double correlation_BC = 0.967;
    double correlation_BD = -0.977;
    double correlation_CD = -0.972;
    int numSamples = 80;

    std::vector<std::vector<int>> samples = generateSamples(mean_A, std_A, mean_B, std_B, mean_C, std_C, mean_D, std_D, correlation_AB, correlation_AC, correlation_AD, correlation_BC, correlation_BD, correlation_CD, numSamples);

    // Print the generated samples
    for (const auto& sample : samples) {
        std::cout << "A: " << sample[0] << ", B: " << sample[1] << ", C: " << sample[2] << ", D: " << sample[3] << std::endl;
    }

    return 0;
}