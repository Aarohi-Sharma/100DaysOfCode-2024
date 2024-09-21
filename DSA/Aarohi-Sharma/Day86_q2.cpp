class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()){ 
            return 0;
        }
        queue<string> wordQueue;
        wordQueue.push(beginWord);
        int distance = 1;
        while (!wordQueue.empty()) {
            int size = wordQueue.size();
            distance++; 
            while (size-- > 0) {
                string currWord = wordQueue.front();
                wordQueue.pop();
                for (int i = 0; i < currWord.length(); i++) {
                    string temp = currWord;
                    for (char j = 'a'; j <= 'z'; j++) {
                        temp[i] = j;
                        if (temp == endWord) return distance;
                        if (wordSet.find(temp) != wordSet.end()) {
                            wordQueue.push(temp);
                            wordSet.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
