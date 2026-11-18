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

void forward_pass(network_t *net, float *input);