#include "json.h"

typedef struct {
    const char *input;
    size_t pos;
    size_t len;
    char error[256];
} parser_t;

// Core parsing functions
static void skip_whitespace(parser_t *p);
static json_value_t *parse_value(parser_t *p);
static json_value_t *parse_object(parser_t *p);
static json_value_t *parse_array(parser_t *p);
static json_value_t *parse_string(parser_t *p);
static json_value_t *parse_number(parser_t *p);
static json_value_t *parse_literal(parser_t *p, const char *literal, json_type_t type);

// Memory management
static json_value_t *alloc_value(json_type_t type);
static void set_error(parser_t *p, const char *msg);
