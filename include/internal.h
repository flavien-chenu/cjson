/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** internal
*/

#ifndef CJSON_INTERNAL_H_
    #define CJSON_INTERNAL_H_
    #include <stddef.h>
    #include <sys/types.h>
    #include <stdio.h>
    #include "types.h"

    #define CJSON_INTERNAL_BLANKS " \t\r\n"
    #define CJSON_INTERNAL_EOFIELD(c) ( c == ',' || c == '\t' || \
c == ' ' || c == '\r' || c == '\n' )
    #define CJSON_INTERNAL_EONUM(c) ( c == '}' || c == ']' || \
CJSON_INTERNAL_EOFIELD(c) )

    #define CJSON_INTERNAL_ISNUM(c) (c >= '0' && c <= '9')
    #define CJSON_INTERNAL_NUM(c) (c - '0')
    #define CJSON_INTERNAL_NUM_0 (  (internal_cjson_number_t)\
                                    { false, false, 0, 0, 1 }   )

//==================================================
// STRING
//==================================================

/**
 * @brief Calculate the length of a string
 * @param s String of which get length
 * @return Number of bytes in the string pointed to by s
 */
size_t internal_cjson_strlen(const char *s);

/**
 * @brief Duplicate given string
 * @param s String to duplicate
 * @return Duplicated string
 */
char *internal_cjson_strdup(const char *s);

/**
 * @brief Duplicate given string on n chars or size of s if n too large
 * @param s String to duplicate
 * @param n Number of bytes to duplicate
 * @return Duplicated string
 */
char *internal_cjson_strndup(const char *s, unsigned int n);

/**
 * @brief Check if given char is in given char collection
 * @param c Char to find
 * @param chars Char collection in which search
 * @return Status of searching
 */
bool internal_cjson_char_in_str(char c, char *chars);

/**
 * @brief Copy src in dest on n bytes
 * @param dest Destination
 * @param src Source
 * @param n Number of bytes to copy
 */
void internal_cjson_strncpy(char *dest, char const *src, int n);

/**
 * @brief Compare s1 to s2
 * @param s1 String 1
 * @param s2 String 2
 * @return Difference between s1 and s2
 */
int internal_cjson_strcmp(char const *s1, char const *s2);

/**
 * @brief Compare s1 to s2 on n bytes
 * @param s1 String 1
 * @param s2 String 2
 * @param n Number of bytes to compare
 * @return Difference between s1 and s2
 */
int internal_cjson_strncmp(char const *s1, char const *s2, unsigned int n);

//==================================================
// SETTER
//==================================================

/**
 * @brief Set value of given cjson
 * @param c CJSON object
 * @param v Value to set
 * @param t Type of value
 */
void internal_cjson_set_value(cjson_t *c, cjson_value_t v, cjson_type_t t);

/**
 * @brief Set key of given csjon
 * @param c CJSON object
 * @param key Key to set
 */
void internal_cjson_set_key(cjson_t *c, char *key);

//==================================================
// ERROR
//==================================================

/**
 * @brief Display error on stderr
 * @param message Message to display
 * @param error Error status
 */
void internal_cjson_error(const char *message, bool *error);


//==================================================
// FILE
//==================================================

/**
 * @brief Get size of file if exists
 * @param filepath File of which get size
 * @return Size of file
 */
off_t internal_cjson_file_get_size(char *filepath);

//==================================================
// PARSING
//==================================================

/**
 * @brief Skip blank spaces
 * @param json JSON content
 * @param i Index of current position
 */
void internal_cjson_skip_blank(char *json, int *i);

//==================================================
// KEY
//==================================================

/**
 * @brief Get key in JSON object
 * @param json JSON string
 * @param i Current index
 * @param error Error status
 * @return Parsed key
 */
char *internal_cjson_parse_key(char *json, int *i, bool *error);

//==================================================
// VALUES
//==================================================

/**
 * @brief Parse json object
 * @param json JSON string
 * @param i Current index
 * @param error Error status
 * @return Parsed object
 */
cjson_value_t internal_cjson_parse_object(char *json, int *i, bool *error);

/**
 * @brief Parse json array
 * @param json JSON string
 * @param i Current index
 * @param error Error status
 * @return Parsed array
 */
cjson_value_t internal_cjson_parse_array(char *json, int *i, bool *error);

/**
 * @brief Parse json string
 * @param json JSON string
 * @param i Current index
 * @param error Error status
 * @return Parsed string
 */
cjson_value_t internal_cjson_parse_string(char *json, int *i, bool *error);

/**
 * @brief Parse json number
 * @param json JSON string
 * @param i Current index
 * @param error Error status
 * @return Parsed number
 */
cjson_value_t internal_cjson_parse_number(char *json, int *i, bool *error);

/**
 * @brief Parse json boolean
 * @param json JSON string
 * @param i Current index
 * @param error Error status
 * @return Parsed boolean
 */
cjson_value_t internal_cjson_parse_bool(char *json, int *i, bool *error);

/**
 * @brief Parse json null
 * @param json JSON string
 * @param i Current index
 * @param error Error status
 * @return Parsed null
 */
cjson_value_t internal_cjson_parse_null(char *json, int *i, bool *error);

/**
 * @brief Get value of next item and set it in CJSON element
 * @param cjson CJSON element in which set value
 * @param json JSON string
 * @param i Current index
 * @param error Error status
 */
void internal_cjson_get_value(cjson_t *cjson, char *json,
int *i, bool *error);

//==================================================
// SEPARATOR
//==================================================

/**
 * @brief Parse json object
 * @param json JSON string
 * @param i Current index
 * @param error Error status
 * @return Parsed object
 */
void internal_cjson_check_separator(char *json, int *i, bool *error);

//==================================================
// TO STRING SIZE
//==================================================

/**
 * @brief Get rendering size of given array
 * @param cjson Array CJSON element to stringify
 * @param size Size of rendered string
 * @param depth Depth of object
 * @param error Error status
 */
void internal_cjson_string_size_array(cjson_t *cjson, size_t *size,
int depth, bool *error);

/**
 * @brief Get rendering size of given number
 * @param cjson Number CJSON element to stringify
 * @param size Size of rendered string
 * @param depth Depth of object
 * @param error Error status
 */
void internal_cjson_string_size_number(cjson_t *cjson, size_t *size);

/**
 * @brief Get rendering size of given null
 * @param size Size of rendered string
 */
void internal_cjson_string_size_null(size_t *size);

/**
 * @brief Get rendering size of given boolean
 * @param cjson Boolean CJSON element to stringify
 * @param size Size of rendered string
 */
void internal_cjson_string_size_bool(cjson_t *cjson, size_t *size);

/**
 * @brief Get rendering size of given string
 * @param cjson String CJSON element to stringify
 * @param size Size of rendered string
 */
void internal_cjson_string_size_string(cjson_t *cjson, size_t *size);

/**
 * @brief Get rendering size of given CJSON object
 * @param cjson CJSON object to stringify
 * @param size Size of rendered string
 * @param depth Depth of object
 * @param error Error status
 */
void internal_cjson_string_size_object(cjson_t *cjson, size_t *size,
int depth, bool *error);

/**
 * @brief Get rendering size of given CJSON element
 * @param cjson CJSON element to stringify
 * @param size Size of rendered string
 * @param depth Depth of object
 * @param error Error status
 */
void internal_cjson_string_size(cjson_t *cjson, size_t *size,
int depth, bool *error);

/**
 * @brief Add tabs in total size
 * @param depth Depth of object
 * @param size Size of rendered string
 */
void internal_cjson_string_size_add_tabs(int depth, size_t *size);

//==================================================
// STRINGIFY
//==================================================

/**
 * @brief Stringify given CJSON element
 * @param cjson CJSON element to stringify
 * @param json JSON rendering string
 * @param depth Depth of rendering
 * @param error Error status
 */
void internal_cjson_stringify(cjson_t *cjson, internal_cjson_string_t *json,
int depth, bool *error);

/**
 * @brief Add tabs depending on depth
 * @param json JSON rendering string
 * @param depth Depth of rendering
 */
void internal_cjson_stringify_add_tabs(internal_cjson_string_t *json,
int depth);

/**
 * @brief Stringify given CJSON boolean value
 * @param cjson CJSON boolean element
 * @param json JSON rendering string
 */
void internal_cjson_stringify_bool(cjson_t *cjson,
internal_cjson_string_t *json);

/**
 * @brief Stringify given CJSON null value
 * @param json JSON rendering string
 */
void internal_cjson_stringify_null(internal_cjson_string_t *json);

/**
 * @brief Stringify given CJSON object
 * @param cjson CJSON element to stringify
 * @param json JSON rendering string
 * @param depth Depth of rendering
 * @param error Error status
 */
void internal_cjson_stringify_object(cjson_t *cjson,
internal_cjson_string_t *json, int depth, bool *error);

/**
 * @brief Stringify given CJSON array
 * @param cjson CJSON array to stringify
 * @param json JSON rendering string
 * @param depth Depth of rendering
 * @param error Error status
 */
void internal_cjson_stringify_array(cjson_t *cjson,
internal_cjson_string_t *json, int depth, bool *error);

/**
 * @brief Stringify given CJSON string
 * @param cjson CJSON string to stringify
 * @param json JSON rendering string
 */
void internal_cjson_stringify_string(cjson_t *cjson,
internal_cjson_string_t *json);

/**
 * @brief Stringify given CJSON string
 * @param cjson CJSON string to stringify
 * @param json JSON rendering string
 */
void internal_cjson_stringify_number(cjson_t *cjson,
internal_cjson_string_t *json);

#endif /* !CJSON_INTERNAL_H_ */