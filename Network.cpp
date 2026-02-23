#include "Vecteur.cpp"
#include "Network.h"

#define main Network

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
int main() {
	return 0;
}