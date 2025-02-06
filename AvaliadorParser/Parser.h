#ifndef PARSER_H
#define PARSER_H

#include "Lexer.h"
#include "Expression.h"
#include <memory>
#include <vector>

class Parser {
private:
    std::vector<Token> tokens;          // tokens do lexer
    size_t current;                     // indice do token atual

    const Token& peek() const;          // retorna o token atual
    
    const Token& advance();             // avança para o proximo token
    
    bool match(TokenType type) const;       // verifica se o token atual eh do tipo especificado

    std::unique_ptr<Expression> parseExpression();
                 
    
    std::unique_ptr<Expression> parseOrExpression();        // parseia expressoes lógicas OR    
    std::unique_ptr<Expression> parseAndExpression();       // parseia expressoes lógicas AND
    std::unique_ptr<Expression> parseEqualityExpression();      // parseia expressoes de igualdade
    std::unique_ptr<Expression> parseRelationalExpression();        // parseia expressoes relacionais
    std::unique_ptr<Expression> parseAdditiveExpression();          // parseia expressoes aditivas
    std::unique_ptr<Expression> parseMultiplicativeExpression();        // parseia expressoes multiplicativas
    std::unique_ptr<Expression> parseUnaryExpression();             // parseia expressoes unarias
    std::unique_ptr<Expression> parsePrimaryExpression();           // parseia expressoes primarias

public:
    explicit Parser(){

        this-> current = 0;
    }               
    
    std::unique_ptr<Expression> parse(const std::string& input);    
};

#endif 