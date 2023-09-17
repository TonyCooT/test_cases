
#ifndef MOVING_AVERAGE_HPP
#define MOVING_AVERAGE_HPP

#include <numeric>
#include <vector>


template <typename T>
auto simple_moving_average(const std::vector<T> & data, std::size_t window)
{
  std::vector<T> processedData;
  processedData.reserve(data.size());
  T average = static_cast<T>(0);

  for (std::size_t i = 0; i < data.size(); ++i)
  {
    if (i < window) {
      // Calculation is performed as a cumulative moving average
      average = (data[i] + i * average) / (i + 1);
    } else {
      average += (data[i] - data[i - window]) / window;
    }

    processedData.push_back(average);
  }

  return processedData;
}

#endif // !MOVING_AVERAGE_HPP
