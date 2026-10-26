#include <iostream>
using namespace std;

namespace {
    template<typename VectorDataType>
    class vector {
        // bc array is just a pointer to the first element in it
        VectorDataType *v_array_ = nullptr;

        // to resize the array when hitting the current array size cap
        int capacity_ = 0;

        // tracking how many items are currently in the vector
        int size_ = 0;

        /*
         * If we hit the current array cap create a new array with its capacity = to the old size_ * 2
         * @param <int> (new_capacity_): how big is the new size of the new array
         * @return void
         */
        void resize(const int new_capacity) {
            VectorDataType *new_v_array = new VectorDataType[new_capacity];
            for (int i = 0; i < size_; ++i) {
                new_v_array[i] = v_array_[i];
            }

            delete[] v_array_;
            v_array_ = new_v_array;
            capacity_ = new_capacity;
        }

    public:
        /*
         * Adding new item to the vector
         * @param <VectorDataType> (value): the new value that u want to store in the vector
         */
        void push_back(const VectorDataType &value) {
            if (size_ >= capacity_) {
                const int new_cap = size_ == 0 ? 1 : size_ * 2;
                resize(new_cap);
            }
            v_array_[size_] = value;
            size_++;
        }

        /*
         * remove the last item in the vector array
         */
        void pop_back() {
            if (size_ == 0) return;
            size_--;
        }

        /*
         * make the vector array bigger
         * @param <int> (new_cap): the new capacity for the vector array
         */
        void reserve(const int new_cap) {
            if (new_cap <= capacity_) {
                return;
            }
            resize(new_cap);
        }

        // shrink the size of vector array to be exactly as the number of items in it
        void shrink_to_fit() {
            if (capacity_ > size_) {
                resize(size_);
            }
        }

        // remove all items from the vector
        void clear() {
            size_ = 0;
        }

        /*
         * return the value of the item at the given index
         * @param <int> (index): the index u want to see the value at
         * @return <VectorDataType> : the value at the index given. if the return is 0 then its out of bond
         */
        VectorDataType at(const int index) const {
            if (index >= size_) {
                return 0;
            }
            return v_array_[index];
        }

        // @return the current size
        int size() const {
            return size_;
        }

        // @return the array capacity limit
        int capacity() const {
            return capacity_;
        }

        // @return the array pointer which is the fist item pointer
        VectorDataType *data() const {
            return v_array_;
        }

        // @return the item at the start of the vector
        VectorDataType front() const {
            return v_array_[0];
        }

        // @return the item at the end of the vector
        VectorDataType back() const {
            return v_array_[size_ - 1];
        }

        // @return <bool> : true if the vector is empty and false if not
        bool empty() const {
            if (size_ == 0) {
                return true;
            }
            return false;
        }


        ~vector() { delete[] v_array_; }
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
    cout << vec1.at(5) << endl;
    cout << "The first item in the vector is: " << vec1.front() << endl;
    cout << "The last item in the vector is: " << vec1.back() << endl;
    cout << "The pointer to the array used to store the vector: " << vec1.data() << endl;
    return 0;
}
