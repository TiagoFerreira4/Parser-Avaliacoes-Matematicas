#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "Expression.h"
#include <string>

class Evaluator {
public:
    std::string evaluate(const std::unique_ptr<Expression>& expression) const;          
};

#endif 