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
	int normalPay{};
	int recurPay{};
	int isContinue = 0;

	while (isContinue < 1) {

		/// 開始
		std::cout << "/// ============== Pay comparator ============== //" << std::endl;

		/// 働く時間を入力
		std::cout << "Please enter workTime:" << std::endl;
		std::cin >> workTime;

		/// 給料計算
		normalPay = NormalPayCalc(workTime);
		recurPay = RecurPayCalc(workTime);

		/// 結果表示
		std::cout << "/// ======================== Result ========================= //" << std::endl;
		std::cout << "Normal Pay for " << workTime << " hours is: " << normalPay << std::endl;
		std::cout << "Recur Pay for " << workTime << " hours is: " << recurPay << std::endl;
		std::cout << ((normalPay < recurPay) ? "Recur Pay is higher." : "Normal Pay is higher.") << std::endl;

		/// 続行確認
		std::cout << "/// ========================= Result ======================== //" << std::endl;
		std::cout << "Do you want to continue? (0: Yes, 1: No )" << std::endl;
		std::cin >> isContinue;

		std::cout << "/// === Thankyou for using our service, See you next time === //" << std::endl;

	}
	return 0;
}
