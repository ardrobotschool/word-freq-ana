#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <array>

using namespace std;

int main(){
    vector<string*> words;
    array<vector<string*> *, 32> wordsByLength;
    
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
                while(true){
                    if(isalpha(ch)){
                        *words[words.size()-1] += ch;
                        ch = is.get();
                    }
                    else if(ch == '\''){
                        if(isalpha((ch = is.get()))){
                            (*words[words.size()-1] += '\'') += ch;
                            ch = is.get();
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    else{
        cout << "File could not be opened." << endl;
        return 0;
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
    for(int i = 0; i < wordsByLength.size(); i++){
        wordsByLength[i] = new vector<string*>;
    }
    for(int i = 0; i < words.size(); i++){
        wordsByLength[words[i]->length()]->push_back(words[i]);
    }
    for(int i = 0; i < wordsByLength.size(); i++){
        if(!wordsByLength[i]->empty()){
            cout << i << "-letter words: " << wordsByLength[i]->size() << endl;
        }
    }
    
    //Deallocate memory
    for(int i = 0; i < words.size(); i++){
        delete words[i];
    }
    for(int i = 0; i < wordsByLength.size(); i++){
        delete wordsByLength[i];
    }
}