/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** parse
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "types.h"
#include "internal.h"
#include "cjson.h"

static bool prevent_bad_syntax(char *json, int *i)
{
    internal_cjson_skip_blank(json, i);
    if (json[*i] != '{') {
        internal_cjson_error("unable to find first '{' of JSON object", NULL);
        return true;
    }
    return false;
}

cjson_t *cjson_parse(char *json)
{
    int i = 0;
    cjson_t *cjson = NULL;
    bool error = false;

    if (prevent_bad_syntax(json, &i))
        return NULL;
    cjson = cjson_new(CJSON_ROOT);
    if (!cjson) {
        internal_cjson_error("an error occured during object alloc", NULL);
        return NULL;
    }
    internal_cjson_get_value(cjson, json, &i, &error);
    if (error) {
        cjson_free(cjson);
        return NULL;
    }
    return cjson;
}
