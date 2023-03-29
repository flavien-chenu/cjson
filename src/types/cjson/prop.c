/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** append
*/

#include "internal.h"

cjson_t *cjson_get_prop(cjson_t *object, char *key)
{
    cjson_t *prop = NULL;
    cjson_t *read = object->value.v_object;

    if (!read)
        return NULL;
    while (read && !prop) {
        if (!read->key) {
            read = read->next;
            continue;
        }
        if (internal_cjson_strcmp(read->key, key) == 0)
            prop = read;
        read = read->next;
    }
    return prop;
}
