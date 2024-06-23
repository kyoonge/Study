#include <iostream>
#include <cassert>

class MyArray {
private:
    const int dim;   // �� ���� �迭����
    int* size;       // �ε����� �����س��� �迭
    int* data;       // ���� �迭 ������ �����
    int total_size;  // ��ü �迭 ũ��
    int calculateIndex(const int* indices) const;    // ������ �ε����� 1���� �ε����� ��ȯ

public:
    MyArray(int dim, int* array_size);
    ~MyArray();

    class Proxy {       // Proxy Ŭ����
    private:
        MyArray& array;
        int* indices;   // �� ������ ���� �ε��� ����
        int level;  //���� �����ϰ� �ִ� ����

    public:
        Proxy(MyArray& arr, int* idx, int lvl);
        Proxy operator[](int index);
        operator int& ();
        Proxy& operator=(const int& value);
    };

    Proxy operator[](int index);    // �迭 ���ٿ� operator[]
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
    data = new int[total_size]();   //�޸� �Ҵ� �� 0���� �ʱ�ȭ
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
