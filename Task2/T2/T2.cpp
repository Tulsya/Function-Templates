#include <iostream>
#include <vector>

template <typename T>
class Table {
public:
    
    Table(int rows, int cols) : rows_(rows), cols_(cols), data_(rows, std::vector<T>(cols)) {}

    
    std::vector<T>& operator[](int row) {
        return data_[row];
    }

    const std::vector<T>& operator[](int row) const {
        return data_[row];
    }


    std::pair<int, int> Size() const {
        return { rows_, cols_ };
    }

private:
    int rows_;
    int cols_;
    std::vector<std::vector<T>> data_;
};

int main() {
  
    Table<int> test(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0] << std::endl;

    auto size = test.Size();
    std::cout << "Rows: " << size.first << ", Cols: " << size.second << std::endl;

    return 0;
}
