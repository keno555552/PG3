#include <iostream>
#include <stdio.h>
#include "medicine.h"
#include "medicineTypes.h"

/// 薬物の配列を作成
Medicine* medicine[4]{
	new Oseltamivir,
	new Paracetamol,
	new Loratadine,
	new Amoxicillin
};


int main() {

	/// 病人循環
	for (int i = 0; i < illnessTypeCount; i++) {

		/// 病人発生
		printf("----  Patient got %s ! ----\n", Illname::name[i].c_str());
		printf("\n");

		bool isHealed = false;
		for (auto& ptr : medicine) {
			/// 薬物を試しに投与してみる
			if (ptr->administer(static_cast<IllnessType>(i))) {
				/// 治癒成功
				isHealed = true;
				break;
			}
		}

		/// 治癒結果表示
		if (isHealed) {
			printf("Patient is healed!\n");
		} else {
			printf("Patient is NOT healed!\n");
		}

		printf("\n\n");
	}

	/// 薬物解放
	for (int i = 0; i < 4; i++) {
		delete medicine[i], medicine[i] = nullptr;
	}
	return 0;
}
