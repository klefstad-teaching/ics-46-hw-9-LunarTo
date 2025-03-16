#include "ladder.h"
#include <fstream>
#include <unordered_set>

void error(string word1, string word2, string msg){
    cout << word1 << word2 << msg << endl;
}

//trying to see if the distance between two strings equal with d
bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    int editAmount;

    for(int i = 0, j = 0 ; i < str1.size() || j < str2.size() ; ++i, ++j ){
        if(str1[i] == str2[j]){
            ++i;
            ++j;
        }
        else{
            ++editAmount;
        }
    }

    if(editAmount != d){
        return false;
    }

    return true;
}

//testing my idea of what is adjacent is
bool is_adjacent(const string& word1, const string& word2){
    int distance = 0;


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
        cout << ladder[i] << endl;
    }
}

void verify_word_ladder(){
    cout << "Test" <<endl;
}