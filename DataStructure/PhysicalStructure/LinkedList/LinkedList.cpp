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