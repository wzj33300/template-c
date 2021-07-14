//#define NDEBUG
#include <cassert>
#include <iostream>
namespace MyLinkedList {
    template <class T>
    struct Node {
        T        data;
        Node<T>* next;  // 后续
        Node<T>* prev;  // 前驱
        Node(T _data, Node<T>* _next = NULL, Node<T>* _prev = NULL)
            : data(_data), next(_next), prev(_prev) {}
    };
    template <class T>
    struct LinkedList {
        int      len;
        Node<T>* head;
        Node<T>* cache;
        int      cachePosition;
        LinkedList() : len(0), head(NULL), cache(NULL) {}
        ~LinkedList() {
            while (!empty()) {
                erase(0);
            }
        }
        Node<T>* find(int position) {
            assert(position < len);
            if (!cache)
                cache = head, cachePosition = 0;
            Node<T>* q;
            int      cnt = 0;
            int      _a = position - cachePosition, _b = position;
            if (abs(_a) >= abs(_b)) {
                q = head;
                while (q->next != NULL && cnt++ != _b) {
                    q = q->next;
                }
            } else {
                q = cache;
                if (_a < 0) {
                    while (q->prev != NULL && cnt++ != _a) {
                        q = q->prev;
                    }
                } else {
                    while (q->next != NULL && cnt++ != _a) {
                        q = q->next;
                    }
                }
            }
            return cache = q;
        }
        void insert(T data, int position) {
            assert(position <= len);
            if (position == 0) {  // 头部插入
                if (!head) {
                    head = new Node<T>(data, NULL, NULL);
                    ++len;
                    return;
                }

                Node<T>* a = new Node<T>(data, head, NULL);
                head->prev = a;
                head       = a;
            } else {
                Node<T>* q = find(position - 1);
                q->next    = new Node<T>(data, q->next, q);
            }
            ++len;
        }
        void push_back(T data) {
            insert(data, len);
        }
        void push_front(T data) {
            insert(data, 0);
        }
        void erase(int position) {
            assert(position < len);
            if (position == 0) {
                if (len == 1) {
                    head  = NULL;
                    cache = NULL;
                    --len;
                    return;
                }
                head = head->next;
                delete head->prev;
                head->prev = NULL;
            } else {
                Node<T>* q = find(position - 1);
                q->next    = q->next->next;
                delete q->next->prev;
                q->next->prev = q;
            }
            --len;
        }
        void pop_back() {
            erase(len - 1);
        }
        void pop_front() {
            erase(0);
        }
        T& operator[](int position) {
            return find(position)->data;
        }
        int size() {
            return len;
        }
        bool empty() {
            return !len;
        }
        T& front() {
            return find(len - 1)->data;
        }
        T& back() {
            return find(0)->data;
        }
    };
}  // namespace MyLinkedList

int main() {
    MyLinkedList::LinkedList<int> a;
    a.push_back(1);
    a.push_front(2);
    a.pop_front();
    a.pop_back();
    //    a.pop_front();
    a.push_front(12);
    std::cout << a[0] << std::endl << a.size() << std::endl;
}

//
//#include <iostream>
//#include <cstdio>
//#include <ctime>
// template <class T>
// T gcdV1(T a, T b) {
//    T _temp;
//    while (b != 0) {
//        _temp = a;
//        a = b;
//        b = _temp % b;
//    }
//    return a;
//}
// template <class T>
// T gcdV2(T a, T b) {
//    while (a != b) {
//        int big = a > b?a:b;
//        int small = a < b?a:b;
//        a = big - small;
//        b = small;
//    }
//    return a;
//
//
//}
// template <class T>
// T gcdV3(T a, T b) {
//    long long _temp = 0;
//    while (a != b) {
//        int _aaa = a & 1, _bbb = b & 1;
//        if (_aaa == 0) {
//            if (_bbb == 0)
//                a >>= 1, b >>= 1, ++_temp;
//            else
//                a >>= 1;
//        } else {
//            if (_bbb == 0)
//                b >>= 1;
//            else {
//                int _big = a > b ? a : b, _small = a < b ? a : b;
//                a = _big - _small, b = _small;
//            }
//        }
//    }
//    return a << _temp;
//}
//
// template <class T>
// void swapa(T& a, T& b) {
//    T _temp = a;
//    a = b;
//    b = _temp;
//}
// template <class T>
// T gcdV4(T a, T b) {
//    long long r = 0;
//    while (true) {
//        if (!a || !b)
//            return (a + b) << r;
//        while ((a & 1) == 0 && (b & 1) == 0)
//            ++r, a >>= 1, b >>= 1;
//        while ((a & 1) == 0)
//            a >>= 1;
//        while ((b & 1) == 0)
//            b >>= 1;
//        if (a < b)
//            swapa(a, b);
//        a -= b;
//    }
//}
//
// int main() {
//    std::cout << gcdV4(121310,5315353);
//    long long a, b;
//    system(R"(C:\Users\wzj\OneDrive\VScode\template-c\template_c.exe)");
//    freopen(R"(C:\Users\wzj\OneDrive\VScode\template-c\cmake-build-debug\.out)",
//    "r", stdin); std::cin >> a >> b; time_t t = clock();
//
//}
//
//// 1 1 2 3 5 8 13 21 34 55
//
