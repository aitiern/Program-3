# Program 3 — Sorting & Timing (C++)

A three-part C++ assignment that generates large random data sets, sorts them
with a general-purpose sort, verifies the results, and measures performance.

## Parts

### Part 1 — Data generation
Generates three files of **100,000 random integers** each (values 0–32,000)
using a small `filer` helper.
- `filer.h` / `filer.cpp` — file-generation helper
- `main.cpp` — driver that writes `Part1Data1.txt`, `Part1Data2.txt`, `Part1Data3.txt`

### Part 2 — General sort + verification + timing
Reads each generated file, sorts it, confirms the result is ordered, and reports
the elapsed time per file.
- `generalSort.h` / `generalSort.cpp` — the sorting routine
- `SortCheck.h` / `SortCheck.cpp` — verifies a sequence is sorted
- `main.cpp` — runs the three trials and prints timings

Example run (see `Outputs`):
```
Trial 1 (Part1Data1.txt): Sorted in 0.049 seconds.
Trial 2 (Part1Data2.txt): Sorted in 0.049 seconds.
Trial 3 (Part1Data3.txt): Sorted in 0.047 seconds.
```

### Part 3 — Column sort *(in progress)*
Scaffolding for a column-sort implementation. The source files
(`Columnsort.cpp`, `SortCheck.cpp`, `main.cpp`) are currently empty stubs.

## Building

Each part is self-contained. From a part's directory:

```bash
g++ -std=c++17 main.cpp filer.cpp -o program      # Part 1
g++ -std=c++17 main.cpp generalSort.cpp SortCheck.cpp -o program  # Part 2
```

## Repository layout

```
Program 3/
├── Part1/   # data generation
├── Part2/   # sort + verify + timing
├── Part3/   # column sort (WIP)
└── Outputs  # captured sample run output
```

> Note: the generated `*Data*.txt` / `Sorted*.txt` files and compiled binaries
> are produced at build/run time and are excluded via `.gitignore`.
