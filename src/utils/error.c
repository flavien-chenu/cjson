/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** error
*/

#include <unistd.h>
#include "internal.h"

void internal_cjson_error(const char *message, bool *error)
{
    write(2, "CJSON: ", 8);
    write(2, message, internal_cjson_strlen(message));
    write(2, "\n", 1);
    if (error)
        *error = true;
}
