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
T Compare(T& a, T& b) {
	if (a < b) return a;
	else return b;
}

int main() {

	/// intŒ^‚Ì”äŠr
	{
		int i = 10;
		int j = 20;

		std::cout << "int i is " << i << std::endl;
		std::cout << "int j is " << j << std::endl;
		std::cout << "Lesser value is " << Compare(i, j) << "\n" << std::endl;
	}

	/// floatŒ^‚Ì”äŠr
	{
		float i = 10.0f;
		float j = 20.0f;

		std::cout << "float i is " << std::fixed << std::setprecision(1) << i << "f" << std::endl;
		std::cout << "float j is " << std::fixed << std::setprecision(1) << j << "f" << std::endl;
		std::cout << "Lesser value is " << std::fixed << std::setprecision(1) << Compare(i, j) << "f" << "\n" << std::endl;
	}

	/// doubleŒ^‚Ì”äŠr
	{
		double i = 10.0;
		double j = 20.0;

		std::cout << "double i is " << std::fixed << std::setprecision(6) << i << std::endl;
		std::cout << "double j is " << std::fixed << std::setprecision(6) << j << std::endl;
		std::cout << "Lesser value is " << std::fixed << std::setprecision(6) << Compare(i, j) << "\n" << std::endl;
	}


	return 0;
}
