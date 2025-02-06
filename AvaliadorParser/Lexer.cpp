#include "Lexer.h"
#include <cctype>
#include <stdexcept>

Lexer::Lexer(const std::string& input) : input(input), position(0) {}           // construtor 

char Lexer::currentChar() const {                               // eetorna o caractere atual
    return position < input.size() ? input[position] : '\0';
}

void Lexer::advance() {                 // avanca para o proximo caractere
    if (position < input.size()) {
        ++position;
    }
}

void Lexer::skipWhitespace() {              // ignora espaços em branco
    while (std::isspace(currentChar())) {
        advance();
    }
}

Token Lexer::parseNumberOrBoolean() {           // parseia numeros ou booleanos
    size_t start = position;
    while (std::isalnum(currentChar())) {       // enquanto for alfanumerico
        advance();
    }
    std::string value = input.substr(start, position - start);
    if (value == "true" || value == "false") {
        return Token(TokenType::BOOLEAN, value);
    }
    return Token(TokenType::INTEGER, value);
}

Token Lexer::parseOperatorOrParenthesis() {             // parseia operadores ou parenteses
    char ch = currentChar();
    advance();

    
    if ((ch == '<' || ch == '>' || ch == '=' || ch == '!') && currentChar() == '=') {       // se for um dos operadores de comparaçao
        std::string op(1, ch);
        op += currentChar();
        advance();
        return Token(TokenType::OPERATOR, op);
    }

    
    if ((ch == '&' || ch == '|') && currentChar() == ch) {          // se for um dos operadores logicos
        std::string op(1, ch);
        op += currentChar();
        advance();
        return Token(TokenType::OPERATOR, op);
    }

    
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '<' || ch == '>') {       // se for um dos operadores aritmeticos
        return Token(TokenType::OPERATOR, std::string(1, ch));
    }

    
    if (ch == '(' || ch == ')') {
        return Token(TokenType::PARENTHESIS, std::string(1, ch));           // se for um dos parenteses
    }

    throw std::runtime_error("error");
}

std::vector<Token> Lexer::tokenize() {              // tokenizacao
    std::vector<Token> tokens;
    while (currentChar() != '\0') {
        skipWhitespace();
        if (std::isdigit(currentChar()) || std::isalpha(currentChar())) {       // se for um nemero ou booleano
            tokens.push_back(parseNumberOrBoolean());
        } else if (std::ispunct(currentChar())) {
            tokens.push_back(parseOperatorOrParenthesis());
        } else {
            throw std::runtime_error("error");
        }
    }
    tokens.push_back(Token(TokenType::END, "")); 
    return tokens;
}
