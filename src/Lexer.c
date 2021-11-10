#include "../include/Lexer.h"


void tokenize(tokenlist_t* tokenlist, lexer_t* lexer) {
    for (int i = 0; i < strlen(lexer -> source); ++i) {
        switch (lexer -> source[i]) {
                case 'a':
                case 'b':
                case 'c':
                case 'd':
                case 'e':
                case 'f':
                case 'g':
                case 'h':
                case 'i':
                case 'j':
                case 'k':
                case 'l':
                case 'm':
                case 'n':
                case 'o':
                case 'p':
                case 'q':
                case 'r':
                case 's':
                case 't':
                case 'u':
                case 'v':
                case 'w':
                case 'x':
                case 'y':
                case 'z':
                case 'A':
                case 'B':
                case 'C':
                case 'D':
                case 'E':
                case 'F':
                case 'G':
                case 'H':
                case 'I':
                case 'J':
                case 'K':
                case 'L':
                case 'M':
                case 'N':
                case 'O':
                case 'P':
                case 'Q':
                case 'R':
                case 'S':
                case 'T':
                case 'U':
                case 'V':
                case 'W':
                case 'X':
                case 'Y':
                case 'Z':
                    add_token(tokenlist, create_token(T_CHAR, lexer -> source[i], lexer -> source, lexer -> lineNum)); 
                    break;
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    add_token(tokenlist, create_token(T_INTEGER, lexer -> source[i], lexer -> source, lexer -> lineNum));
                    break;
        }
    }

    if (strcmp(lexer -> source, "___EOF___;") == 0) {
        add_token(tokenlist, create_token(T_EOF, '\0', lexer -> source, lexer -> lineNum));
    }
}
