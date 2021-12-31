#pragma once

#include "Scale.hpp"

#include <cstdlib>
#include <vector>

namespace mstpGeneratorLib
{

class PatternGenerator
{
public:
  std::vector<Scale> _scales;

  PatternGenerator(std::size_t width, std::size_t height);

  const std::vector<double>& pattern() const;
  void generate();

private:
  const std::size_t _width;
  const std::size_t _height;
  const std::size_t _size;
  std::vector<double> _pattern;

  void randomize();
  void normalize();
  void blur(
    std::size_t radius, const std::vector<double>& source, std::vector<double>& destination) const;
  void blurHorizontal(
    std::size_t radius, const std::vector<double>& source, std::vector<double>& destination) const;
  void blurVertical(
    std::size_t radius, const std::vector<double>& source, std::vector<double>& destination) const;
};

} // namespace mstpGeneratorLib
