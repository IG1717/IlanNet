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

static float get_weight(const layer_t *layer, int node, int in) {
  return layer->W[node * layer->n_in + in];
}

static float sigmoid(float x) { return (1 / (1 + expf(-1 * x))); }

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
  if (layer->b == NULL) {
    return 1;
  }
  layer->z = calloc(n_out, sizeof(float));
  if (layer->z == NULL) {
    return 1;
  }
  layer->a = calloc(n_out, sizeof(float));
  if (layer->a == NULL) {
    return 1;
  }

  return 0;
}

void layer_forward(layer_t *layer, const float *input) {
  for (int i = 0; i < layer->n_out; i++) {
    layer->z[i] = layer->b[i]; // Set each node equal to its bias
    for (int j = 0; j < layer->n_in; j++) {
      layer->z[i] +=
          input[j] *
          get_weight(layer, i,
                     j); // Multiply each input by corresponding weight
    }
    layer->a[i] = sigmoid(layer->z[i]);
  }
}

void forward_pass(layer_t *layers, int n_layers, const float *input) {
  for (int i = 0; i < n_layers; i++) {
    if (i == 0) {
      layer_forward(&layers[i], input);
    } else {
      layer_forward(&layers[i], layers[i - 1].a);
    }
  }
}

void free_layer(layer_t *layer) {
  free(layer->W);
  free(layer->b);
  free(layer->z);
  free(layer->a);
}