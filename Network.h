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
	int total_dimensions;
	Vector* weights;
	Vector* biases;

	float* dev_weights;
	float* dev_biases;

public:

	Network(int size, int* dimensions) {
		this->size = size;
		this->dimensions = dimensions;

		for(int i = 0; i < size; i++) {
			total_dimensions += dimensions[i];
			}

		//allocating host memory for weights and biases
		cudaMallocHost(&weights, size * sizeof(Vector));
		cudaMallocHost(&biases, size * sizeof(Vector));

		//allocating device memory for weights and biases
		cudaMalloc(&dev_weights, total_dimensions *sizeof(float));
		cudaMalloc(&dev_biases, total_dimensions * sizeof(float));




		for (int i = 0; i < size; i++) {

			srand(time({}));
			weights[i] = Vector(dimensions[i]);
			weights[i].randomint();
			biases[i] = Vector(dimensions[i]);
			biases[i].randomint();
		}

		//copying data from host to device

	}

	~Network() {
		cudaFree(dev_weights);
		cudaFree(dev_biases);
		cudaFreeHost(weights);
		cudaFreeHost(biases);
	}
	void toString();

	__global__ void forward(Vector* dev_weights, Vector* dev_biases);


};