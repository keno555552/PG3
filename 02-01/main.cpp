#include <iostream>
#include <iomanip>

/// <summary>
/// ‘Î”äŠÖ”(¬‚³‚¢‚Ù‚¤‚ğ•Ô‚·)
/// </summary>
/// <typeparam name="T">Œ`</typeparam>
/// <param name="a">‘Î”ä‘ÎÛa</param>
/// <param name="b">‘ÎÛ‘ÎÛb</param>
/// <returns>¬‚³‚¢‚Ù‚¤</returns>
template<typename T>
T Min(T& a, T& b) {
	if (a < b) return a;
	else return b;
}

int main() {

	/// intŒ^‚Ì”äŠr
	{
		int i = 10;
		int j = 20;

		printf("int i is %d\n", i);
		printf("int j is %d\n", j);
		printf("Lesser value is %d\n\n", Min(i, j));
	}

	/// floatŒ^‚Ì”äŠr
	{
		float i = 10.0f;
		float j = 20.0f;

		printf("float i is %.1f\n", i);
		printf("float j is %.1f\n", j);
		printf("Lesser value is %.1f\n\n", Min(i, j));
	}

	/// doubleŒ^‚Ì”äŠr
	{
		double i = 10.0;
		double j = 20.0;

		printf("double i is %lf\n", i);
		printf("double j is %lf\n", j);
		printf("Lesser value is %lf\n\n", Min(i, j));
	}


	return 0;
}
