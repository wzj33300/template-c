#define NDEBUG 0

#include <cassert>

namespace MyQueue {
    template <class T, class Container = MyArray::Array<T> >
    struct Queue {
        Container a;

        Queue(int maxn) {
            a    = new T[maxn];
            head = tail = 0;
        }

        Queue<T>& operator=(const Queue<T>& other) {
            a    = other.a;
            head = other.head;
            tail = other.tail;
        }

        void pop() {
            assert(!empty());
            head = (head + 1) % maxSize;
        }

        void push(T data) {
            assert((tail + 1) % maxSize != head);
            a[tail] = data;
            tail    = (tail + 1) % maxSize;
        }

        T& front() {
            return a[head];
        }

        T& back() {
            return a[tail];
        }

        int size() {
            return (tail - head + maxSize) % maxSize;
        }

        bool empty() {
            return head == tail;
        }
    };
}  // namespace MyQueue