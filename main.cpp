#include "main.h"

int main() {
	int size = 3;
	int dimensions[] = { 2, 3, 1 };
	Network network(size, dimensions);//no delete and stuff needed; stack object
	return 0;
}