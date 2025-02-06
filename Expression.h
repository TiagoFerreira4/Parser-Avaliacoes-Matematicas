#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <memory>
#include <string>

using namespace std;


class Expression {
public:
    virtual ~Expression() = default;
    virtual string evaluate() const = 0; 
};


class LiteralExpression: public Expression {
private:
    string value;

public:
    explicit LiteralExpression(const string& value){

        this-> value = value;
    }
    


    string evaluate() const override{

        return value;
    }
};


class BinaryExpression: public Expression {           
private:
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;
    string op;

public:
    BinaryExpression(std::unique_ptr<Expression> left, const std::string& op,std::unique_ptr<Expression> right)  : left(std::move(left)), op(op), right(std::move(right)) {} //construtor

    std::string evaluate() const override;

    
};

#endif 