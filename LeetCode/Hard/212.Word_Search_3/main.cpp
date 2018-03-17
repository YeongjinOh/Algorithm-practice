// It doesn't pass when board is ["ab"] words is ["a"]
// But I'm not sure why it is
class Solution {
    public:

        struct trie{
            bool end;
            char c;
            vector<trie*> children;
            trie(char c_) : end(false), c(c_), children(26, NULL) { }
            void insert(const string& word, int i) {
                if (i == word.size()) {
                    end = true;
                    return;
                }
                if (children[word[i]-'a'] == NULL)
                    children[word[i]-'a'] = new trie(word[i]);
                children[word[i]-'a']->insert(word,i+1);
            }

            void check(vector<vector<char>>& board, vector<string>& res, string& word, int i, int j) {
                if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == 0) return;
                word.push_back(c);
                board[i][j] = 0;
                if (end) {
                    end = false;
                    res.push_back(word);
                }
                int di[] = {-1, 0, 1, 0}, dj[] = {0, 1, 0, -1};
                for (int s=0; s<4; s++) {
                    int ii = i+di[s], jj = j+dj[s];
                    if (ii < 0 || jj < 0 || ii >= board.size() || jj >= board[0].size() || board[ii][jj] == 0) continue;
                    trie* child = children[board[ii][jj]-'a'];
                    if (child != NULL)
                        child->check(board, res, word, ii, jj);
                }
                //printf("word:%s\n", word.c_str());

                word.pop_back();
                board[i][j] = c;
            }
            ~trie() {
                for (int i=0; i<26; i++)
                    if (children[i] != NULL)
                        delete(children[i]);
            }

            void print(string& word) {
                word.push_back(c);
                if (end)
                    cout << word << endl;
                for (int i=0; i<26; i++)
                    if (children[i] != NULL)
                        children[i]->print(word);
                word.pop_back();
            }

        };
        vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
            vector<string> res;
            int n = board.size();
            if (n == 0) return res;
            int m = board[0].size();

            vector<trie*> tries(26, NULL);
            for (const string& word: words) {
                if (word.size() == 0) continue;
                if (tries[word[0]-'a'] == NULL)
                    tries[word[0]-'a'] = new trie(word[0]);
                tries[word[0]-'a']->insert(word,1);
            }

            /* print tries */
            bool printTries = false;
            for (int i=0; i<26 && printTries; i++) {
                if (tries[i] != NULL) {
                    string word;
                    tries[i]->print(word);
                }
            }


            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) {
                    char c = board[i][j];
                    if (tries[c-'a'] != NULL) {
                        string word;
                        tries[c-'a']->check(board, res, word, i, j);
                    }
                }
            }
            return res;
        }
};
