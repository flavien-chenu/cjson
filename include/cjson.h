/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** cjson
*/

#ifndef CJSON_H_
    #define CJSON_H_
    #define CJSON_ARRAY_KEY "__cjson_array_element__"
    #define CJSON_ROOT "__cjson_root__"
    #define CJSON(v) ((cjson_value_t) v)

    #include "types.h"

//==================================================
// TYPE
//==================================================

/**
 * @brief Create a new CJSON object
 * @param key Object key
 * @return Created object
 */
cjson_t *cjson_new(char *key);

/**
 * @brief Free given CJSON object
 * @param cjson CJSON object to free
 */
void cjson_free(cjson_t *cjson);

//==================================================
// ARRAY
//==================================================

/**
 * @brief Create a new CJSON array
 * @return Created array or NULL if failed
 */
cjson_array_t *cjson_array_new(void);

/**
 * @brief Free given CJSON array
 * @param array Array to free
 */
void cjson_array_free(cjson_array_t *array);

/**
 * @brief Append given value in given array
 * @param array Array in which append value
 * @param element Element to append in given array
 */
void cjson_array_append(cjson_array_t *array, cjson_t *element);

/**
 * @brief Remove given element from given array
 * @param array Array in which remove element
 * @param element Element to remove in given array
 */
void cjson_array_remove(cjson_array_t *array, cjson_t *element);

/**
 * @brief Remove given element from given array and free it
 * @param array Array in which remove element
 * @param element Element to remove in given array
 * @warning This function destroy given element by freeing it.
 * Don't use this function if you want to keep accessible the element.
 * In this case use 'cjson_array_remove' instead.
 */
void cjson_array_delete(cjson_array_t *array, cjson_t *element);

//==================================================
// PROPERTIES
//==================================================

/**
 * @brief Get property in given object
 * @param object Object in which get value
 * @param key Key of property
 * @return Property if found, NULL if not found
 */
cjson_t *cjson_get_prop(cjson_t *object, char *key);

//==================================================
// PARSER
//==================================================

/**
 * @brief Parse given JSON content
 * @param json JSON content to parse
 * @return Parsed JSON object or NULL if failed
 */
cjson_t *cjson_parse(char *json);

/**
 * @brief Parse given JSON file
 * @param filepath Path of file to parse
 * @return Parsed JSON object or NULL if failed
 */
cjson_t *cjson_parse_file(char *filepath);

#endif /* !CJSON_H_ */
