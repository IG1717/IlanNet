#include "layer.h"
#include <stdlib.h>

int main(void) {
  srand(42); // Seed random number generator

  layer_t hidden;
  if (build_layer(&hidden, 2, 3) != 0) {
    return 1;
  }

  layer_t output;
  if (build_layer(&output, 3, 1) != 0) {
    return 1;
  }

  return 0;
}