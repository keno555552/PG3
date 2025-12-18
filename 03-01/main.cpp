#include <iostream>
#include <stdio.h>
#include "Enemy.h"


int main() {

	/// 初期化
	Enemy* enemy = new Enemy();
	int playerMove = 0;

	while (true) {
		/// ============ プレイヤー入力 ============///
		printf("=====================================\n");
		printf("Enemy Distance : %d\n", enemy->GetDistance());
		printf("=====================================\n");
		printf("Input Player Move (+: Move Closer, -: Move Away, 0: Stay) : ");
		scanf_s("%d",& playerMove);

		/// ============ プレイヤー移動 ============///
		enemy->PlayerMove(playerMove);

		/// ============ 敵更新 ============///
		printf("\n\n");
		enemy->Update();

		printf("\n\n\n");
	}


	delete enemy;
	return 0;
}
