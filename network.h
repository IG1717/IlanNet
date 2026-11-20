#include "layer.h"

typedef struct {
  int n_layers;
  layer_t *layers;
} network_t;

/**
 * Function to build a network from an array of layer sizes
 *
 * \param net - pointer to the network to build
 * \param sizes - array of sizes of each layer ex. (2,3)
 * \param n_sizes - length of sizes array
 *
 * \return 0 on success
 */
int build_network(network_t *net, const int *sizes, int n_sizes);

/**
 * Function to free the memory allocated to all layers in a network
 *
 * \param layer - pointer to network with memory to be freed
 */
void free_network(network_t *network);

// void forward_pass(network_t *net, float *input);

/**
 * Function to train a network
 *
 * \param net - pointer to the network to be trained
 * \param input - inputs to be trained on
 * \param targets - target for each input
 * \param n_examples - number of examples given to the network during training
 * \param epochs - number of epochs to run during training
 * \param learning_rate - learning rate of the networks
 */
void train(network_t *net, float *inputs, float *targets, int n_examples, int epochs, float learning_rate);