#pragma once

namespace g2 {
	class Stack {
	private:
		int current;
		int stack[4096];

	public:
		Stack() {
			current = -1;
		}

		bool isNone() {
			return length() == 0;
		}

		bool isQuad() {
			return peek() == 1;
		}

		bool isTexture() {
			return peek() == 2;
		}

		void pushQuad() {
			push(1);
		}

		void pushTexture() {
			push(2);
		}

		int pop() {
			if (length() == 0) throw "cannot pop from empty g2::stack";

			int value = stack[current];

			--current;

			return value;
		}

	private:

		int length() {
			return current + 1;
		}

		void push(int value) {
			if (length() == 4096) throw "g2::Stack is full";

			++current;

			stack[current] = value;
		}

		int peek() {
			if (length() == 0) return -1;

			return stack[current];
		}
	};
}
