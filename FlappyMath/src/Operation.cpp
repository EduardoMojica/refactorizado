#include "Operation.h"
#include <cstdlib>
#include <ctime>

Operation::Operation() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    generate();
}

void Operation::generate() {
    number1 = std::rand() % 20 + 1;
    number2 = std::rand() % 20 + 1;

    int operationType = std::rand() % 4; // 0: addition, 1: subtraction, 2: multiplication, 3: division
    switch (operationType) {
        case 0: // Addition
            operatorSymbol = '+';
            correctAnswer = number1 + number2;
            break;
        case 1: // Subtraction
            operatorSymbol = '-';
            correctAnswer = number1 - number2;
            break;
        case 2: // Multiplication
            operatorSymbol = '*';
            correctAnswer = number1 * number2;
            break;
        case 3: // Division
            operatorSymbol = '/';
            if (number2 == 0) number2 = 1; // Avoid division by zero
            correctAnswer = static_cast<float>(number1) / number2;
            break;
    }

    incorrectAnswer = correctAnswer + static_cast<float>(std::rand() % 30 + 1);
}

float Operation::getCorrectAnswer() const {
    return correctAnswer;
}

float Operation::getIncorrectAnswer() const {
    return incorrectAnswer;
}

char Operation::getOperator() const {
    return operatorSymbol;
}

int Operation::getNumber1() const {
    return number1;
}

int Operation::getNumber2() const {
    return number2;
}