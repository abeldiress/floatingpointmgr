#include "../include/FloatingPointManager.h"
#include <benchmark/benchmark.h>

static void BM_BFloat16Conversion(benchmark::State& state) {
  FloatingPointManager manager;
  float value = 1.23456;

  for (auto _ : state) {
    uint16_t bfloat16 = manager.FloatToBFloat16(value);
    benchmark::DoNotOptimize(manager.BFloat16ToFloat(bfloat16));
  }
}
BENCHMARK(BM_BFloat16Conversion);
BENCHMARK_MAIN();
