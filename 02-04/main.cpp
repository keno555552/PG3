#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <Time.h>
#include <functional>

/// <summary>
/// メイン関数、遅延表示と実行関数
/// </summary>
/// <param name="fn">実行する関数</param>
/// <param name="delayMs">遅延秒数(ミリ秒)</param>
/// <param name="roll">ダイスの結局</param>
/// <param name="userGuess">プレイヤー入力した数値</param>
void DelayReveal(std::function<void(int, int)> fn, unsigned int delayMs, int roll, int userGuess) {

	/// 遅延表示の演出
	printf("Rolling dice\n");
	for (int i = 3; i > 0; i--) {
		for (int j = i; j > 0; j--) {
			printf(".");
		}
		printf("\n");
		Sleep(delayMs);
	}
	/// 関数を呼び出す
	fn(roll, userGuess);
}

int main() {

	/// ランダムシードの初期化
	srand((unsigned int)time(NULL));

	int inputNumber = 0;
	int isConitnue = 0;


	/// ゲーム開始メッセージ
	printf("=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
	printf("Odd-Even Guessing Game \n");
	printf("=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");

	/// ゲームループ
	while (isConitnue != 1) {

		/// ユーザー入力
		printf("Guess if the dice roll will be Odd (1) or Even (0): ");
		scanf_s("%d", &inputNumber);

		/// 1から6までのランダムな数を生成
		int diceRoll = (rand() % 6) + 1;

		/// ラムダ式で結果処理を定義
		std::function ShowResult = [](int roll, int userGuess) {
			printf("You rolled a %d!\n", roll);

			/// 偶数奇数の判別
			int parity = roll % 2;
			printf("It is ");
			if (parity == 1) {
				printf("Odd\n");
			} else {
				printf("Even\n");
			}

			if (roll % 2 == userGuess) {
				printf("Congratulations! You guessed correctly!\n");
			} else {
				printf("Sorry, better luck next time.\n");
			}
		};


		/// 結果を遅延表示
		DelayReveal(ShowResult, 1000, diceRoll, inputNumber);

		printf("=====================================\n");
		/// 続けるかどうかの確認
		printf("Do you want to play again? Yes (0) / No (1): ");
		scanf_s("%d", &isConitnue);
		printf("\n");
		printf("=====================================\n");
	}

	printf("=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
	printf("Thank you for playing! Goodbye!\n");
	printf("=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");



	return 0;
}
