#pragma once
#include <vector>
#include <string>

/// 病種を定義する列挙型
enum IllnessType
{
	FLU,
	COLD,
	ALLERGY,
	INFECTION,
	POISONING,
	illnessTypeCount
};

/// 病種名を格納する構造体
struct Illname {
	static std::string name[5];
};

/// 薬物クラスの定義
class Medicine
{
public:

	/// 薬物を投与するメソッド
	bool administer(IllnessType illness);

protected:

	/// 薬物名
	std::string name;

	/// 対応する病種
	int target_illness;
};

