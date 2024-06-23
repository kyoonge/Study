#include <iostream>
#include <cassert>

class MyArray {
private:
    const int dim;   // 몇 차원 배열인지
    int* size;       // 인덱스를 저장해놓는 배열
    int* data;       // 실제 배열 데이터 저장소
    int total_size;  // 전체 배열 크기
    int calculateIndex(const int* indices) const;    // 다차원 인덱스를 1차원 인덱스로 변환

public:
    MyArray(int dim, int* array_size);
    ~MyArray();

    class Proxy {       // Proxy 클래스
    private:
        MyArray& array;
        int* indices;   // 각 차원에 대한 인덱스 저장
        int level;  //현재 접근하고 있는 차원

    public:
        Proxy(MyArray& arr, int* idx, int lvl);
        Proxy operator[](int index);
        operator int& ();
        Proxy& operator=(const int& value);
    };

    Proxy operator[](int index);    // 배열 접근용 operator[]
};

int MyArray::calculateIndex(const int* indices) const
{
    int flat_index = 0;
    int multiplier = 1;
    for (int i = dim - 1; i >= 0; --i) {
        flat_index += indices[i] * multiplier;
        multiplier *= size[i];
    }
    return flat_index;
}

MyArray::MyArray(int dim, int* array_size) : dim(dim)
{
    size = new int[dim];
    total_size = 1;
    for (int i = 0; i < dim; ++i) {
        size[i] = array_size[i];
        total_size *= size[i];
    }
    data = new int[total_size]();   //메모리 할당 후 0으로 초기화
}

MyArray::~MyArray()
{
    delete[] size;
    delete[] data;
}

MyArray::Proxy MyArray::operator[](int index)
{
    int* indices = new int[dim]();
    indices[0] = index;
    return Proxy(*this, indices, 1);
}

MyArray::Proxy MyArray::Proxy::operator[](int index)
{
    indices[level] = index;
    return Proxy(array, indices, level+1);
}

MyArray::Proxy::Proxy(MyArray& arr, int* idx, int lvl): array(arr), indices(idx), level(lvl) {}

MyArray::Proxy::operator int& ()
{
    int flat_index = array.calculateIndex(indices);
    return array.data[flat_index];
}

MyArray::Proxy& MyArray::Proxy::operator=(const int& value)
{
    int flat_index = array.calculateIndex(indices);
    array.data[flat_index] = value;
    return *this;
}
