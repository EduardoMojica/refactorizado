#pragma once
#include "Pipe.h"
#include "utils.h"
#include <cstdlib>

class PipeFactory {
public:
    static Pipe createPipe(int x) {
        int minGapY = 100;
        int maxGapY = SCREEN_HEIGHT - PIPE_GAP - 100;
        int gapY = minGapY + rand() % (maxGapY - minGapY + 1);
        return Pipe(x, gapY);
    }
};