#ifndef TOKEN_H
#define TOKEN_H

#include <string>


enum class TokenType {                                          // define os tipos possiveis
    INTEGER, BOOLEAN, OPERATOR, PARENTHESIS, END
};


class Token {                                           // armazena o tipo e o valor de um token.
public:                         
    TokenType type;
    std::string value;

    Token(TokenType type, const std::string& value) : type(type), value(value) {}
};

#endif 