#include "util.h"

void app_log(const char* str, FILE* stream) {
    fprintf(stream, "%s\n", str);
}

