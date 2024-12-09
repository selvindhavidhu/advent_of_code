#ifndef SELVIN_AOC_FILEOP_H_
#define SELVIN_AOC_FILEOP_H_

#include "stdheaders.h"

size_t get_file_size(const char *file_path);
size_t read_file_contents(const char *file_path, char *buffer, size_t buflen);

#endif