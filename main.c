#include "network.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  srand(42); // Seed random number generator

  int layer_sizes[] = {2, 3, 1};
  network_t net;
  if (build_network(&net, layer_sizes, 3) != 0) {
    return 1;
  }

  float inputs[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

  float targets[4] = {0, 1, 1, 0};

  train(&net, &inputs, &targets, 4, 10, 1);

  free_network(&net);
  return 0;
}