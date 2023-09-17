
#include "moving_average.hpp"


int main()
{
  std::vector<float> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  simple_moving_average(data, 4);

  return 0;
}
