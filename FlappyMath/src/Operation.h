#ifndef OPERATION_H
#define OPERATION_H

#include <string>

class Operation {
public:
    Operation(int a, int b, char op);
    std::string getText() const;
    int getResult() const;
private:
    int a, b;
    char op;
};

#endif 