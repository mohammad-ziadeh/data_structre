#include <iostream>

using namespace std;

namespace {
    template<typename QueueDataType>
    class queue {
        struct node {
            QueueDataType value;
            node *next_node = nullptr;
        };

        node *head_ = nullptr;
        node *tail_ = nullptr;
        size_t nodes_count_ = 0;
        runtime_error empty_err_msg_ = runtime_error("the queue is empty!");

        void connect_node(const QueueDataType &v) {
            node *new_node = new node();
            if (head_ == nullptr)
                head_ = new_node;

            if (tail_ != nullptr)
                tail_->next_node = new_node;

            tail_ = new_node;
            new_node->value = v;
            nodes_count_++;
        }

        void disconnect_node() {
            const node *old_head = head_;
            head_ = head_->next_node;
            delete old_head;
            if (head_ == nullptr)
                tail_ = nullptr;
            nodes_count_--;
        }

    public:
        void push(const QueueDataType &v) {
            connect_node(v);
        }

        void pop() {
            if (empty()) {
                throw empty_err_msg_;
            }
            disconnect_node();
        }

        const QueueDataType &front() {
            if (empty()) {
                throw empty_err_msg_;
            }
            return head_->value;
        }

        const QueueDataType &back() {
            if (empty()) {
                throw empty_err_msg_;
            }
            return tail_->value;
        }

        bool empty() const {
            return size() == 0;
        }

        size_t size() const {
            return nodes_count_;
        }

        ~queue() {
            while (!empty()) {
                pop();
            }
        }
    };
}

// Queue FIFO
int main() {
    queue<int> q1;
    q1.push(5);
    q1.push(7);
    q1.push(1);

    cout << q1.front() << endl;
    cout << q1.back() << endl;
    try {
        q1.pop();
        q1.pop();
        q1.pop();
        q1.pop();
    } catch (const runtime_error &err) {
        cout << err.what() << endl;
    }

    cout << q1.empty() << endl;
    // cout << q1.back() << endl;

    return 0;
}
