/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include "cjson.h"

int main(int ac, char **av)
{
    cjson_t *parsed = NULL;
    char *string = NULL;

    if (ac != 2) {
        fprintf(stderr, "CJSON tester: please specify file\n");
        return 1;
    }
    parsed = cjson_parse_file(av[1]);
    cjson_array_t *array = cjson_get_array_unsafe(parsed);
    cjson_t *element = cjson_array_get(array, 3);
    cjson_display(element);
    cjson_free(parsed);
    (void) parsed;
    free(string);
    return 0;
}
