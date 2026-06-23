#ifndef UTILITY_H
#define UTILITY_H

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ---- Timer (counts only the code you run between construction/reset and elapsed_time) ----
class Timer {
   public:
    Timer() { start_time = clock(); }
    double elapsed_time() {
        clock_t end_time = clock();
        return static_cast<double>(end_time - start_time) / static_cast<double>(CLOCKS_PER_SEC);
    }
    void reset() { start_time = clock(); }

   private:
    clock_t start_time;
};

#endif  // UTILITY_H
