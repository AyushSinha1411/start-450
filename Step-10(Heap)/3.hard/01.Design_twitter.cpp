/*
QUESTION:
Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and get the news feed. Your design should support the following methods:
1. `postTweet(int userId, int tweetId)`: Compose a new tweet.
2. `getNewsFeed(int userId)`: Retrieve the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themselves. Tweets must be ordered from most recent to least recent.
3. `follow(int followerId, int followeeId)`: Follower follows a followee.
4. `unfollow(int followerId, int followeeId)`: Follower unfollows a followee.

Example:
Input:
Twitter twitter = new Twitter();
twitter.postTweet(1, 5); // User 1 posts a tweet (id = 5)
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]
twitter.follow(1, 2);    // User 1 follows user 2
twitter.postTweet(2, 6); // User 2 posts a tweet (id = 6)
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]
twitter.unfollow(1, 2);  // User 1 unfollows user 2
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]

APPROACH:
1. Use an unordered_map to store tweets, where the key is the userId and the value is a vector of pairs containing tweetId and timestamp.
2. Use another unordered_map to store followers, where the key is the userId and the value is a set of followeeIds.
3. Implement the methods to handle posting tweets, following/unfollowing users, and retrieving the news feed using a priority queue to keep the most recent tweets.

CODE:
*/

#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

class Twitter {
private:
    unordered_map<int, vector<pair<int, int>>> tweets; // userId -> (tweetId, timestamp) pairs
    unordered_map<int, set<int>> followers; // userId -> set of followeeIds
    int timestamp;

public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(tweetId, timestamp++);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> newsFeed;
        auto compare = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second; // Sort by timestamp in ascending order
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);

        // Add the user's own tweets to the priority queue
        for (const auto& tweet : tweets[userId]) {
            pq.push(tweet);
            if (pq.size() > 10) {
                pq.pop(); // Keep only the 10 most recent tweets
            }
        }

        // Add tweets from the users followed by the current user to the priority queue
        for (int followeeId : followers[userId]) {
            for (const auto& tweet : tweets[followeeId]) {
                pq.push(tweet);
                if (pq.size() > 10) {
                    pq.pop(); // Keep only the 10 most recent tweets
                }
            }
        }

        // Retrieve tweets from the priority queue
        while (!pq.empty()) {
            newsFeed.push_back(pq.top().first);
            pq.pop();
        }
        
        // Reverse the order of tweets to get them in descending order of timestamp
        reverse(newsFeed.begin(), newsFeed.end());

        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followers[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

/*
TIME COMPLEXITY:
- postTweet: O(1), for inserting a tweet.
- getNewsFeed: O(n log 10), where n is the total number of tweets from the user and the users they follow.
- follow: O(1), for inserting a followee.
- unfollow: O(1), for removing a followee.

SPACE COMPLEXITY:
- O(U + T), where U is the number of users and T is the number of tweets.
*/
