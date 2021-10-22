#include "../headers/global.h"
#include <stdlib.h>


void open_file(char* file_name){
    file_ptr = fopen(file_name, "r");

    if(file_ptr == NULL) {
        perror("Opening file ");
        exit(errno);
    }
}

void close_file(){
    fclose(file_ptr);
}

void next_char(){
    current_char = fgetc(file_ptr);
}

char* char_to_string(char c){
    char* str = malloc(2);
    str[0] = c;
    str[1] = '\0';
    return str;
}

void cursor_back(){
    fseek(file_ptr, -1, SEEK_CUR);
}