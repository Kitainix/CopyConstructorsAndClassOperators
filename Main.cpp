#include <iostream>
#include <string>

// Тема: "Конструкторы копирования и операторы класса."

class Integer {
private:
	int data;

	// Такая реализация полей лучше подойдёт для математически достоверных целых чисел.
	/*
	bool sign;
	unsigned long long units;
	*/

public:
	Integer():data(0){}
	
	Integer(int num) :data(num) {}

	// Перегрузка оператора, как дружественной функции.
	friend Integer operator+(Integer A, Integer B) {
		Integer result;
		result.data = A.data + B.data;
		return result;
		// return Integer(this->data + obj.data);
	}

	friend std::ostream& operator<<(std::ostream& out, const Integer& obj);

	int GetNum() {
		return data;
	}

	// Оператор перегрузки, как метод класса.
	Integer& operator=(const Integer& other) {
		this->data = other.data;
		return *this;
	}

};


std::ostream& operator<<(std::ostream& out, const Integer& obj) {
	return out << obj.data;
}

// Перегрузка оператора, как независимая функция.
Integer operator-(Integer a, Integer b) {
	return a.GetNum() - b.GetNum();
}

// Перегрузка оператора, как независимая функция.
Integer operator*(Integer a, Integer b) {
	return a.GetNum() * b.GetNum();
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	Integer a{ 5 };
	Integer b{ 8 };

	std::cout << a + b << '\n';
	std::cout << a - b << '\n';
	std::cout << a * b << '\n';

	std::cout << a + 5 << '\n';
	std::cout << a - 5 << '\n';
	std::cout << a * 3 << '\n';

	std::cout << 4 + b << '\n';
	std::cout << 7 - b << '\n';
	std::cout << 1 * b << '\n';


	return 0;
}

/*
  1. Операторы можно перегружать только для классов. Для встроенных типов данных операторы не перегружают.
  
  2. Оператор не может менять своего поведения в ходе перегрузки.
  
  3. Ряд операторов под запретом перегрузки:
		".", "?:", "&" (унарный амперсант), "::", "->".
*/