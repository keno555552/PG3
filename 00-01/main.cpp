#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>


int main() {
	/// コンソールのコードページをUTF-8に設定
    SetConsoleOutputCP(CP_UTF8);
	/// コンソールの入力コードページをUTF-8に設定
    SetConsoleCP(CP_UTF8);

	/// 標準出力をUTF-16モードに設定
    _setmode(_fileno(stdout), _O_U16TEXT);

	/// 日本語と中国語の文字列を出力
    const wchar_t str1[] = L"ありがとうございます";
    const wchar_t str2[] = L"謝謝";
    wprintf(L"%s\n", str1);
    wprintf(L"%s\n", str2);

    return 0;
}

