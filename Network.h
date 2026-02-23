#pragma once
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <cstdio>
#include <cstdlib>
#include "Network.h"
using namespace std;

class Network {
private:
	int size;
	int* dimensions;
	Vector* weights;
	Vector* biases;

	Vector* dev_weights;
	Vector* dev_biases;

public:

	Network(int size, int* dimensions) {
		this->size = size;
		this->dimensions = dimensions;

		//allocating host memory for weights and biases
		cudaMallocHost(&weights, size * sizeof(Vector));
		cudaMallocHost(&biases, size * sizeof(Vector));

		//allocating device memory for weights and biases
		cudaMalloc(&dev_weights, size * sizeof(Vector));
		cudaMalloc(&dev_biases, size * sizeof(Vector));

		for (int i = 0; i < size; i++) {
			weights[i] = Vector(dimensions[i]); //no delete and stuff needed; stack object
			weights[i].randomint();
			biases[i] = Vector(dimensions[i]);
			biases[i].randomint();
		}
	}

	~Network() {
		cudaFree(dev_weights);
		cudaFree(dev_biases);
		cudaFreeHost(weights);
		cudaFreeHost(biases);
	}

};