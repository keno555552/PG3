#include <iostream>


/// <summary>
/// 再帰で給料計算
/// </summary>
/// <param name="time">働く時間</param>
/// <returns>総給料</returns>
int RecurPayCalc(int time) {
	int basePay = 100;
	if (time == 0) {
		return 0;
	} else if (time == 1) {
		return basePay;
	}
	return RecurPayCalc(time - 1) * 2 - 50;
}


/// <summary>
/// 普通の給料計算
/// </summary>
/// <param name="time">働く時間</param>
/// <returns>総給料</returns>
int NormalPayCalc(int time) {
	int basePay = 1226;
	if (time == 0) {
		return 0;
	}

	return NormalPayCalc(time - 1) + basePay;
}

int main() {

	/// 受け皿変数
	int payStyle{};
	int workTime{};
	int pay{};
	int isContinue = 0;

	while (isContinue < 1) {

		/// 開始
		std::cout << "/// ==================== Pay Calculator ===================== //" << std::endl;

		/// 給料の計算方法を選択
		std::cout << "Choose your Pay style: (0: Normal, 1: Recursion )" << std::endl;
		std::cin >> payStyle;

		/// 働く時間を入力
		std::cout << "Please enter your workTime:" << std::endl;
		std::cin >> workTime;

		/// 給料計算
		if (payStyle == 0) pay = NormalPayCalc(workTime);
		else pay = RecurPayCalc(workTime);

		/// 結果表示
		std::cout << "/// ======================== Result ========================= //" << std::endl;
		std::cout << "\nYour Pay is: " << pay << "\n" << std::endl;

		/// 続行確認
		std::cout << "/// ========================= Result ======================== //" << std::endl;
		std::cout << "Do you want to continue? (0: Yes, 1: No )" << std::endl;
		std::cin >> isContinue;

		std::cout << "/// === Thankyou for using our service, See you next time === //" << std::endl;

	}
	return 0;
}
