#include "Vector.h"

string Vector::toString() {
	string result = "[";
	for (int i = 0; i < size; i++) {
		result += to_string(values[i]);
		if (i != size - 1) {
			result += ", ";
		}
	}
	result += "]";
	return result;
}

