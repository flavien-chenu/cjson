# 🔡 C JSON
Epitech C JSON tool

# Usage

## Prerequisties
In order to use CJSON functions you have to include `cjson.h` header file.

```c
#include "cjson.h"

int main(void)
{
    return 1;
}
```

## Load JSON file to CJSON type
```c
cjson_t *cjson = cjson_parse_file(filename); // Parse given file
```

## Get property of object
To get a property there are severals methods to do it.

Follwing fake file will be used in next examples :
```json
{
    "id": 3,
    "price": 1.90,
    "name": "John",
    "enabled": true,
    "notes": [2, 4.5, 78, 12]
}
```

### Get property value directly to type expected
You need to know the type that you want to get.


*This method is not recommanded because if an error occured you'll not be able to know it*

```c
//Example in order to get int property 'id'

int integer = cjson_get_prop_int_unsafe(cjson, "id");
//integer = 3

float price = cjson_get_prop_float_unsafe(cjson, "price");
//price = "1.90"

char *str = cjson_get_prop_string_unsafe(cjson, "name");
//str = "John"

bool enabled = cjson_get_prop_bool_unsafe(cjson, "enabled");
//enabled = true

cjson_array_t *notes = cjson_get_prop_array_unsafe(cjson, "notes");
//notes = [2, 4.5, 78, 12] (linked list system)

```

### Get property value with error handling
You need to know the type that you want to get.

*This method is recommanded because if an error occured you will able to know it*

```c
//Example in order to get int property 'id'

int integer = 0;
if (!cjson_get_prop_int(cjson, "id", &integer))
    printf("An error occured on integer\n");
//integer = 3

float price = 0;
if (!cjson_get_prop_float(cjson, "price", &price))
    printf("An error occured on float\n");
//price = "1.90"

char *str = NULL;
if (!cjson_get_prop_string(cjson, "name", &str))
    printf("An error occured on string\n");
//str = "John"

bool enabled = false;
if (!cjson_get_prop_string(cjson, "enabled", &enabled))
    printf("An error occured on boolean\n");
//bool = true

cjson_array_t *notes = NULL;
if (!cjson_get_prop_array(cjson, "notes", &notes))
    printf("An error occured on array\n");
//notes = [2, 4.5, 78, 12] (linked list system)
```

### Get property CJSON element
This method get CJSON element that is directly editable, with this maneer you'll be able to:
- Edit its key
- Edit its value
- Display it
- Export it

```c
// Get a CJSON element representing a float -> "price" : 1.90
cjson_t *price = cjson_get_prop(cjson, "price");

//To edit key you can do as follwing
cjson_set_prop_key(price, "MyNewPriceKey"); //Now price is : "MyNewPriceKey" : 1.90

//To edit value you can do as follwing
cjson_set_prop_value(price, CJSON(34.7)); //Now price is : "MyNewPriceKey" : 34.7

//Or you can do as follwing
cjson_set_prop_value(price, CJSON(false), CJSON_BOOL_T); //Now price is : "MyNewPriceKey" : false
```

## Get array of items in primitive C types
CJSON lib offer you possibility to convert directly in expected primitive C type.

### Convert to int array
```c
cjson_array_t *notes = NULL;
if (!cjson_get_prop_array(cjson, "notes", &notes)) {
    printf("An error occured on array\n");
    exit(1);
}

size_t len = 0;
int *converted = cjson_array_to_int_array(notes, &len);

if (!converted) {
    printf("An error occured on array conversion\n");
    exit(1);
}
for (size_t i = 0; i < len; i++) {
    printf("notes[%zu] = %d\n", i, converted[i]);
}
//len = 4
//converted = [2, 4, 78, 12]

//Display:
//notes[0] = 2
//notes[1] = 4
//notes[2] = 78
//notes[3] = 12
```

Made by [Flavien Chenu](https://github.com/flavien-chenu)
