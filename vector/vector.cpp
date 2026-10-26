#include <iostream>
using namespace std;

namespace {
    template<typename VectorDataType>
    class vector {
        // bc array is just a pointer to the first element in it
        VectorDataType *_data = nullptr;

        // to resize the array when hitting the current array size cap
        int _capacity = 0;

        // tracking how many items are currently in the vector
        int _size = 0;

        /*
         * If we hit the current array cap create a new array with its capacity = to the old _size * 2
         * @param <int> (new_capacity): how big is the new size of the new array
         * @return void
         */
        void resize(const int new_capacity) {
            VectorDataType *new_data = new VectorDataType[new_capacity];
            for (int i = 0; i < _size; ++i) {
                new_data[i] = _data[i];
            }

            delete[] _data;
            _data = new_data;
            _capacity = new_capacity;
        }

    public:
        /*
         * Adding new item to the vector
         * @param <VectorDataType> (value): the new value that u want to store in the vector
         */
        void push_back(const VectorDataType &value) {
            if (_size >= _capacity) {
                const int new_cap = _size == 0 ? 1 : _size * 2;
                resize(new_cap);
            }
            _data[_size] = value;
            _size++;
        }

        /*
         * remove the last item in the vector array
         */
        void pop_back() {
            if (_size == 0) return;
            _size--;
        }

        /*
         * make the vector array bigger
         * @param <int> (new_cap): the new capacity for the vector array
         */
        void reserve(const int new_cap) {
            if (new_cap <= _capacity) {
                return;
            }
            resize(new_cap);
        }

        // shrink the size of vector array to be exactly as the number of items in it
        void shrink_to_fit() {
            if (_capacity > _size) {
                resize(_size);
            }
        }

        // remove all items from the vector
        void clear() {
            _size = 0;
        }

        /*
         * return the value of the item at the given index
         * @param <int> (index): the index u want to see the value at
         * @return <VectorDataType> : the value at the index given
         */
        VectorDataType at(const int index) const {
            if (index >= _size) {
                throw out_of_range("Out of range, try smaller index");
            }
            return _data[index];
        }

        // @return the current size
        int size() const {
            return _size;
        }

        // @return the array capacity limit
        int capacity() const {
            return _capacity;
        }

        // @return the array pointer which is the fist item pointer
        VectorDataType *data() const {
            return _data;
        }

        // @return the item at the start of the vector
        VectorDataType front() const {
            return _data[0];
        }

        // @return the item at the end of the vector
        VectorDataType back() const {
            return _data[_size - 1];
        }

        // @return <bool> : true if the vector is empty and false if not
        bool empty() const {
            if (_size == 0) {
                return true;
            }
            return false;
        }


        ~vector() { delete[] _data; }
    };
}


int main() {
    vector<int> vec1;
    vec1.push_back(3);
    vec1.push_back(7);
    vec1.push_back(55);
    vec1.push_back(66);
    vec1.push_back(99);
    cout << "The vector cap is: " << vec1.capacity() << endl;
    cout << "The current vector size is: " << vec1.size() << endl;
    // cout <<  vec1.at(1) << endl;
    cout << "The first item in the vector is: " << vec1.front() << endl;
    cout << "The last item in the vector is: " << vec1.back() << endl;
    cout << "The pointer to the array used to store the vector: " << vec1.data() << endl;
    return 0;
}
