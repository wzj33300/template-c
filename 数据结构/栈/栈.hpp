#include <cassert>
namespace MyStack {
	template<class T>
	struct Stack {
		int maxSize;
		T *a;
		int len;

		Stack(int maxn) {
			maxSize = maxn;
			a = new T[maxSize];
			len = 0;
		}

		~Stack() {
			delete a;
		}

		void pop() {
			assert(!empty());
			--len;
		}

		void push(T data) {
			assert(len != maxSize);
			a[len++] = data;
		}

		T &top() {
			return a[len - 1];
		}

		int size() {
			return len;
		}

		bool empty() {
			return len;
		}
	};
}
