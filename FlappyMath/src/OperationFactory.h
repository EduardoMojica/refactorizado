#pragma once
#include "Operation.h"
#include <cstdlib>

class OperationFactory {
public:
    static Operation createRandomOperation() {
        int opType = rand() % 2; // 0: suma, 1: resta
        int a = rand() % 20 + 1;
        int b = rand() % 20 + 1;
        if (opType == 0) {
            return Operation(a, b, '+');
        } else {
            if (a < b) std::swap(a, b);
            return Operation(a, b, '-');
        }
    }
};