#pragma once

#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

class Vector {
private:
	int size;
	float* values;

public:
	Vector(int size) {
		this->size = size;
		this->values = (float*)malloc(size * sizeof(float));
	}

	~Vector() {
		free(this->values);
	}

	void randomint() {
		for (int i = 0; i < size; i++) {
			values[i] = (float)rand() / 100;
		}
	}

	string toString();
};