#include <gtest/gtest.h>

#include "PatternGenerator.hpp"
#include <algorithm>
#include <cstdlib>
#include <vector>

namespace
{

constexpr std::size_t width = 320;
constexpr std::size_t height = 240;

bool areValuesInRange(const std::vector<double>& data, double lowerBound, double upperBound)
{
  double min = *std::min_element(data.begin(), data.end());
  double max = *std::max_element(data.begin(), data.end());
  return (min >= lowerBound) && (max <= upperBound);
}

} // namespace

TEST(PatternGeneratorTest, PatternSize)
{
  libMstp::PatternGenerator generator(width, height);
  EXPECT_EQ(generator.pattern().size(), width * height);
}

TEST(PatternGeneratorTest, InitialPattern)
{
  libMstp::PatternGenerator generator(width, height);
  EXPECT_TRUE(areValuesInRange(generator.pattern(), 0.0, 1.0));
}

TEST(PatternGeneratorTest, Generate)
{
  libMstp::PatternGenerator generator(width, height);
  generator._scales.push_back(libMstp::Scale(50, 100, 0.04));
  generator._scales.push_back(libMstp::Scale(25, 50, 0.03));
  generator._scales.push_back(libMstp::Scale(12, 25, 0.02));

  constexpr std::size_t steps = 100;
  for (size_t i = 0; i < steps; i++) {
    generator.generate();
    EXPECT_TRUE(areValuesInRange(generator.pattern(), 0.0, 1.0));
  }
}
