#define NDEBUG 0

#include <cassert>

namespace MyArray {
	template<class T>
	struct Array {
		T *a;
		int len;
		int maxSize;

		Array(int maxn) : a(new T[maxn]), len(0), maxSize(maxn) {}

		~Array() {
			delete a;
		}

		void push(T data) {
			assert(len != maxSize);
			a[len++] = data;
		}

		void pop() {
			assert(len != 0);
			--len;
		}

		Array<T> &operator[](int at) {
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
			return !!len;
		}

		T &front() {
			return a[0];
		}

		T &back() {
			return a[len - 1];
		}
	};
}