#include "Parser.h"
#include <stdexcept>

const Token& Parser::peek() const {                 // retorna o token atual
    return tokens[current];
}

const Token& Parser::advance() {                    // avanca para o proximo token
    if (current < tokens.size()) {
        return tokens[current++];
    }
    throw std::runtime_error("error");
}

bool Parser::match(TokenType type) const {                  // verifica se o token atual eh do tipo especificado
    return peek().type == type;
}

std::unique_ptr<Expression> Parser::parse(const std::string& input) {           // funçao de parseamento
    Lexer lexer(input);
    tokens = lexer.tokenize();
    current = 0;
    return parseExpression();
}

std::unique_ptr<Expression> Parser::parseExpression() {         // funçao principal
    return parseOrExpression();
}

std::unique_ptr<Expression> Parser::parseOrExpression() {               // parseia expressoes logicas OR
    auto expr = parseAndExpression();
    while (match(TokenType::OPERATOR) && peek().value == "||") {
        auto op = advance().value;
        auto right = parseAndExpression();
        expr = std::make_unique<BinaryExpression>(std::move(expr), op, std::move(right));
    }
    return expr;
}

std::unique_ptr<Expression> Parser::parseAndExpression() {          // parseia expressões logicas AND
    auto expr = parseEqualityExpression();
    while (match(TokenType::OPERATOR) && peek().value == "&&") {
        auto op = advance().value;
        auto right = parseEqualityExpression();
        expr = std::make_unique<BinaryExpression>(std::move(expr), op, std::move(right));
    }
    return expr;
}

std::unique_ptr<Expression> Parser::parseEqualityExpression() {             // parseia expressoes de igualdade
    auto expr = parseRelationalExpression();
    while (match(TokenType::OPERATOR) && (peek().value == "==" || peek().value == "!=")) {
        auto op = advance().value;
        auto right = parseRelationalExpression();
        expr = std::make_unique<BinaryExpression>(std::move(expr), op, std::move(right));
    }
    return expr;
}

std::unique_ptr<Expression> Parser::parseRelationalExpression() {           // parseia expressoes relacionais
    auto expr = parseAdditiveExpression();
    while (match(TokenType::OPERATOR) && (peek().value == "<" || peek().value == ">" || peek().value == "<=" || peek().value == ">=")) {
        auto op = advance().value;
        auto right = parseAdditiveExpression();
        expr = std::make_unique<BinaryExpression>(std::move(expr), op, std::move(right));
    }
    return expr;
}

std::unique_ptr<Expression> Parser::parseAdditiveExpression() {             // parseia expressoes de soma e sub
    auto expr = parseMultiplicativeExpression();
    while (match(TokenType::OPERATOR) && (peek().value == "+" || peek().value == "-")) {
        auto op = advance().value;
        auto right = parseMultiplicativeExpression();
        expr = std::make_unique<BinaryExpression>(std::move(expr), op, std::move(right));
    }
    return expr;
}

std::unique_ptr<Expression> Parser::parseMultiplicativeExpression() {               // parseia expressoes multiplicativas
    auto expr = parseUnaryExpression();
    while (match(TokenType::OPERATOR) && (peek().value == "*" || peek().value == "/")) {
        auto op = advance().value;
        auto right = parseUnaryExpression();
        expr = std::make_unique<BinaryExpression>(std::move(expr), op, std::move(right));
    }
    return expr;
}

std::unique_ptr<Expression> Parser::parseUnaryExpression() {                // parseia expressões unarias
    
    if (match(TokenType::OPERATOR) && peek().value == "-") {
        auto op = advance().value;
        auto operand = parseUnaryExpression();
        return std::make_unique<BinaryExpression>(std::make_unique<LiteralExpression>("0"), op, std::move(operand));
    }
    return parsePrimaryExpression();
}

std::unique_ptr<Expression> Parser::parsePrimaryExpression() {          // parseia expressoes primarias
    if (match(TokenType::INTEGER) || match(TokenType::BOOLEAN)) {
        return std::make_unique<LiteralExpression>(advance().value);
    } else if (match(TokenType::PARENTHESIS) && peek().value == "(") {
        advance(); // Consume '('
        auto expr = parseExpression();
        if (match(TokenType::PARENTHESIS) && peek().value == ")") {
            advance(); // Consume ')'
            return expr;
        } else {
            throw std::runtime_error("error");
        }
    }
    throw std::runtime_error("error");
}
