/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** get
*/

#include "cjson.h"
#include "internal.h"

cjson_t *cjson_array_get(cjson_array_t *array, int index)
{
    int i = 0;
    cjson_t *cjson = array ? array->first : NULL;

    while (cjson && i < index) {
        cjson = cjson->next;
    }
    if (i == index)
        return cjson;
    else
        return NULL;
}
