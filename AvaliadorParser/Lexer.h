#ifndef LEXER_H
#define LEXER_H

#include "Token.h"
#include <vector>
#include <string>


class Lexer {
private:
    std::string input;
    size_t position;

    char currentChar() const;       // retorna o caractere atual
    void advance();                 // mavança para o próximo caractere
    void skipWhitespace();             // ignora espaços em branco
    Token parseNumberOrBoolean();       // parseia números ou booleanos
    Token parseOperatorOrParenthesis();     // parseia operadores ou parênteses

public:
    explicit Lexer(const std::string& input);     
    std::vector<Token> tokenize();
};

#endif 