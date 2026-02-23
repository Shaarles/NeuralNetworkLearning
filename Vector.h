#pragma once
#include <iostream>
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
		values = (float*)malloc(size * sizeof(float));
	}

	~Vector() {
		free(values);
	}

	void randomint() {
		for (int i = 0; i < size; i++) {
			
			values[i] = rand() / 100.0f;
		}
	}

	string toString();
};