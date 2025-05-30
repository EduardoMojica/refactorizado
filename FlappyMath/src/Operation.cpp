#include "Operation.h"
#include <sstream>

Operation::Operation(int a_, int b_, char op_) : a(a_), b(b_), op(op_) {}

std::string Operation::getText() const {
    std::ostringstream oss;
    oss << a << " " << op << " " << b;
    return oss.str();
}

int Operation::getResult() const {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    return 0;
}