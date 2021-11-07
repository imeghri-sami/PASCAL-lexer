#ifndef PASCAL_LEXER_TOKENS_H
#define PASCAL_LEXER_TOKENS_H

typedef enum {
    PROGRAM_TOKEN,
    CONST_TOKEN,
    VAR_TOKEN,
    BEGIN_TOKEN,
    END_TOKEN,
    IF_TOKEN,
    THEN_TOKEN,
    WHILE_TOKEN,
    DO_TOKEN,
    READ_TOKEN,
    WRITE_TOKEN,
    ID_TOKEN,
    NUM_TOKEN,
    SC_TOKEN,
    PT_TOKEN,
    PLUS_TOKEN,
    MINUS_TOKEN,
    MULTI_TOKEN,
    DIV_TOKEN,
    COM_TOKEN,
    ASSIGN_TOKEN,
    LOWER_TOKEN,
    LOWER_OR_EQUAL_TOKEN,
    GREATER_TOKEN,
    GREATER_OR_EQUAL_TOKEN,
    EQUAL_TOKEN,
    NOT_EQUAL_TOKEN,
    OP_TOKEN,
    CP_TOKEN,
    EOF_TOKEN,
    ERROR_TOKEN
}token_enum;

char *tokens[] = {
        "PROGRAM_TOKEN",
        "CONST_TOKEN",
        "VAR_TOKEN",
        "BEGIN_TOKEN",
        "END_TOKEN",
        "IF_TOKEN",
        "THEN_TOKEN",
        "WHILE_TOKEN",
        "DO_TOKEN",
        "READ_TOKEN",
        "WRITE_TOKEN",
        "ID_TOKEN",
        "NUM_TOKEN",
        "SC_TOKEN",
        "PT_TOKEN",
        "PLUS_TOKEN",
        "MINUS_TOKEN",
        "MULTI_TOKEN",
        "DIV_TOKEN",
        "COM_TOKEN",
        "ASSIGN_TOKEN",
        "LOWER_TOKEN",
        "LOWER_OR_EQUAL_TOKEN",
        "GREATER_TOKEN",
        "GREATER_OR_EQUAL_TOKEN",
        "EQUAL_TOKEN",
        "NOT_EQUAL_TOKEN",
        "OP_TOKEN",
        "CP_TOKEN",
        "EOF_TOKEN",
        "ERROR_TOKEN"
};

char* keywords[] = {
        "program",
        "const",
        "var",
        "begin",
        "end",
        "if",
        "then",
        "while",
        "do",
        "read",
        "write"
};

const int KEYWORDS_LENGTH = 11;

#endif //PASCAL_LEXER_TOKENS_H
