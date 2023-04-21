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
    char *text1 = cjson_get_prop_string_unsafe(parsed, "text1");
    char *text2 = cjson_get_prop_string_unsafe(parsed, "text2");
    char *text3 = cjson_get_prop_string_unsafe(parsed, "text3");
    char *text6 = cjson_get_prop_string_unsafe(parsed, "text6");
    char *text7 = cjson_get_prop_string_unsafe(parsed, "text7");
    char *text8 = cjson_get_prop_string_unsafe(parsed, "text8");
    printf("'%s'\n", text1);
    printf("'%s'\n", text2);
    printf("'%s'\n", text3);
    printf("'%s'\n", text6);
    printf("'%s'\n", text7);
    printf("'%s'\n", text8);

    cjson_free(parsed);
    free(string);
    return 0;
}
