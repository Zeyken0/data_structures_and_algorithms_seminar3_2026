#include "quick_sort.h"

template <typename T>
static void quick_sort_impl(std::vector<T>& arr, std::size_t low, std::size_t high) {
    if (low >= high) return;

    const std::size_t mid = low + (high - low) / 2;
    std::swap(arr[mid], arr[high]);
    const T pivot = arr[high];

    std::size_t i = low;
    for (std::size_t j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            std::swap(arr[i], arr[j]);
            ++i;
        }
    }
    std::swap(arr[i], arr[high]);

    if (i > low) quick_sort_impl(arr, low, i - 1);
    if (i < high) quick_sort_impl(arr, i + 1, high);
}

template <typename T>
void quick_sort(std::vector<T>& arr) {
    if (arr.size() < 2) return;
    quick_sort_impl(arr, 0, arr.size() - 1);
}

template void quick_sort<int>(std::vector<int>&);
template void quick_sort<double>(std::vector<double>&);
template void quick_sort<float>(std::vector<float>&);
