#include <iostream>
using namespace std;

namespace {
    template<typename StackDataType>
    class stack {
        /*
         * This is a bubble which is an item in the stack
         * it will store the next_node: which is a pointer to what come before this item
         * and value: is the value of this item
         */
        struct node {
            StackDataType value;
            node *next_node = nullptr;
        };

        // is a global pointer that always point to the item at the top
        node *head_ = nullptr;

        // stack size tracker
        int size_ = 0;

        runtime_error empty_err_msg_ = runtime_error("the stack is empty!");

        /*
         * create a new bubble (node) and give its next_node the value of the previous item pointer
         * @param <StackDataType> (val): the new value u want to store
         */
        void connect_node(const StackDataType &val) {
            node *new_node = new node;
            new_node->next_node = head_;
            new_node->value = val;
            head_ = new_node;
            size_++;
        }

        /*
         * in case of a pop item it will create a temporary point that will store the old head_ to delete it later
         * then it will give head_ the value of the popped node <next_node> that the old head_ was pointing at
         * last delete the temp_old_head which is the old head_
         */
        void disconnect_node() {
            if (head_ == nullptr) return;
            const node *temp_old_head = head_;
            head_ = head_->next_node;
            delete temp_old_head;
            size_--;
        }

    public:
        /*
         * add new item to the stack
         * @param <StackDataType> (val): the item value the u want to push
         */
        void push(const StackDataType &val) {
            connect_node(val);
        }


        // remove the item at the top of the stack
        void pop() {
            if (empty()) {
                throw empty_err_msg_;
            }
            disconnect_node();
        }

        /*
         * get the current size of the stack
         * @return <int> the stack size_
         */
        int size() const {
            return size_;
        }

        /*
         * get the current size of the stack
         * @return <int> the stack size_
         */
        int empty() const {
            return size_ == 0;
        }

        /*
         * get the item that is at the top of the stack
         * also u can give it a new value bc its a reference return function
         * @return a reference to the head_->value
         */
        StackDataType &top() {
            if (empty()) {
                throw empty_err_msg_;
            }
            return head_->value;
        }

        ~stack() {
            while (!empty()) {
                pop();
            }
        }
    };
}


int main() {
    stack<int> stack1;
    stack1.push(5);
    stack1.push(8);
    stack1.push(9);
    stack1.top() = 30;

    cout << stack1.top() << endl;

    cout << stack1.size() << endl;

    try {
        stack1.pop();
        stack1.pop();
        stack1.pop();
        stack1.pop();
    } catch (const runtime_error &err) {
        cout << err.what() << endl;
    }

    cout << stack1.size() << endl;

    if (!stack1.empty()) {
        stack1.top() = 30;
    }
    return 0;
}
