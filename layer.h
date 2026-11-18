typedef struct layer {
  int n_in;  // Number of input nodes to this layer
  int n_out; // Number of nodes in this layer
  float *W;  // Weights inside the layer
  float *b;  // Offsets of each node
  float *z;  // rawsum of each node
  float *a;  // sum of each node after activation function applied
} layer_t;

/**
 * Function to create a layer
 *
 * \param n_in - number of input nodes to the layer
 * \param n_out - number of nodes inside the layer
 *
 * \return 0 on success, 1 on failure
 */
int build_layer(layer_t *layer, int n_in, int n_out);

/**
 * Function to free the memory allocated to a layer
 *
 * \param layer - pointer to layer with memory to be freed
 */
void free_layer(layer_t *layer);