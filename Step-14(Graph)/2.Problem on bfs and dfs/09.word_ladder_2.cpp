/*
QUESTION:
Given two words, beginWord and endWord, and a list of words wordList, find all the shortest transformation sequences from beginWord to endWord, such that only one letter can be changed at a time and each transformed word must exist in the wordList.

EXAMPLE:
Input:
beginWord = "hit"
endWord = "cog"
wordList = {"hot", "dot", "dog", "lot", "log", "cog"}

Output: 
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]

APPROACH:
1. Use BFS to find all shortest transformation sequences.
2. Push all words in wordList into an unordered_set to enable efficient lookup and deletion.
3. Use a queue to explore all possible transformations and track the sequence of words forming the transformation.
4. For each word, try changing each character to every other character from 'a' to 'z', and if the transformed word exists in the set, add it to the queue for further exploration and remove it from the set to avoid revisiting.

CODE:
*/

#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

// Function to find all shortest transformation sequences from beginWord to endWord.
vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList) {
    // Push all values of wordList into a set
    // to make deletion from it easier and in less time complexity.
    unordered_set<string> st(wordList.begin(), wordList.end());
    
    // Creating a queue ds which stores the words in a sequence which is
    // required to reach the targetWord after successive transformations.
    queue<vector<string>> q;

    // BFS traversal with pushing the new formed sequence in queue 
    // when after a transformation, a word is found in wordList.
    q.push({beginWord});

    // A vector defined to store the words being currently used
    // on a level during BFS.
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);
    int level = 0;
   
    // A vector to store the resultant transformation sequence.
    vector<vector<string>> ans;
    while (!q.empty()) {
        vector<string> vec = q.front();
        q.pop();

        // Now, erase all words that have been
        // used in the previous levels to transform
        if (vec.size() > level) {
            level++;
            for (auto it : usedOnLevel) {
                st.erase(it);
            }
        }

        string word = vec.back();

        // store the answers if the end word matches with targetWord.
        if (word == endWord) {
            // the first sequence where we reached end
            if (ans.size() == 0) {
                ans.push_back(vec);
            } else if (ans[0].size() == vec.size()) {
                ans.push_back(vec);
            }
        }

        for (int i = 0; i < word.size(); i++) {   
            // Now, replace each character of ‘word’ with char
            // from a-z then check if ‘word’ exists in wordList.
            char original = word[i];
            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;
                if (st.count(word) > 0) { 
                    // Check if the word is present in the wordList and
                    // push the word along with the new sequence in the queue.
                    vec.push_back(word);
                    q.push(vec);
                    // mark as visited on the level
                    usedOnLevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
    }
    return ans;
}

/*
EXAMPLE USAGE:
string beginWord = "hit";
string endWord = "cog";
vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
vector<vector<string>> result = findSequences(beginWord, endWord, wordList);
// Output: 
// [
//   ["hit","hot","dot","dog","cog"],
//   ["hit","hot","lot","log","cog"]
// ]

TIME COMPLEXITY:
- O(N * M * 26), where N is the length of each word, M is the number of words in the wordList. For each word, we potentially check N * 26 transformations.

SPACE COMPLEXITY:
- O(M * N), for the queue and the unordered_set.
*/
