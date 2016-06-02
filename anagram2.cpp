#include <fstream>
#include <iostream>
#include <ctype.h>

using namespace std;

void checkABCNum(char abcnum[], char str[])
{
    int i;
    for(i='a'; i<='z'; i++){
        abcnum[i]=0;
    }
    for(i=0; i<16; i++){
        abcnum[tolower(str[i])]++;
    }
}

int canMakeWord(char abcnum_require[], char abcnum_given[])
{
    int i;
    for(i='a'; i<='z'; i++){
        if(abcnum_require[i] > abcnum_given[i]){
            return 0;
        }
    }
    return 1;
}

int main(){
    
    // "アナグラムに使う１６文字の英字を入力してください"
//    char letters[17] = "iamveryhungrynow";
    char letters[17];
    cout << "Input 16 letters" << endl;
    for(int i=0; i<=16; i++){
        letters[i]=getchar();
    }
    
    char abcnum[256];
    char tmp_abcnum[256];
    
    //lettersとして与えられた各アルファベット数を数える
    checkABCNum(abcnum, letters);
    
    ifstream ifs("sortedwords.txt");
    char word[32];
    if(ifs.fail()){
        cerr << "ファイル読み込みに失敗" << endl;
        return -1;
    }
    
    while(ifs.getline(word, 32)){
        checkABCNum(tmp_abcnum, word);
        if(canMakeWord(tmp_abcnum, abcnum)){
            cout << "一番長い単語は[ " << word << " ]" << endl;
            break;
        }
    }
    
    return 0;
}