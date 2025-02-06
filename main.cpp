#include <iostream>
#include <vector>
#include <string>
#include "Parser.h"
#include "Evaluator.h"

int main() {
    try {
        int c;

        std::cin >> c;
        std::cin.ignore(); // ingora o caractere de nova linha

        std::vector<std::string> expressions(c);

        for (int i = 0; i < c; ++i) {
            std::getline(std::cin, expressions[i]);
        }

        Parser parser;

        Evaluator evaluator;

        for (const auto& expr : expressions) {
            try {
                auto ast = parser.parse(expr); 
                auto result = evaluator.evaluate(ast); 
                std::cout << result << std::endl;
            } catch (const std::exception& e) {
                std::cout << "error" << std::endl;
            }
        }
    } catch (const std::exception& e) {
        std::cerr <<  e.what() << std::endl;
        return 1;
    }

    return 0;
}