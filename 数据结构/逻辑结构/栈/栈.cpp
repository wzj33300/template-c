#define NDEBUG 0

#include <cassert>
#include <cstdio>

namespace MyStack {
    template <class T, class Container = MyArray::Array<T> >
    struct Stack {
        Container a;

        Stack(int maxn) : a = Container(maxn) {}

        void pop() {
            a.pop();
        }

        void push(T data) {
            a.push(data);
        }

        T& top() {
            return a.top();
        }

        int size() {
            return a.size();
        }

        bool empty() {
            return a.empty();
        }
    };
}  // namespace MyStack

