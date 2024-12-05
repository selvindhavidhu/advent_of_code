#include "fileop.h"

size_t get_file_size(const char *file_path)
{
	FILE *fp = fopen(file_path, "rb");
	if (!fp) {
		fprintf(stderr, "Failed to open file: %s for reading.\n",
			file_path);
		exit(ENOENT);
	}

	fseek(fp, 0, SEEK_END);
	size_t size = ftell(fp);
	fclose(fp);
	return size;
}

void read_file_contents(const char *file_path, char *buffer, size_t buflen)
{
	if (!buffer || buflen < 1)
		return;

	FILE *fp = fopen(file_path, "rb");
	if (!fp) {
		fprintf(stderr, "Failed to open file: %s for reading.\n",
			file_path);
		exit(ENOENT);
	}

	fread(buffer, sizeof(char), buflen, fp);
	buffer[buflen - 1] = '\0';

	fclose(fp);
}