#include "day_1.h"

#define MAX_LINE_SIZE 512

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

	const char words[][6] = { "one", "two",   "three", "four", "five",
				   "six", "seven", "eight", "nine" };

	const int words_length[] = { 3, 3, 5, 4, 4, 3, 5, 5, 4 };
	int sum = 0;
	char line[MAX_LINE_SIZE + 1] = { 0 };
	int num[2] = { 0, 0 };
	int a = 1;

	while (fgets(line, MAX_LINE_SIZE, fp) != NULL) {
		printf("line: %d\t", a++);
		num[0] = num[1] = 0;
		int line_length = (int)strlen(line);

		/* Find the first digit. */
		for (int i = 0; i < line_length; ++i) {
			int ch = line[i];
			if (isdigit(ch)) {
				num[0] = ch - '0';
				goto search_second_digit;
			} else {
				int len = (int) strlen(line + i);
				for (int k = 0; k < 9; ++k) {
					if (len >= words_length[k]) {
						char const* pos = strstr(line + i, words[k]);
						if (pos) {
							num[0] = k + 1;
							goto search_second_digit;
						}
					}
				}
			}
		}

		search_second_digit:

		/* Find the second digit. */
		for (int j = line_length - 1; j >= 0; --j) {
			int ch = line[j];
			if (isdigit(ch)) {
				num[1] = ch - '0';
				goto end_of_search;
			} else {
				int len = (int) strlen(line + j);
				for (int k = 0; k < 9; ++k) {
					if (len >= words_length[k]) {
						char const* pos = strstr(line + j, words[k]);
						if (pos) {
							num[1] = k + 1;
							goto end_of_search;
						}
					}
				}
			}
		}

		end_of_search:
		printf("num[0] = %d\t num[1] = %d\n", num[0], num[1]);

		sum += (num[0] * 10) + num[1];
		memset(line, 0, MAX_LINE_SIZE + 1);
	}

	fclose(fp);
	return sum;
}