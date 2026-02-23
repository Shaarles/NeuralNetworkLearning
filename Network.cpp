#include "Vector.cpp"


class Network{
private:
	int size;
	int* dimensions;
	Vector* weights;
	Vector* biases;

public:

	Network(int size, int* dimensions) {
		this->size = size;
		this->dimensions = dimensions;
		this->weights = (Vector*)malloc(size*sizeof(Vector));
		this->biases = (Vector*)malloc(size * sizeof(Vector));
	}

	~Network() {
		free(this->weights);
		free(this->biases);
	}

};