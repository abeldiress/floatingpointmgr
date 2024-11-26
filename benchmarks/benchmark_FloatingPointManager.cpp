#include "../include/FloatingPointManager.h"
#include <benchmark/benchmark.h>

static void BM_BFloat16Conversion(benchmark::State &state) {
  FloatingPointManager mgr;
  float value = 1.23456;

  for (auto _ : state) {
    uint16_t bfloat16 = mgr.FloatToBFloat16(value);
    benchmark::DoNotOptimize(mgr.BFloat16ToFloat(bfloat16));
  }
}

static void BM_FloatToFixedPoint(benchmark::State &state) {
  FloatingPointManager mgr;
  float value = 1.2346;
  int fractional = 4;

  for (auto _ : state) {
    int32_t fixed_point = mgr.FloatToFixedPoint(value, fractional);
    benchmark::DoNotOptimize(mgr.FixedPointToFloat(fixed_point, fractional));
  }
}

BENCHMARK(BM_BFloat16Conversion);
BENCHMARK(BM_FloatToFixedPoint);
BENCHMARK_MAIN();
