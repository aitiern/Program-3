#include "utility.h"
#include "filer.h"

void filer::makefile(int n, int range, string file_name) {
    ofstream outfile;
    outfile.open(file_name);

    if (!outfile) {
        cerr << "Error opening file: " << file_name << endl;
        return;
    }

    srand(int(time(NULL)));  // Seed once per file

    for (int i = 0; i < n; i++) {
        outfile << next_number(range) << endl;
    }

    outfile.close();
}

int filer::next_number(int range) {
    return rand() % (range + 1);  // range inclusive
}
