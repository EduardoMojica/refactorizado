#ifndef OPERATION_H
#define OPERATION_H

#include <string>
#include <random>

class Operation {
public:
    Operation();
    void generate();
    float getCorrectAnswer() const;
    float getIncorrectAnswer() const;
    std::string getOperationString() const;

private:
    int number1;
    int number2;
    char operatorSymbol;
    float correctAnswer;
    float incorrectAnswer;

    float generateIncorrectAnswer() const;
};

#endif // OPERATION_H