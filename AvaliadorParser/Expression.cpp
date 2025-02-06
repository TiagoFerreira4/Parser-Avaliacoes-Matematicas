#include "Expression.h"
#include <stdexcept>
#include <sstream>
#include <string>


bool stringToBool(const std::string& value) {       // string para booleano
    
    if (value == "true") {

        return true;

    }
    if (value == "false") { 

    return false;

    }

    throw std::invalid_argument("error");
}




std::string BinaryExpression::evaluate() const {            // expressso binaria
    
    
    std::string leftValue = left -> evaluate();

    std::string rightValue = right -> evaluate();     
    try{ 
        if (op == "+") {                        
            int sum; 
            std::string sumStr;

            sum = std::stoi(leftValue) + std::stoi(rightValue);
            sumStr = std::to_string(sum);        
            
            return sumStr;              // retorna o valor da soma em string
        } 
        else if (op == "-") {
            int sub; 
            std::string subStr;

            sub = std::stoi(leftValue) - std::stoi(rightValue);
            subStr = std::to_string(sub);   


            return subStr;              // retorna o valor da subtracao em string
        } 
        
        else if (op == "*") {
            
            int mult;
            std::string multStr;

            mult = std:: stoi(leftValue) * std::stoi(rightValue);
            multStr = std::to_string( mult);

            return multStr;                  // retorna o valor da multiplicacao em string
            
        } 
        else if (op == "/"){
            int divisor = std::stoi(rightValue);
            int div;
            std::string divStr;
            
            if (divisor == 0) {             //conferindo se esta acontecendo divisao por zero
            return "error";
            }
            else{

                div = std::stoi(leftValue) / std::stoi(rightValue);
                divStr = std::to_string(div);

                return divStr;          // valor da divisao em string
            }

        }
        
        else if (op == "&&"){
            bool leftBool = stringToBool(leftValue);
            bool rightBool = stringToBool(rightValue);

            if (leftBool && rightBool) {

                return "true";
            }

            else{
                return "false";
                }
            
        }
        else if (op == "||") {
            bool leftBool = stringToBool(leftValue);
            bool rightBool = stringToBool(rightValue);

            if (leftBool || rightBool) {

                return "true";
            }
            else{

                return "false";
            }
            


        } 
        
        else if (op == "==") {
            if (leftValue == rightValue){

                return "true";
            }

            else{

                return"false";
            }
        } 
        else if (op == "!=") {
            
            if (leftValue != rightValue) {
                return "true";

            }
            else {

                return "false";
            }
        }
        else if (op == "<" || op== ">" || op == ">=" || op == "<=") {
            if (leftValue == "true" || leftValue == "false" || rightValue == "true" || rightValue == "false"){      //confere se esta acontecendo uma comparacao maior que/ menor que com booleano(oq eh um erro)
                return "error";
            }
            else{
                bool check = std::stoi(leftValue) < std::stoi(rightValue);

                if (op == "<"){ 
                    if (std::stoi(leftValue) < std::stoi(rightValue)){
                        return "true";
                    }

                    else{
                        return "false";
                    }
                }

                if (op == ">"){ 
                    if (std::stoi(leftValue) > std::stoi(rightValue)){

                        return "true";
                    }
                    else{

                        return "false";
                    }
                }

                if (op == "<="){

                    if (std::stoi(leftValue) <= std::stoi(rightValue)){

                        return "true";
                    }
                    else{

                        return "false";
                    }
                }

                if (op == ">=") {

                    if (std::stoi(leftValue) >= std::stoi(rightValue)){

                        return "true";
                    }

                    else{
                        return "false";

                    }
                }

            }
            
        }
    }
    catch (const std::exception&){
        return "error";
    
    }
    return "error";
}
