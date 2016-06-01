#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(){

	cout << "アナグラムに使う１６文字の英字を入力してください";

	string letters;//ここに16文字入れる
	cin >> letters ;



	ifstream ifs("words");
	char word[50];
	char longest[50];
	if(ifs.fail()){
		cerr << "ファイル読み込みに失敗" << endl;
		return -1;
	}

	while(ifs.getline(word, 50-1)){
		
	}



	cout << "一番長い単語は[" << longest << "]" << endl;

	return 0;
}
