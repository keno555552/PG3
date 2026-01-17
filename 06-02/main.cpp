#include <Novice.h>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>
#include <cassert>
#include <thread>
#include <mutex>

const char kWindowTitle[] = "LE2B_05_カン_ケンリャン";

const int kWindowWidth = 1280;
const int kWindowHeight = 720;

/// マップチップデータ構造体
struct MapChipData
{
	std::vector<std::vector<bool>> data; // [y][x] の2次元配列
};

/// マップチップを描画する関数
void DrawMapChip(const MapChipData& mapChipData) {
	int chipSizeX = (int)kWindowWidth / (int)mapChipData.data[0].size();
	int chipSizeY = (int)kWindowHeight / (int)mapChipData.data.size();

	int rows = (int)mapChipData.data.size();
	if (rows == 0) return;
	int cols = (int)mapChipData.data[0].size();
	for (int y = 0; y < rows; ++y) {
		for (int x = 0; x < cols; ++x) {
			if (mapChipData.data[y][x]) {
				Novice::DrawBox(x * chipSizeX, y * chipSizeY, chipSizeX, chipSizeY, 0.0f, 0x222222FF, kFillModeSolid);
				Novice::DrawBox(x * chipSizeX, y * chipSizeY, chipSizeX, chipSizeY, 0.0f, 0xDDDDDDFF, kFillModeSolid);
			}
		}
	}
}

/// ファイルを読み込み
bool readFile(MapChipData* map, const std::string& path) {

	std::ifstream file(path);
	if (!file.is_open()) {
		assert(file.is_open());
	}

	// --- まずは幅と高さを計測する ---
	int mapWidth = 0;
	int mapHeight = 0;

	std::string line;
	while (std::getline(file, line)) {
		if (line.empty()) continue;

		mapHeight++;

		std::istringstream ss(line);
		std::string cell;
		int count = 0;

		while (std::getline(ss, cell, ',')) {
			count++;
		}

		mapWidth = max(mapWidth, count);
	}

	// ファイルを先頭に戻す
	file.clear();
	file.seekg(0);

	// --- MapChipData を必要サイズで初期化 ---
	MapChipData* mapChipData = map;
	mapChipData->data.resize(mapHeight, std::vector<bool>(mapWidth, false));

	// --- CSV を実際に読み込む ---
	int y = 0;
	while (std::getline(file, line) && y < mapHeight) {

		std::istringstream ss(line);
		std::string cell;
		int x = 0;

		while (std::getline(ss, cell, ',') && x < mapWidth) {

			// "1" → true, "0" → false として扱う
			mapChipData->data[y][x] = (cell == "1");

			x++;
		}
		y++;
	}
	Sleep(1000); // 読み込み待ち時間をシミュレート

	return true;
}

/// DrawLoading
void DrawLoading(int* parameter, int* maxTime) {
	float t = (float)*parameter / (float)*maxTime;
	float color = 256.0f * (1 - t);
	float size = 200.0f + (100.0f * t);
	Novice::DrawEllipse(int(((float)kWindowWidth / 2.0f)), int(((float)kWindowHeight / 2.0f)), (int)size, (int)size, 0.0f,
		0xFFFFFF | (int)color, kFillModeSolid);

	(*parameter)++;
	if (*parameter >= *maxTime) {
		(*parameter) = 0;
	}
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	/// マップチップデータ
	MapChipData mapChipData{};



	/// 動画タイマー
	int parameter = 0;
	int maxTime = 30;

	/// フラク
	bool isLoadComplete = false;

	/// ファイル読み込みを別スレッドで実行
	std::thread loader;
	loader = std::thread([&]() {
		isLoadComplete = readFile(&mapChipData, "./map.csv");
		});
	loader.detach();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		/// フラクによる描画切り替え
		if (!isLoadComplete) {
			DrawLoading(&parameter, &maxTime);
		} else {
			DrawMapChip(mapChipData);
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
