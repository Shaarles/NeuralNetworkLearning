#include "Network.h"

void Network::toString() {
	for (int i = 0; i < size; i++) {
		printf("Layer %d:\n", i);
		printf("Weights: %s\n", weights[i].toString().c_str());
		printf("Biases: %s\n", biases[i].toString().c_str());//.c_str() needed to convert string to const char* for printf
	}
}