#include <stdio.h>

int main() {
	int lower = 0;
	int higher = 300;
	int step = 20;

	printf(" c  |   f\n");
	printf("-----------\n");
	for (float c = higher; c >= lower; c -= step) {
		float f = ((9.0 / 5.0) * c) + 32.0;

		printf("%3.0f  %6.1f\n", c, f);
	}

	return 0;
}
