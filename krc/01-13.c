#include <stdio.h>
#include <assert.h>

#define IN 0
#define OUT 1
#define BUCKET_SIZE 5
#define BUCKET_QUANTITY 5

int main() {
	int c;
	int count[BUCKET_QUANTITY];
	int state = OUT;
	int current_word_len = 0;

	for(int i = 0; i < BUCKET_QUANTITY; i++)
		count[i] = 0;

	while((c = getchar()) != EOF) {
		if(state == IN && (c == ' ' || c == '\n' || c == '\t')) {
			state = OUT;

			int bucket = current_word_len / BUCKET_SIZE;
			if (bucket >= BUCKET_QUANTITY)
				bucket = BUCKET_QUANTITY - 1;

			count[bucket]++;
			current_word_len = 0;
		} else {
			state = IN;
			current_word_len++;
		}
	}

	for(int i = 0; i < BUCKET_QUANTITY; i++) {
		int min = i * BUCKET_SIZE;
		if (i == BUCKET_QUANTITY - 1) {
			printf("%d or more: %d\n", min, count[i]);
		} else {
			int max = ((i + 1) * BUCKET_SIZE) - 1;
			printf("%d to %d: %d\n", min, max, count[i]);
		}
	}

	return 0;
}
