#ifndef FLOATINGPOINTMANAGER_H
#define FLOATINGPOINTMANAGER_H

#include <cstdint>
#include <vector>
#include <string>

class FloatingPointManager {
public:
  enum class Format { FLOAT32, BFLOAT16, FIXED_POINT };

  FloatingPointManager();

  uint16_t FloatToBFloat16(float value);
  float BFloat16ToFloat(uint16_t value);
  int32_t FloatToFixedPoint(float value, int fractionalBits);
  float FixedPointToFloat(int32_t value, int fractionalBits);

  float Add(float a, float b, Format format);
  float Multiply(float a, float b, Format format);

  float ComputeError(float exact, float approximate);

  std::vector<float> SimulatePrecisionLoss(const std::vector<float>& data, Format format);

private:
    uint32_t RoundToNearest(uint32_t value, int bitPrecision);
};

#endif // FLOATINGPOINTMANAGER_H
