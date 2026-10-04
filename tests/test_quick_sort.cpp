#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "quick_sort.h"
#include <vector>

TEST_CASE("QuickSort: пустой массив", "[quick_sort]") {
    std::vector<int> arr;
    quick_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("QuickSort: один элемент", "[quick_sort]") {
    std::vector<int> arr = {42};
    quick_sort(arr);
    REQUIRE(arr == std::vector<int>{42});
}

TEST_CASE("QuickSort: уже отсортированный", "[quick_sort]") {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    quick_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("QuickSort: обратный порядок", "[quick_sort]") {
    std::vector<int> arr = {5, 4, 3, 2, 1};
    quick_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("QuickSort: произвольный порядок", "[quick_sort]") {
    std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    quick_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 1, 2, 3, 3, 4, 5, 5, 6, 9});
}

TEST_CASE("QuickSort: много дубликатов", "[quick_sort]") {
    std::vector<int> arr = {5, 1, 5, 1, 5, 1};
    quick_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 1, 1, 5, 5, 5});
}

TEST_CASE("QuickSort: отрицательные числа", "[quick_sort]") {
    std::vector<int> arr = {-1, -5, -3, -2, -4};
    quick_sort(arr);
    REQUIRE(arr == std::vector<int>{-5, -4, -3, -2, -1});
}

TEST_CASE("QuickSort: два элемента, оба порядка", "[quick_sort]") {
    SECTION("по возрастанию") {
        std::vector<int> arr = {1, 2};
        quick_sort(arr);
        REQUIRE(arr == std::vector<int>{1, 2});
    }
    SECTION("по убыванию") {
        std::vector<int> arr = {2, 1};
        quick_sort(arr);
        REQUIRE(arr == std::vector<int>{1, 2});
    }
}

TEST_CASE("QuickSort: double", "[quick_sort][double]") {
    SECTION("положительные дробные") {
        std::vector<double> arr = {3.5, 1.25, 2.75, 0.5, 4.0};
        quick_sort(arr);
        REQUIRE(arr == std::vector<double>{0.5, 1.25, 2.75, 3.5, 4.0});
    }
    SECTION("отрицательные и положительные") {
        std::vector<double> arr = {-1.5, 2.25, -3.75, 0.0, 1.5};
        quick_sort(arr);
        REQUIRE(arr == std::vector<double>{-3.75, -1.5, 0.0, 1.5, 2.25});
    }
    SECTION("пустой массив") {
        std::vector<double> arr;
        quick_sort(arr);
        REQUIRE(arr.empty());
    }
}
