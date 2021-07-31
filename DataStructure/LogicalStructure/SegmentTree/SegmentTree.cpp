#define NDEBUG 0

#include <cassert>

namespace MySegmentTree {
    template<class T>
    struct Node {
        int l, r;
        T data;

        Node(int L, int R, T DATA) : l(L), r(R), data(DATA) {}
    };

    template<class T>
    struct SegmentTree {
        int maxSize;
        Node<T> *a;

        SegmentTree(int maxn, T *data) : maxSize(maxn), a(new Node<T>[maxn << 2]) {
            build(1, maxn, 1, data);
        }

        ~SegmentTree() {
            delete a;
        }

        void build(int l, int r, int p, T *data) {
            if (l == r) {
                a[p] = data[l];
            }
            int mid = (l + r) >> 1;
            build(l, m, p << 1), build(m + 1, r, (p << 1) + 1);
            a[p] = a[p << 1] + a[(p << 1) + 1];
        }
        

    };
}


