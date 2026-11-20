#include "network.h"
#include <stdlib.h>

int build_network(network_t *net, const int *sizes, int n_sizes) {
  int n_layers = n_sizes - 1;
  net->layers = malloc(sizeof(layer_t) * n_layers);
  if (net->layers == NULL) {
    return 1;
  }
  net->n_layers = n_layers;
  for (int i = 0; i < n_layers; i++) {
    if (build_layer(&net->layers[i], sizes[i], sizes[i + 1]) != 0) { // Passes in the layer to be built
      return 1;
    }
  }
  return 0;
}

void free_network(network_t *net) {
  for (int i = 0; i < net->n_layers; i++) {
    free_layer(&net->layers[i]);
  }
  free(net->layers);
  net->layers = NULL;
  net->n_layers = 0;
}

void forward_pass(network_t *net, float *input) {
  for (int i = 0; i < net->n_layers; i++) {
    if (i == 0) {
      layer_forward(&net->layers[i], input);
    } else {
      layer_forward(&net->layers[i], net->layers[i - 1].a);
    }
  }
}

void backward_pass(network_t *net, float *input, float *target) {
  for (int i = net->n_layers; i > 0; i--) { // Loop backward from the last layer
    continue;
  }
}

void train(network_t *net, float *inputs, float *targets, int n_examples, int epochs, float learning_rate) {
  int n_in = net->layers[0].n_in;                   // Number of inputs to the network
  int n_out = net->layers[net->n_layers - 1].n_out; // Number of outputs of the network

  for (int i = 0; i < epochs; i++) {
    for (int j = 0; j < n_examples; j++) {
      forward_pass(net, &inputs[j * n_in]);
      backward_pass(net, &inputs[j * n_in], &targets[j * n_out]);
    }
  }
}