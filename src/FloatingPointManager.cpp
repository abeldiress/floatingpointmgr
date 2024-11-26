#include "FloatingPointManager.h"
#include <cmath>
#include <limits>
#include <stdexcept>

FloatingPointManager::FloatingPointManager() {}

uint16_t FloatingPointManager::FloatToBFloat16(float value) {
  uint32_t floatBits = *reinterpret_cast<uint32_t*>(&value);
  return static_cast<uint16_t>(floatBits >> 16);
}

float FloatingPointManager::BFloat16ToFloat(uint16_t value) {
  uint32_t floatBits = static_cast<uint32_t>(value) << 16;
  return *reinterpret_cast<float*>(&floatBits);
}

int32_t FloatingPointManager::FloatToFixedPoint(float value, int fractionalBits) {
  return static_cast<int32_t>(std::round(value * (1 << fractionalBits)));
}

float FloatingPointManager::FixedPointToFloat(int32_t value, int fractionalBits) {
  return static_cast<float>(value) / (1 << fractionalBits);
}

float FloatingPointManager::Add(float a, float b, Format format) {
  if (format == Format::BFLOAT16) {
    return BFloat16ToFloat(FloatToBFloat16(a) + FloatToBFloat16(b));
  }

  return a + b;
}

float FloatingPointManager::Multiply(float a, float b, Format format) {
  if (format == Format::BFLOAT16) {
    return BFloat16ToFloat(FloatToBFloat16(a) * FloatToBFloat16(b));
  }
  
  return a * b;
}

float FloatingPointManager::ComputeError(float exact, float approximate) {
  return std::abs(exact - approximate) / std::abs(exact);
}

std::vector<float> FloatingPointManager::SimulatePrecisionLoss(const std::vector<float>& data, Format format) {
  std::vector<float> result;
  for (float value : data) {
    if (format == Format::BFLOAT16) {
      result.push_back(BFloat16ToFloat(FloatToBFloat16(value)));
    }
  }
  return result;
}

uint32_t FloatingPointManager::RoundToNearest(uint32_t value, int bitPrecision) {
  uint32_t mask = (1 << (32 - bitPrecision)) - 1;
  return (value + (mask >> 1)) & ~mask;
}
