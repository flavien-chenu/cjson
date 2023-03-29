/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** separator
*/

#include "internal.h"

void internal_cjson_check_separator(char *json, int *i, bool *error)
{
    if (json[*i] != ':')
        *error = true;
    *i += 1;
}
