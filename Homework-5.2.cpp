#include <iostream>

template<class T>
class Table {
private:
    T rows;
    T cols;
    T** data;
public:
    Table(T r, T c) : rows(r), cols(c) {
        data = new T * [rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
        }
    }

    ~Table() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    T* operator [](index) {
        return data[index];
    }

    const T* operator [](index) const {
        return data[index];
    }

    T Size() const {
        return rows * cols;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
