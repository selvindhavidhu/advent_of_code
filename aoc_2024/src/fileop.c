#include "fileop.h"

size_t get_file_size(const char *file_path)
{
    FILE *fp = fopen(file_path, "rb");
    if (!fp)
    {
        fprintf(stderr, "Failed to open file: '%s' for reading.\n", file_path);
	    return 0;
    }

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    fclose(fp);
    return size;
}

size_t read_file_contents(const char *file_path, char *buffer, size_t buflen)
{
    if (!buffer || buflen < 1)
        return 0;

    FILE *fp = fopen(file_path, "rb");
    if (!fp)
    {
        fprintf(stderr, "Failed to open file: %s for reading.\n", file_path);
        return 0;
    }

    size_t nbytes = fread(buffer, sizeof(char), buflen, fp);
    fclose(fp);
    buffer[buflen - 1] = '\0';
    
    return nbytes;
}