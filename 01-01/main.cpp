#include <iostream>
#include <stdio.h>
#include <list>

/// <summary>
/// リストをprintfします
/// </summary>
/// <param name="stationList">StationList</param>
void PrintStationList(std::list<std::string>& stationList) {
	int i = 1;
	for (auto& station : stationList) {
		printf("JY%d %s\n", i, station.c_str());
		i++;
	}
}


/// <summary>
/// 駅を挿入する
/// </summary>
/// <param name="stationList">目標リスト</param>
/// <param name="targetStation">一個前の駅</param>
/// <param name="inputStation">対象駅</param>
void ImportStation(std::list<std::string>& stationList, std::string targetStation, std::string inputStation) {
	auto target = std::find_if(stationList.begin(),
		stationList.end(),
		[&](const std::string& station) {
			return station == targetStation;
		});

	if (target != stationList.end()) {
		stationList.insert(++target, inputStation);
	} else {
		stationList.push_back(inputStation);
	}
}

std::list<std::string> stationList{
	"Tokyo",
	"Kanda",
	"Akihabara",
	"Okachimachi",
	"Ueno",
	"Uguisudani",
	"Nippori",
	"Tabata",
	"Komagome",
	"Sugamo",
	"Otsuka",
	"Ikebukuro",
	"Mejiro",
	"Takadanobaba",
	"Shin-Okubo",
	"Shinjuku",
	"Yoyogi",
	"Harajuku",
	"Shibuya",
	"Ebisu",
	"Mekuro",
	"Gotanda",
	"Osaki",
	"Shinagawa",
	"Tamachi",
	"Hamamatsucho",
	"Shimbashi",
	"Yurakucho",
};

int main() {

	/// プリン部分
	printf("/// ============= 1970's Yamanote Line ================ ///\n");
	{
		PrintStationList(stationList);
	}
	printf("\n\n");

	/// 足し部分
	ImportStation(stationList, "Nippori", "Nishi-nippori");


	/// プリン部分
	printf("/// ============= 2019's Yamanote Line ================ ///\n");
	{
		PrintStationList(stationList);
	}
	printf("\n\n");

	/// 足し部分
	ImportStation(stationList, "Shinagawa", "Takanawa Gateway");


	/// プリン部分
	printf("/// ============= 2022's Yamanote Line ================ ///\n");
	{
		PrintStationList(stationList);
	}
	printf("\n\n");


	return 0;
}
