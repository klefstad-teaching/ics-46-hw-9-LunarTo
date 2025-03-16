#include "ladder.h"
#include <fstream>
#include <unordered_set>

void error(string word1, string word2, string msg){
    cout << word1 << word2 << msg << endl;
}

//trying to see if the distance between two strings equal with d
bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    int editAmount = 0;

    int hold1 = str1.size();
    int hold2 = str2.size();
    if(abs(hold1 - hold2) > d){
        return false;
    }

    for(int i = 0, j = 0 ; i < str1.size() && j < str2.size() ; ++i, ++j ){
        if(str1[i] == str2[j]){
            continue;
        }
        else{
            ++editAmount;
            if(editAmount > d){
            return false;
            }
            if(str1.size() > str2.size()){
                ++i;
            }
            else if(str2.size() > str1.size()){
                ++j;
            }
        }
    }

    return true;
}

//uses edit distance
bool is_adjacent(const string& word1, const string& word2){
    //return edit_distance_within(word1, word2, 1);
    int hold1 = word1.size();
    int hold2 = word2.size();

    //check same length but more than one char diff
    int check1 = 0;
    if(hold1 == hold2){
        for(int i = 0; i < hold1; ++i){
            if(word1[i] == word2[i]){
                continue;
            }
            else{
                ++check1;
            }
        }
        if(check1 > 1){
            return false;
        }
        return true;
    }

    //still adjacent but extra or missing letter
    int num = 0;
    int i = 0, j =0;
    if(abs(hold1 - hold2) == 1){
        if(hold1 > hold2){
            while(i < hold1 && j < hold2){
                if(word1[i] == word2[j]){
                    ++i;
                    ++j;
                }
                else{
                    ++i;
                    ++num;
                }
            }
        }      

        if(hold1 < hold2){
            while(i < hold1 && j < hold2){
                if(word1[i] == word2[j]){
                    ++i;
                    ++j;
                }
                else{
                    ++j;
                    ++num;
                }
            }
        }  
        if(num > 1){
            return false;
        }
        else{
            return true;
        }

    }
    return false;
}

//need to look at this one
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    queue<vector<string>> ladderQueue;
    unordered_set<string> visited;

    visited.insert(begin_word);
    ladderQueue.push({begin_word});

    while(!ladderQueue.empty()){
        int size = ladderQueue.size();

        for(int i = 0; i < size ; ++i){
            vector<string> ladder = ladderQueue.front();
            ladderQueue.pop();

            string last = ladder.back();
            for(string word : word_list){
                if(is_adjacent(last,word)){
                    if(visited.find(word) == visited.end()){
                        visited.insert(word);
                        vector<string> newLadder = ladder;
                        newLadder.push_back(word);

                        if(word == end_word){
                            return newLadder;
                        }
                        ladderQueue.push(newLadder);
                    }
                } 
            }  
        }
    }
    return {};
    
}

void load_words(set<string> & word_list, const string& file_name){
    ifstream in(file_name);
    string line;

    while(getline(in,line)){
        word_list.insert(line);
    }
    
}

void print_word_ladder(const vector<string>& ladder){
    if(ladder.empty()){
        cout << "No word ladder found.";
    }
    else{
        cout <<"Word ladder found: ";
        for(int i = 0 ; i < ladder.size() ; ++i){
            cout << ladder[i] << " ";
        }
    }
    cout <<endl;
}


//
void verify_word_ladder(){
    cout << "Test" <<endl;
    set<string> wordList = {"cat, cot, cod, dod, dog"};
    vector<string> size;
    size = generate_word_ladder("cat","dog",wordList);
    cout << size.size() << endl;
}   