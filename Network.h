#pragma once
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <cstdio>
#include <cstdlib>
#include "Vector.cpp"
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
		cudaMallocHost(&weights, size * sizeof(new Vector(size)));
		cudaMallocHost(&biases, size * sizeof(new Vector(size)));

		//allocating device memory for weights and biases
		cudaMalloc(&dev_weights, size * sizeof(new Vector(size)));
		cudaMalloc(&dev_biases, size * sizeof(new Vector(size)));

		//copying data from host to device

		cudaMemcpy(dev_weights, weights, size * sizeof(new Vector(size)), cudaMemcpyHostToDevice);
		cudaMemcpy(dev_biases, biases, size * sizeof(new Vector(size)), cudaMemcpyHostToDevice);



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

	void toString();

};