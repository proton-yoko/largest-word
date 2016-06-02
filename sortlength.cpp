#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

int main(){

	char dic[240000][32];

	ifstream ifs("words");
	char w[32];
	int i=0;
	while(ifs.getline(w, 32)){

		for(int k=0; k<strlen(w); k++){
			dic[i][k] = w[k];
		}

//		cout << dic[i] << endl;
		i++;
	}
	int	numwords = i;

	//ファイルから読み込んで、順番にdic[]に言葉を入れ終わった

	ofstream outputfile("sortedwords.txt");
	for(int len=32; len>0; len--){
		for(i=0; i<numwords; i++){
			if(strlen(dic[i])==len){
				outputfile << dic[i];
				outputfile << "\n";
			}
		}
	}
	outputfile.close();


	return 0;
}
