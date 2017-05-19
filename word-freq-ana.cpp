#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int main(){
    vector<string*> words;
    
    char filename[32];
    cout << "Enter filename: ";
    cin >> filename;
    ifstream is(filename);
    
    if(is.is_open()){
        char ch;
        while(is){
            ch = is.get();
            if(isalpha(ch)){
                words.push_back(new string);
                while(isalpha(ch)){
                    *words[words.size()-1] += ch;
                    ch = is.get();
                }
            }
        }
    }
    int charcount = 0;
    for(int i = 0; i < words.size(); i++){
        charcount += (*(words[i])).length();
    }
    double meanLength = charcount;
    meanLength/=words.size();
    cout << "Mean word length: " << meanLength << endl;
}