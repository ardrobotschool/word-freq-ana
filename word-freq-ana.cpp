#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int main(){
    vector<string*> words;
    vector<string*> * wordsByLength[32];
    
    char filename[32];
    cout << "Enter filename: ";
    cin >> filename;
    ifstream is(filename);
    
    //Reading file:
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
    //Calculating mean word length:
    int charcount = 0;
    for(int i = 0; i < words.size(); i++){
        charcount += (words[i])->length();
    }
    double meanLength = charcount;
    meanLength/=words.size();
    cout << "Mean word length: " << meanLength << endl;
    
    //Categorizing words by length:
    for(int i = 0; i < 32; i++){
        wordsByLength[i] = new vector<string*>;
    }
    for(int i = 0; i < words.size(); i++){
        wordsByLength[words[i]->length()]->push_back(words[i]);
    }
    for(int i = 0; i < 32; i++){
        if(!wordsByLength[i]->empty()){
            cout << i << "-letter words: " << wordsByLength[i]->size() << endl;
        }
    }
}