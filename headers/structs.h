#ifndef PASCAL_LEXER_STRUCTS_H
#define PASCAL_LEXER_STRUCTS_H
#include "tokens.h"

typedef struct {
    token_enum code;
    char* value;
}token_type;

#endif //PASCAL_LEXER_STRUCTS_H
