/*
QUESTION:
Given two words, startWord and targetWord, and a list of words wordList, find the length of the shortest transformation sequence from startWord to targetWord, such that only one letter can be changed at a time and each transformed word must exist in the wordList. Note that startWord is not a part of wordList.

EXAMPLE:
Input:
startWord = "hit"
targetWord = "cog"
wordList = {"hot", "dot", "dog", "lot", "log", "cog"}

Output: 5

EXPLANATION:
The shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> "cog", which is 5 words long.

APPROACH:
1. Use BFS to find the shortest transformation sequence.
2. Push all words in wordList into an unordered_set to enable efficient lookup and deletion.
3. Use a queue to explore all possible transformations and track the number of steps taken.
4. For each word, try changing each character to every other character from 'a' to 'z', and if the transformed word exists in the set, add it to the queue for further exploration and remove it from the set to avoid revisiting.

CODE:
*/

#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

// Function to find the length of the shortest transformation sequence from startWord to targetWord.
int wordLadderLength(string startWord, string targetWord, vector<string> &wordList) {
    // Creating a queue ds of type {word,transitions to reach ‘word’}.
    queue<pair<string, int>> q;

    // BFS traversal with pushing values in queue 
    // when after a transformation, a word is found in wordList.
    q.push({startWord, 1});

    // Push all values of wordList into a set
    // to make deletion from it easier and in less time complexity.
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(startWord);

    while (!q.empty()) {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        // we return the steps as soon as
        // the first occurrence of targetWord is found.
        if (word == targetWord)
            return steps;

        for (int i = 0; i < word.size(); i++) {
            // Now, replace each character of ‘word’ with char
            // from a-z then check if ‘word’ exists in wordList.
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                // check if it exists in the set and push it in the queue.
                if (st.find(word) != st.end()) {
                    st.erase(word);
                    q.push({word, steps + 1});
                }
            }
            word[i] = original;
        }
    }
    // If there is no transformation sequence possible
    return 0;
}

/*
EXAMPLE USAGE:
string startWord = "hit";
string targetWord = "cog";
vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
int result = wordLadderLength(startWord, targetWord, wordList);
// Output: 5

TIME COMPLEXITY:
- O(M^2 * N), where M is the length of each word and N is the total number of words in the wordList. For each word, we potentially check M * 26 transformations.

SPACE COMPLEXITY:
- O(M * N), for the queue and the unordered_set.
*/
