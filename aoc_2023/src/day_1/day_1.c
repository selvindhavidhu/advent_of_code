#include "day_1.h"

#define MAX_LINE_SIZE 512
#define WORDS_ARRAY_SIZE 9

static int find_first_digit(const char *line);
static int find_second_digit(const char *line);

static const char WORDS[WORDS_ARRAY_SIZE][6] = { "one",	  "two",   "three",
						 "four",  "five",  "six",
						 "seven", "eight", "nine" };
static const size_t WORDS_LENGTH[WORDS_ARRAY_SIZE] = {
	3, 3, 5, 4, 4, 3, 5, 5, 4
};

int solve_day_1(const char *input_file_path)
{
	FILE *fp = fopen(input_file_path, "r");
	if (fp == NULL) {
		fprintf(stderr, "Failed to open file: %s for reading.\n",
			input_file_path);
		exit(ENOENT);
	}

	int sum = 0;
	char line[MAX_LINE_SIZE + 1] = { 0 };
	int num[2] = { 0, 0 };

	while (fgets(line, MAX_LINE_SIZE, fp) != NULL) {
		int line_length = (int)strlen(line);

		/* Find the first digit. */
		for (int i = 0; i < line_length; ++i) {
			int ch = line[i];
			if (isdigit(ch)) {
				num[0] = ch - '0';
				break;
			}
		}

		/* Find the second digit. */
		for (int j = line_length - 1; j >= 0; --j) {
			int ch = line[j];
			if (isdigit(ch)) {
				num[1] = ch - '0';
				break;
			}
		}

		sum += (num[0] * 10) + num[1];
		memset(line, 0, MAX_LINE_SIZE + 1);
	}

	fclose(fp);

	return sum;
}

int solve_day_1_part_2(const char *input_file_path)
{
	FILE *fp = fopen(input_file_path, "r");
	if (fp == NULL) {
		fprintf(stderr, "Failed to open file: %s for reading.\n",
			input_file_path);
		exit(ENOENT);
	}

	int sum = 0;
	char line[MAX_LINE_SIZE + 1] = { 0 };
	while (fgets(line, MAX_LINE_SIZE, fp) != NULL) {
		int n1 = find_first_digit(line);
		int n2 = find_second_digit(line);
		sum += (n1 * 10) + n2;

		memset(line, 0, MAX_LINE_SIZE + 1);
	}

	fclose(fp);
	return sum;
}

static int find_first_digit(const char *line)
{
	int line_length = (int)strlen(line);

	for (int i = 0; i < line_length; ++i) {
		int ch = line[i];
		if (isdigit(ch)) {
			return (ch - '0');
		} else {
			size_t len = strlen(line + i);
			for (size_t k = 0; k < WORDS_ARRAY_SIZE; ++k) {
				if (len >= WORDS_LENGTH[k] &&
				    (strncmp(line + i, WORDS[k],
					     WORDS_LENGTH[k]) == 0)) {
					return (k + 1);
				}
			}
		}
	}
	return 0;
}

static int find_second_digit(const char *line)
{
	int line_length = (int)strlen(line);

	for (int i = line_length - 1; i >= 0; --i) {
		int ch = line[i];
		if (isdigit(ch)) {
			return (ch - '0');
		} else {
			size_t len = strlen(line + i);
			for (size_t k = 0; k < WORDS_ARRAY_SIZE; ++k) {
				if (len >= WORDS_LENGTH[k] &&
				    (strncmp(line + i, WORDS[k],
					     WORDS_LENGTH[k]) == 0)) {
					return (k + 1);
				}
			}
		}
	}
	return 0;
}