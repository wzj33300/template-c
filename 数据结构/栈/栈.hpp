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
			if (empty()) {
				throw "stack is empty!!!";
			}
			--len;
		}

		void push(T data) {
			if (len == maxSize) {
				throw "stack is full!!!";
			}
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
