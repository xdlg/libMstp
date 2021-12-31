#include "PatternGenerator.hpp"
#include "Scale.hpp"

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>

void writeImage(std::size_t width, std::size_t height, const std::vector<double>& data);

int main(int argc, char** argv)
{
  constexpr std::size_t width = 320;
  constexpr std::size_t height = 240;

  mstpGeneratorLib::PatternGenerator generator(width, height);
  generator._scales.push_back(mstpGeneratorLib::Scale(50, 100, 0.04));
  generator._scales.push_back(mstpGeneratorLib::Scale(25, 50, 0.03));
  generator._scales.push_back(mstpGeneratorLib::Scale(12, 25, 0.02));

  for (std::size_t i = 0; i < 100; i++) {
    std::cout << "Generating pattern " << std::to_string(i) << "..." << std::endl;
    generator.generate();
  }

  writeImage(width, height, generator.pattern());

  std::cout << "Done\n";

  return 0;
}

void writeImage(std::size_t width, std::size_t height, const std::vector<double>& data)
{
  std::ofstream ofs("out.ppm", std::ios_base::out | std::ios_base::binary);
  ofs << "P5" << std::endl << width << ' ' << height << std::endl << "255" << std::endl;

  for (std::size_t i = 0; i < height * width; i++) {
    ofs << static_cast<unsigned char>(data[i] * 255);
  }

  ofs.close();
}
