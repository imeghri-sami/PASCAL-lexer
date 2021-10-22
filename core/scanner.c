#include "../headers/includes.h"

token_type* current_token = NULL;

void update_current_token(char* value, int code){
    current_token->value = value;
    current_token->code = code;
}

char* read_next_word(){
    int i = 0;
    char* word = malloc(2);
    word[i++] = current_char;
    next_char();

    while(isalnum(current_char)) {
        word = realloc(word, strlen(word) + 1);
        word[i++] = current_char;
        next_char();
    }

    word[i] = '\0';
    return word;
}

char* read_next_digits(){
    int i = 0;
    char* number = malloc(2);
    number[i++] = current_char;
    next_char();

    while(isdigit(current_char)) {
        number = realloc(number, strlen(number) + 1);
        number[i++] = current_char;
        next_char();
    }


    number[i] = '\0';
    return number;
}

int iskeyword(char* word){
    for(int i = 0; i < KEYWORDS_LENGTH; i++){
        if( !strcmp(word, keywords[i]) ) return i;
    }

    return -1;
}



void get_token(){

    if(isalpha(current_char)){
        char* word = read_next_word();
        int index = iskeyword(word);

        if (index > -1) update_current_token(word, index);
        else update_current_token(word, ID_TOKEN);

    }else if (isdigit(current_char)){
        char* number = read_next_digits();
        update_current_token(number, NUM_TOKEN);
    }else{
        switch (current_char) {
            case ';': update_current_token(";", SC_TOKEN); break;
            case '.': update_current_token(".", PT_TOKEN); break;
            case '+': update_current_token("+", PLUS_TOKEN); break;
            case '-': update_current_token("-", MINUS_TOKEN); break;
            case '*': update_current_token("*", MULTI_TOKEN); break;
            case '/': update_current_token("/", DIV_TOKEN); break;
            case ',': update_current_token(",", COM_TOKEN); break;
            case ':': {
                next_char();
                if (current_char != '=')
                    goto ERROR;
                else {
                    update_current_token(":=", ASSIGN_TOKEN);
                    cursor_back();
                }
                break;
            }
            case '<': {
                next_char();
                if (current_char == '=')
                    update_current_token("<=", LESS_OR_EQUAL_TOKEN);
                else if (current_char == '>')
                    update_current_token("<>", NOT_EQUAL_TOKEN);
                else {
                    update_current_token("<", LESS_TOKEN);
                    cursor_back();
                }
                break;
            }
            case '>': {
                next_char();
                if (current_char == '=')
                    update_current_token(char_to_string(current_char), GREATER_OR_EQUAL_TOKEN);
                else {
                    update_current_token("<", GREATER_TOKEN);
                    cursor_back();
                }
                break;
            }
            case '(': update_current_token("(", OP_TOKEN); break;
            case ')': update_current_token(")", CP_TOKEN); break;
            ERROR : default:
                update_current_token(char_to_string(current_char), ERROR_TOKEN);
        }
        next_char();
    }

}

void escape_whitespaces(){
    while(isspace(current_char)){
        next_char();
    }
}

void start_lexer(){

    FILE* output = fopen("output", "w");

    current_token = malloc(sizeof(token_type));

    next_char();
    while(!feof(file_ptr)){
        escape_whitespaces();
        get_token();
        fprintf(output, "%s\n", tokens[current_token->code]);
        printf("%s -- %s\n", current_token->value, tokens[current_token->code]);
    }

    close_file();
}
