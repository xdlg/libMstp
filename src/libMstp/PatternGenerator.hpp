#pragma once

#include "Scale.hpp"

#include <cstdlib>
#include <vector>

namespace libMstp
{

class PatternGenerator
{
public:
  /// Scales used to generate the pattern
  std::vector<Scale> _scales;

  /// @param width Image width
  /// @param height Image height
  PatternGenerator(std::size_t width, std::size_t height);

  /// Image data of size width*height with values in [0;1]
  const std::vector<double>& pattern() const;

  /// Generate next pattern step
  void generate();

private:
  const std::size_t _width;
  const std::size_t _height;
  const std::size_t _size;
  std::vector<double> _pattern;

  /// Randomize image data
  void randomize();

  /// Normalize image data on the interval [0;1]
  void normalize();

  /// Box blur
  /// @param radius Blur radius
  /// @param source Data to blur
  /// @param destination Blurred data
  void blur(
    std::size_t radius, const std::vector<double>& source, std::vector<double>& destination) const;

  /// Box blur, horizontal pass
  /// @param radius Blur radius
  /// @param source Data to blur
  /// @param destination Blurred data
  void blurHorizontal(
    std::size_t radius, const std::vector<double>& source, std::vector<double>& destination) const;

  /// Box blur, vertical pass
  /// @param radius Blur radius
  /// @param source Data to blur
  /// @param destination Blurred data
  void blurVertical(
    std::size_t radius, const std::vector<double>& source, std::vector<double>& destination) const;
};

} // namespace libMstp
