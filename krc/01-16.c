#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline) {
	int len = 0;

	while (len < (maxline - 1)) {
		int c = getchar();

		if (c == EOF)
			break;

		line[len] = c;
		len++;

		// Newlines should be included in the line, but
		// EOF should not. For that reason we check
		// for newlines after adding the char to the
		// string, but the EOF check is done before.
		if (c == '\n')
			break;
	}
	line[len] = '\0';

	return len;
}

void copy(char to[], char from[]) {
	int i = 0;

	while ((to[i] = from[i]) != '\0')
		i++;
}

int main() {
	char last_line[MAXLINE];
	int last_line_len;
	char longest_line[MAXLINE];
	int longest_line_len = 0;

	while ((last_line_len = get_line(last_line, MAXLINE)) > 0) {
		if (last_line_len > longest_line_len) {
			longest_line_len = last_line_len;
			copy(longest_line, last_line);
		}
	}

	if (longest_line_len > 0)
		printf("%s", longest_line);

	return 0;
}
