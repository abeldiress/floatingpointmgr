#include "../include/FloatingPointManager.h"
#include <gtest/gtest.h>

TEST(FloatingPointManager, BFloat16Conversion) {
  FloatingPointManager manager;
  float value = 1.23456;
  uint16_t bfloat16 = manager.FloatToBFloat16(value);
  float recovered = manager.BFloat16ToFloat(bfloat16);

  EXPECT_NEAR(value, recovered, 0.01);
}

TEST(FloatingPointManager, FixedPointConversion) {
  FloatingPointManager manager;
  float value = 2.75;
  int32_t fixed = manager.FloatToFixedPoint(value, 8);
  float recovered = manager.FixedPointToFloat(fixed, 8);

  EXPECT_NEAR(value, recovered, 0.01);
}
