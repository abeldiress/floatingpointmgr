#include "./include/FloatingPointManager.h"
#include <iostream>

using namespace std;

int main() {
  // PI test
  FloatingPointManager mgr;
  float value = 3.141592;

  uint16_t bfloat16 = mgr.FloatToBFloat16(value);
  float recovered = mgr.BFloat16ToFloat(bfloat16);

  cout << "original: " << value << endl;
  cout << "bfloat16: " << bfloat16 << endl;
  cout << "recovered: " << recovered << endl;

  return 0;
}