#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

template <typename T>
T square(const T& value) {
    return value * value;
}

template <typename T>
std::vector<T> square(const std::vector<T>& values) {
    std::vector<T> result;
    result.reserve(values.size());

    std::transform(values.begin(), values.end(), std::back_inserter(result), [](const T& value) {
        return value * value;
        });

    return result;
}

int main() {
    int singleValue = 4;
    std::cout << "[IN]: " << singleValue << std::endl;
    std::cout << "[OUT]: " << square(singleValue) << std::endl;

    std::vector<int> vec = { -1, 4, 8 };
    std::cout << "[IN]: ";
    for (const auto& val : vec) {
        std::cout << val << ", ";
    }
    std::cout << std::endl;

    std::vector<int> resultVec = square(vec);

    std::cout << "[OUT]: ";
    for (const auto& val : resultVec) {
        std::cout << val << ", ";
    }
    std::cout << std::endl;

    return 0;
}

