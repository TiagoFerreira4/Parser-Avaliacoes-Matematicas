#include "Evaluator.h"
#include <stdexcept>

std::string Evaluator::evaluate(const std::unique_ptr<Expression>& expression) const {
    if (!expression) {
        return "error";                         
    }
    return expression->evaluate();
}
