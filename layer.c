#include "layer.h"
#include <math.h>
#include <stdlib.h>

static float get_random_weight(float a) {
  float r = (float)rand() / RAND_MAX; // Scales random number to between 0 and 1
  return -1 * a + (2 * a) * r;        // Puts number in range [-a, a]
}

static void randomize_weights(layer_t *layer) {
  int n_in = layer->n_in;
  int n_out = layer->n_out;
  float a = sqrtf(6.0f / (n_in + n_out)); // Range of random weights
  for (int i = 0; i < (n_in * n_out); i++) {
    layer->W[i] = get_random_weight(a);
  }
}

int build_layer(layer_t *layer, int n_in, int n_out) {
  layer->n_in = n_in;
  layer->n_out = n_out;

  layer->W = malloc(
      n_in * n_out *
      sizeof(float)); // Creates array to store all weights for this layer

  if (layer->W == NULL) {
    return 1;
  }
  randomize_weights(layer);

  // Default these all to 0
  layer->b = calloc(n_out, sizeof(float));
  layer->z = calloc(n_out, sizeof(float));
  layer->a = calloc(n_out, sizeof(float));

  return 0;
}