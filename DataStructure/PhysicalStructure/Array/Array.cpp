#define NDEBUG

#include <cassert>

namespace MyArray {
    template<class T>
    struct Array {
        T *a;
        int len;
        int maxSize;

        Array(int maxn) : a(new T[maxn]), len(0), maxSize(maxn) {}

        ~Array() {
            delete[] a;
        }

        void insert(T data, int position) { // 插入到location位置, 后面的元素后移
            assert(position <= len);
            assert(len < maxSize);
            for (int i = len - 1; i <= position; --i){
                a[i + 1] = a[i];
            }
            ++len;
            a[position] = data;
        }

        void push_back(T data) {
            insert(data, len);
        }

        void push_front(T data) {
            insert(data, 0);
        }

        void erase(int position) { // 删除location位置
            assert(len != 0);
            for (int i = position + 1; i < len; ++i) {
                a[i - 1] = a[i];
            }
            --len;
        }

        void pop_back() {
            erase(len - 1);
        }

        void pop_front() {
            erase(0);
        }

        T& operator[](int at) {
            return a[at];
        }

        T &at(int at) {
            assert(at < len);
            return a[at];
        }

        int size() {
            return len;
        }

        bool empty() {
            return !len;
        }

        T &front() {
            return a[0];
        }

        T &back() {
            return a[len - 1];
        }
    };
}