#include <iostream>

template<class T>
class table {
private:
    T rows;
    T cols;
    T** data;
public:
    table(T r, T c) : rows(r), cols(c) {
        data = new T * [rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
        }
    }

    ~table() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    T* operator [](T index) {
        return data[index];
    }

    const T* operator [](T index) const {
        return data[index];
    }

    T Size() const {
        return rows * cols;
    }
};

int main()
{
    auto test = table<int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0] << std::endl;
    std::cout << "Size of the table: " << test.Size() << std::endl;
    return 0;
}
