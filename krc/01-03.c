#include <stdio.h>

int main() {
	int lower = 0;
	int higher = 300;
	int step = 20;

	printf(" f  |   c\n");
	printf("-----------\n");
	for (float f = lower; f <= higher; f += step) {
		float c = (5.0 / 9.0) * (f - 32.0);

		printf("%3.0f  %6.1f\n", f, c);
	}

	return 0;
}
