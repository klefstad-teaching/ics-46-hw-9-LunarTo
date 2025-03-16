#include "ladder.h"
#include <fstream>
#include <unordered_set>
#include <cmath>

void error(string word1, string word2, string msg){
    cout << word1 << word2 << msg << endl;
}

//trying to see if the distance between two strings equal with d, need to account for substiutions
bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    int editAmount = 0;

    int hold1 = str1.size();
    int hold2 = str2.size();
    if(abs(hold1 - hold2) > d){
        return false;
    }

    int i = 0;
    int j = 0;
    for(; i < str1.size() && j < str2.size() ; ++i, ++j ){
        if(str1[i] == str2[j]){
            continue;
        }
        else{
            ++editAmount;

            if(str1.size() > str2.size()){
                ++i;
            }
            else if(str2.size() > str1.size()){
                ++j;
            }
            else{
                continue;
            }
        }
    }
    editAmount += (hold1 - i) + (hold2 - j);
    if(editAmount > d){
        return false;
    }

    return true;
}

//uses edit distance
bool is_adjacent(const string& word1, const string& word2){
    int distance = 1;
    if(edit_distance_within(word1,word2, distance)){
        return true;
    }
    return false;
}

//need to look at this one
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    queue<vector<string>> ladderQueue;
    ladderQueue.push({begin_word});
    unordered_set<string> visited;
    visited.insert(begin_word);
    
    vector<string> ladder;
    string last;

    
    while(!ladderQueue.empty()){
        ladder = ladderQueue.front();
        ladderQueue.pop();

        last = ladder.back();
        for(string word : word_list){
            if(is_adjacent(last, word)){
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
    return ladder;
    
}

//what does this function do, not sure if im doing the right thing
void load_words(set<string> & word_list, const string& file_name){
    ifstream in(file_name);
    string line;

    while(getline(in,line)){
        word_list.insert(line);
    }
    
}

void print_word_ladder(const vector<string>& ladder){
    for(int i = 0; i < ladder.size() ; ++i){
        cout << ladder[i] << " ";
    }
}

void verify_word_ladder(){
    cout << "Test" <<endl;
}