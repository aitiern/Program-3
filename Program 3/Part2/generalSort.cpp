#include "generalSort.h"
#include <algorithm> // for std::swap

// Sift-down heapify for 0-based index heap
static void heapify(vector<short>& a, int n, int i) {
    while (true) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n && a[l] > a[largest]) largest = l;
        if (r < n && a[r] > a[largest]) largest = r;
        if (largest == i) break;
        swap(a[i], a[largest]);
        i = largest;
    }
}

void heapSort(vector<short>& a) {
    const int n = static_cast<int>(a.size());
    if (n <= 1) return;

    // Build max-heap
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(a, n, i);
    }
    // Extract elements from heap one by one
    for (int end = n - 1; end > 0; --end) {
        swap(a[0], a[end]);          // move current max to its final place
        heapify(a, end, 0);          // restore heap in the reduced array
    }
}

