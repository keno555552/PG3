#include <iostream>
#include <stdio.h>

/// クラステンプレート定義
template<typename T>
class Comparator {
public:

	T a;
	T b;

	/// コンストラクタ
	Comparator(T first, T second):a(first), b(second) {};

	/// メンバ関数
	T Greater() {
		if (a > b) {
			return static_cast<T>(a);
		} else {
			return static_cast<T>(b);
		}
	}

};

int main() {
	
	/// int型での利用
	int a = 5;
	int b = 10;
	Comparator<int> comp(a,b);
	printf("Greater value between %d and %d is %d\n", a,b,comp.Greater());
	
	/// float型での利用
	float c = 5;
	float d = 10;
	Comparator<float> comp2(c,d);
	printf("Greater value between %.2ff and %.2ff is %.2ff\n", c,d,comp2.Greater());
	
	/// double型での利用
	double e = 5;
	double f = 10;
	Comparator<double> comp3(e,f);
	printf("Greater value between %lf and %lf is %lf\n", e,f,comp3.Greater());

	return 0;
}
