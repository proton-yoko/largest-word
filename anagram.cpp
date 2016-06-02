#include <fstream>
#include <iostream>
#include <ctype.h>

using namespace std;

int main(){

	// "アナグラムに使う１６文字の英字を入力してください"
	char letters[17] = "iamveryhungrynow";
	int abcnum[256];
	int i;

	//lettersとして与えられた各アルファベット数を数える
	for(i='a'; i<='z'; i++){
		abcnum[i]=0;
	}
	for(i=0; i<16; i++){
		abcnum[letters[i]]++;
	}


	ifstream ifs("sortedwords.txt");
	char word[32];
	char longest[32];
	if(ifs.fail()){
		cerr << "ファイル読み込みに失敗" << endl;
		return -1;
	}

	while(ifs.getline(word, 32)){
		int yet = 0;
	//ここまではうまくいってるっぽい
	
		for(i=0; i<=strlen(word); i++){
			abcnum[tolower(word[i])]--;
			if(abcnum[word[i]]<0){
				yet=1;
				break;
			}
		}
		if(yet == 0){
			//cout << "見つけた！" << endl;
			for(int k=0; k<=strlen(word); k++){
				longest[k] = word[k];
				break;
			}
		}
	}


	cout << "一番長い単語は[" ;
	for(i=0; i<strlen(longest); i++){
		cout << longest[i] ;
	}
	cout << "]" << endl;

	return 0;
}
