#ifndef FILER_H
#define FILER_H

// Class object to create a file of random integers
class filer {
public:
    void makefile(int n, int range, string file_name);
    // Writes `n` random integers in range [0, range] to file_name (one per line)

private:
    int next_number(int range);
    // Returns random int in [0, range]
};

#endif // FILER_H