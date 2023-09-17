
#include <iostream>
#include <typeinfo>

#include "moving_average.hpp"


void test_validity();

int main()
{
  test_validity();

  std::vector<float> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  simple_moving_average(data, 4);

  return 0;
}

void test_validity()
{
  std::cout << "[INFO] Validity test run\n";

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

  std::cout << "[INFO] Type error: "
            << typeError << '\n'
            << "[INFO] Data error: "
            << dataError << '\n'
            << "[INFO] Validity test completed" << '\n';
}
