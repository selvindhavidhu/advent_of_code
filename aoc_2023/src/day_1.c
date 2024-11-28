#include "day_1.h"

#define MAX_LINE_SIZE 512

int solve_day_1(const char *input_file_path) {
    FILE *fp = fopen(input_file_path, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file: %s for reading.\n", input_file_path);
        exit(EXIT_FAILURE);
    }

    int sum = 0;
    char line[MAX_LINE_SIZE + 1];
    int num[2];
    size_t char_read = 0;
    size_t forward_index, reverse_index;
    bool stop_forward = false;
    bool stop_reverse = false;

    int ch;
    memset(line, 0, MAX_LINE_SIZE + 1);
    while (fgets(line, MAX_LINE_SIZE, fp) != NULL) {
        char_read = strlen(line);
        forward_index = 0;
        reverse_index = char_read - 1;
        num[0] = num[1] = 0;
        stop_forward = false;
        stop_reverse = false;
        printf("%s, char read: %zd, fid: %zd, rid: %zd\n", line, char_read, forward_index, reverse_index);

        while ((forward_index < char_read) && (reverse_index >= 0)) {

            ch = line[forward_index];
            if (!stop_forward && isdigit(ch)) {
                num[0] = ch - '0';
                stop_forward = true;
            }

            ch = line[reverse_index];
            if (!stop_reverse && isdigit(ch)) {
                num[1] = ch - '0';
                stop_reverse = true;
            }

            ++forward_index;
            --reverse_index;
        }

        printf("first digit: %d, second digit: %d\n", num[0], num[1]);
        sum += (num[0] * 10) + num[1];
        memset(line, 0, MAX_LINE_SIZE + 1);
    }

    fclose(fp);

    return sum;
}