
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <typeinfo>
#include <vector>

#include "moving_average.hpp"


void test_validity();
void test_performance();

int main()
{
  test_validity();
  test_performance();

  std::vector<float> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  simple_moving_average(data, 4);

  return 0;
}

void test_validity()
{
  std::cout << "[INFO] Validity test run" << '\n';

  bool typeError = false;
  bool dataError = false;

  // Case #1
  std::vector<float> dataFloat = {1, 0, 3, 0, 5, 0, 7, 0, 9, 0};
  std::vector<float> resultFloatRight = {1, 0.5, (4 / 3), 1, 2, 2, 3, 3, 4, 4};
  auto resultFloat = simple_moving_average(dataFloat, 4);

  typeError = (typeid(resultFloat) != typeid(resultFloatRight));
  dataError = (resultFloat != resultFloatRight);

  // Case #2
  std::vector<double> dataDouble = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<double> resultDoubleRight = {1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5.5, 6.5};
  auto resultDouble = simple_moving_average(dataDouble, 8);

  typeError = (typeid(resultDouble) != typeid(resultDoubleRight));
  dataError = (resultDouble != resultDoubleRight);

  std::cout << "[INFO] Data type error: "
            << typeError << '\n'
            << "[INFO] Calculation error: "
            << dataError << '\n'
            << "[INFO] Validity test completed" << '\n';
}

void test_performance()
{
  std::cout << "[INFO] Performance test run\n";

  // Tools for generating random numbers
  std::mt19937 gen(std::random_device{}());
  std::uniform_real_distribution<> dist(0.0, 100.0);

  // Creating an synthetic dataset that includes 1'000'000 random values
  // You can choose float or double data types
  std::vector<float> data(1'000'000);
  std::generate_n(data.begin(), data.size(), [&gen, &dist] { return dist(gen); });

  // Processing of a dataset by a simple moving average algorithm
  // You can choose the window size from the range 4, 8, 16, 32, 64, 128
  std::size_t window = 4;

  auto start = std::chrono::high_resolution_clock::now();
  simple_moving_average(data, window);
  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> time = end - start;

  // Calculation of performance metric in counts/seconds
  std::cout << "[INFO] Data type: "
            << typeid(data[0]).name() << '\n'
            << "[INFO] Dataset size: "
            << data.size() << '\n'
            << "[INFO] Window size: "
            << window << '\n'
            << "[INFO] Performance metric in counts/second: "
            << (data.size() / time.count()) << '\n'
            << "[INFO] Performance test completed" << '\n';
}
