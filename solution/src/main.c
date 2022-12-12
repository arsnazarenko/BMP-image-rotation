#include "format.h"
#include "transform.h"
#include "util.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc < 3) {
        app_log("Not enough arguments", stderr);
        app_log("Usage: ./image-transformer <source-image> <transformed-image>", stdout);
        return EXIT_FAILURE;
    }
    struct image img = {0};
    format_deserializer bmp_deserialize = formats[FORMAT_BMP].deserialize;
    bool deser = image_deserialize(argv[1], &img, bmp_deserialize);
    if (!deser) {
        image_destroy(&img);
        return EXIT_FAILURE;
    }
    struct maybe_image maybe = transformations[TR_ROTATE_LEFT](img);
    if (!maybe.valid) {
        app_log("transformation error", stderr);
        image_destroy(&img);
        return EXIT_FAILURE;
    }
    struct image new_img = maybe.img;
    format_serializer bmp_serialize = formats[FORMAT_BMP].serialize;
    bool ser = image_serialize(argv[2], &new_img, bmp_serialize);
    image_destroy(&img);
    image_destroy(&new_img);
    if (!ser) { return EXIT_FAILURE; }
    return 0;
}
