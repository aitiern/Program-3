#include "utility.h"
#include "filer.h"

int main() {
    filer f;
    const int num_values = 100000;
    const int max_value = 32000;

    // Create 3 distinct files
    f.makefile(num_values, max_value, "Part1Data1.txt");
    f.makefile(num_values, max_value, "Part1Data2.txt");
    f.makefile(num_values, max_value, "Part1Data3.txt");

    cout << "Three files with 100,000 random integers created successfully." << endl;

    return 0;
}
