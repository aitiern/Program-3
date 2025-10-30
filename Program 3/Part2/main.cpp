#include "utility.h"
#include "generalSort.h"
#include "SortCheck.h"

static bool readFileToVector(const string& path, vector<short>& out) {
    ifstream in(path);
    if (!in) {
        cerr << "Error: cannot open input file: " << path << "\n";
        return false;
    }
    out.clear();
    out.reserve(100000);
    short v;
    while (in >> v) out.push_back(v);
    return true;
}

static bool writeVectorToFile(const string& path, const vector<short>& data) {
    ofstream out(path);
    if (!out) {
        cerr << "Error: cannot open output file: " << path << "\n";
        return false;
    }
    for (short x : data) out << x << '\n';
    return true;
}

int main() {
    // ✅ Adjusted to point to Part1 folder
    vector<string> inputFiles = {
        "../Part1/Part1Data1.txt",
        "../Part1/Part1Data2.txt",
        "../Part1/Part1Data3.txt"
    };

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);

    int trial = 1;
    for (const auto& inPath : inputFiles) {
        vector<short> data;
        if (!readFileToVector(inPath, data)) {
            cerr << "Skipping trial " << trial << " due to read error.\n";
            ++trial;
            continue;
        }

        Timer t;
        heapSort(data);
        double secs = t.elapsed_time();

        bool ok = SortCheck(data);
        cout << "Trial " << trial << " (" << inPath << "): "
             << (ok ? "Sorted" : "NOT Sorted")
             << " in " << secs << " seconds.\n";

        const string outPath = "Sorted" + to_string(trial) + ".txt";
        writeVectorToFile(outPath, data);

        ++trial;
    }
    return 0;
}

