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

  for (int k = 0; k < 4; k++) {
    forward_pass(&net, inputs[k]);
    printf("%.0f %.0f -> %f\n", inputs[k][0], inputs[k][1], net.layers[1].a[0]);
  }

  free_network(&net);
  return 0;
}