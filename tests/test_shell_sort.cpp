#include <catch.hpp>
#include "shell_sort.h"
#include <vector>

TEST_CASE("ShellSort: пустой массив", "[shell_sort]") {
    std::vector<int> arr;
    shell_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("ShellSort: один элемент", "[shell_sort]") {
    std::vector<int> arr = {0};
    shell_sort(arr);
    REQUIRE(arr == std::vector<int>{0});
}

TEST_CASE("ShellSort: уже отсортированный", "[shell_sort]") {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    shell_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("ShellSort: обратный порядок", "[shell_sort]") {
    std::vector<int> arr = {5, 4, 3, 2, 1};
    shell_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("ShellSort: произвольный порядок", "[shell_sort]") {
    std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    shell_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 1, 2, 3, 3, 4, 5, 5, 6, 9});
}

TEST_CASE("ShellSort: все элементы равны", "[shell_sort]") {
    std::vector<int> arr = {7, 7, 7, 7, 7};
    shell_sort(arr);
    REQUIRE(arr == std::vector<int>{7, 7, 7, 7, 7});
}

TEST_CASE("ShellSort: отрицательные числа", "[shell_sort]") {
    std::vector<int> arr = {-3, 0, -1, 5, -10, 2};
    shell_sort(arr);
    REQUIRE(arr == std::vector<int>{-10, -3, -1, 0, 2, 5});
}

TEST_CASE("ShellSort: два элемента, оба порядка", "[shell_sort]") {
    SECTION("по возрастанию") {
        std::vector<int> arr = {1, 2};
        shell_sort(arr);
        REQUIRE(arr == std::vector<int>{1, 2});
    }
    SECTION("по убыванию") {
        std::vector<int> arr = {2, 1};
        shell_sort(arr);
        REQUIRE(arr == std::vector<int>{1, 2});
    }
}

TEST_CASE("ShellSort: double", "[shell_sort][double]") {
    SECTION("положительные дробные") {
        std::vector<double> arr = {3.5, 1.25, 2.75, 0.5, 4.0};
        shell_sort(arr);
        REQUIRE(arr == std::vector<double>{0.5, 1.25, 2.75, 3.5, 4.0});
    }
    SECTION("отрицательные и положительные") {
        std::vector<double> arr = {-1.5, 2.25, -3.75, 0.0, 1.5};
        shell_sort(arr);
        REQUIRE(arr == std::vector<double>{-3.75, -1.5, 0.0, 1.5, 2.25});
    }
    SECTION("пустой массив") {
        std::vector<double> arr;
        shell_sort(arr);
        REQUIRE(arr.empty());
    }
}
