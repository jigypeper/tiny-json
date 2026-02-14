#ifndef TINY_JSON_H
#define TINY_JSON_H

#include <stddef.h>
#include <stdbool.h>

typedef enum {
  JSON_NULL,
  JSON_BOOL,
  JSON_NUMBER,
  JSON_STRING,
  JSON_ARRAY,
  JSON_OBJECT

} json_type_t;

typedef struct json_array json_array_t;
typedef struct json_object json_object_t;

typedef struct json_value {
  json_type_t type;
  union {
    bool boolean;
    double number;
    char *string;
    json_array_t *array;
    json_object_t *object;
  } as;
} json_value_t;


// Array structure
struct json_array {
    json_value_t **items;
    size_t count;
    size_t capacity;
};

// Object structure (key-value pairs)
typedef struct {
    char *key;
    json_value_t *value;
} json_pair_t;

struct json_object {
    json_pair_t *pairs;
    size_t count;
    size_t capacity;
};

// Core API
json_value_t *json_parse(const char *input, char **error);
void json_free(json_value_t *value);

// Accessors
json_value_t *json_object_get(json_object_t *obj, const char *key);
json_value_t *json_array_get(json_array_t *arr, size_t index);

#endif
