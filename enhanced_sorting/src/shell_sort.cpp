#include "shell_sort.h"

template <typename T>
void shell_sort(std::vector<T>& arr) {
    const std::size_t n = arr.size();
    if (n < 2) return;

    std::size_t gap = 1;
    while (gap < n / 3) {
        gap = gap * 3 + 1;
    }

    for (; gap > 0; gap /= 3) {
        for (std::size_t i = gap; i < n; ++i) {
            T key = arr[i];
            std::size_t j = i;
            while (j >= gap && arr[j - gap] > key) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = key;
        }
    }
}

template void shell_sort<int>(std::vector<int>&);
template void shell_sort<double>(std::vector<double>&);
template void shell_sort<float>(std::vector<float>&);
