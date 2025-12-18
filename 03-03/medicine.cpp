#include "medicine.h"

/// 病種名の初期化
std::string Illname::name[5] = { "FLU", "COLD", "ALLERGY", "INFECTION", "POISONING" };

bool Medicine::administer(IllnessType illness) {

	/// 薬物を投与するメソッド
	printf("Try to administer for illness type %s\n", Illname::name[illness].c_str());

	/// 投与した薬物が対応する病種かどうかを確認する
	if (illness == target_illness) {

		/// 対応する病種であれば成功
		printf("Successfully for administer %s!\n",Illname::name[illness].c_str());
		return true;

	} else {

		/// 対応する病種でなければ失敗
		printf("Failed for administer %s!\n", Illname::name[illness].c_str());
		return false;

	}
}
