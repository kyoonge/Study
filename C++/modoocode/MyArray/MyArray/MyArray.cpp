#include <iostream>

class MyArray {
private:
      int dim;
      int* size;
      int* data;
      int totalSize;

      int getIndex(const int* indices) const {
            int index = 0;
            int multiplier = 1;
            for (int i = dim - 1; i >= 0; --i) {
                  index += indices[i] * multiplier;
                  multiplier *= size[i];
            }
            return index;
      }

public:
      MyArray(int dim, const int* array_size) : dim(dim), totalSize(1) {
            size = new int[dim];
            for (int i = 0; i < dim; ++i) {
                  size[i] = array_size[i];
                  totalSize *= array_size[i];
            }
            data = new int[totalSize](); // Initialize with zeros
      }

      ~MyArray() {
            delete[] size;
            delete[] data;
      }

      class Proxy {
      private:
            MyArray& array;
            int* indices;
            int level;

      public:
            Proxy(MyArray& array, int level) : array(array), level(level) {
                  indices = new int[array.dim]();
            }

            Proxy(MyArray& array, const int* indices, int level) : array(array), level(level) {
                  this->indices = new int[array.dim]();
                  for (int i = 0; i < level; ++i) {
                        this->indices[i] = indices[i];
                  }
            }

            ~Proxy() {
                  delete[] indices;
            }

            Proxy operator[](int index) {
                  if (level >= array.dim) {
                        throw std::out_of_range("Too many indices.");
                  }
                  int* newIndices = new int[array.dim];
                  for (int i = 0; i < level; ++i) {
                        newIndices[i] = indices[i];
                  }
                  newIndices[level] = index;
                  Proxy nextProxy(array, newIndices, level + 1);
                  delete[] newIndices;
                  return nextProxy;
            }

            operator int() {
                  if (level != array.dim) {
                        throw std::out_of_range("Not enough indices.");
                  }
                  return array.data[array.getIndex(indices)];
            }

            Proxy& operator=(int value) {
                  if (level != array.dim) {
                        throw std::out_of_range("Not enough indices.");
                  }
                  array.data[array.getIndex(indices)] = value;
                  return *this;
            }
      };

      Proxy operator[](int index) {
            int* initialIndices = new int[dim]();
            initialIndices[0] = index;
            Proxy p(*this, initialIndices, 1);
            delete[] initialIndices;
            return p;
      }
};

int main() {
      int size[] = { 2, 3, 4 }; // 3D array of size 2x3x4
      MyArray arr(3, size);

      // Fill the array with some values
      for (int i = 0; i < size[0]; ++i) {
            for (int j = 0; j < size[1]; ++j) {
                  for (int k = 0; k < size[2]; ++k) {
                        arr[i][j][k] = (i + 1) * (j + 1) * (k + 1);
                  }
            }
      }

      // Print the array
      for (int i = 0; i < size[0]; ++i) {
            for (int j = 0; j < size[1]; ++j) {
                  for (int k = 0; k < size[2]; ++k) {
                        std::cout << "arr[" << i << "][" << j << "][" << k << "] = " << arr[i][j][k] << std::endl;
                  }
            }
      }

      return 0;
}