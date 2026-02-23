#include "Vecteur.h"


class Vector {
	private:
		int size;
		float* values;

	public:
		Vector(int size) {
			this->size = size;
			this->values = (float*)malloc(size*sizeof(float));
		}

		~Vector() {
			free(this->values);
		}
};

int main() {
	return 0;
}