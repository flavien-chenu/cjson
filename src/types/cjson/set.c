/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** set
*/

#include <stdlib.h>
#include "types.h"
#include "internal.h"

void cjson_set_value(cjson_t *c, cjson_value_t v, cjson_type_t t)
{
    c->value = v;
    c->type = t;
}

void cjson_set_key(cjson_t *c, char *key)
{
    if (c->key)
        free(c->key);
    c->key = internal_cjson_strdup(key);
}
