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
	int workTimeInt{};
	int normalPay{};
	int recurPay{};
	int isContinue = 0;

	while (isContinue < 1) {

		/// 開始
		printf("/// ============== Pay comparator ============== //\n");

		/// 働く時間を入力
		printf("Please enter workTime:\n");
		scanf_s("%d", &workTimeInt);

		/// 給料計算
		normalPay = NormalPayCalc(workTimeInt);
		recurPay = RecurPayCalc(workTimeInt);

		/// 結果表示
		printf("/// ======================== Result ========================= //\n");
		printf("Normal Pay for %d hours is: %d\n", workTimeInt, normalPay);
		printf("Recur Pay for %d hours is: %d\n", workTimeInt, recurPay);
		printf((normalPay < recurPay) ? "Recur Pay is higher.\n" : "Normal Pay is higher.\n");

		/// 続行確認
		printf("/// ========================= Result ======================== //\n");
		printf("Do you want to continue? (0: Yes, 1: No )\n");
		std::cin >> isContinue;


	}
	printf("/// === Thankyou for using our service, See you next time === //\n");
	return 0;
}
