/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** main
*/

#include <stdio.h>
#include "cjson.h"

int main(int ac, char **av)
{
    cjson_t *parsed = NULL;

    if (ac != 2) {
        fprintf(stderr, "CJSON tester: please specify file\n");
        return 1;
    }
    parsed = cjson_parse_file(av[1]);
    cjson_free(parsed);
    (void) parsed;
    return 0;
}
