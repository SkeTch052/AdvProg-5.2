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

    class Wrapper {
    private:
        T* row;
        T cols;
    public:
        Wrapper(T* r, T c) : row(r), cols(c) {}

        T& operator[](T index) {
            if (index < 0 || index >= cols) {
                throw std::out_of_range("Wrong index");
            }
            return row[index];
        }
    };

    table& operator=(const table& created_table) {
        if (&created_table != this) {

            for (int i = 0; i < rows; i++) {
                delete[] data[i];
            }
            delete[] data;

            rows = created_table.rows;
            cols = created_table.cols;
            data = new T * [rows];
            for (int i = 0; i < rows; i++) {
                data[i] = new T[cols];
                for (int j = 0; j < cols; ++j) {
                    data[i][j] = created_table.data[i][j];
                }
            }
            return *this;
        }
    }

    Wrapper operator[](T index) {
        if (index < 0 || index >= rows) {
            throw std::out_of_range("Wrong index");
        }
        return Wrapper(data[index], cols);
    }

    const Wrapper operator[](T index) const {
        if (index < 0 || index >= rows) {
            throw std::out_of_range("Wrong index");
        }
        return RowWrapper(data[index], cols);
    }

    T Size() const {
        return rows * cols;
    }
};

int main()
{
    try {
        auto test = table<int>(2, 3);
        test[0][0] = 4;
        std::cout << test[0][0] << std::endl;
        std::cout << "Size of the table: " << test.Size() << std::endl;
    }
    catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }
    return 0;
}