#include <readline/readline.h>
#include <readline/history.h>
#include <bits/stdc++.h>
using namespace std;

// Danh sách lệnh có sẵn
vector<string> commands = {
    "ls", "ll", "cd", "cat", "cp", "mv",
    "mkdir", "rm", "rmdir", "touch", "kubectl"
};

// Hàm tính Levenshtein distance
int levenshteinDistance(const string &s1, const string &s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            dp[i][j] = min({dp[i - 1][j] + 1,
                            dp[i][j - 1] + 1,
                            dp[i - 1][j - 1] + cost});
        }
    }
    return dp[n][m];
}

// Similarity
double similarity(const string &s1, const string &s2) {
    int dist = levenshteinDistance(s1, s2);
    int maxLen = max(s1.size(), s2.size());
    if (maxLen == 0) return 1.0;
    return 1.0 - (double)dist / maxLen;
}

// Hàm gợi ý lệnh khi bấm Tab
char* commandGenerator(const char* text, int state) {
    static vector<string> matches;
    static size_t index;

    if (state == 0) {
        matches.clear();
        index = 0;

        string input(text);

        // Fuzzy match
        vector<pair<string, double>> scores;
        for (auto &cmd : commands) {
            double sim = similarity(input, cmd);
            if (sim > 0.3) { // chỉ lấy những cái tương đối giống
                scores.push_back({cmd, sim});
            }
        }
        sort(scores.begin(), scores.end(),
             [](auto &a, auto &b) { return a.second > b.second; });

        for (auto &p : scores) matches.push_back(p.first);
    }

    if (index < matches.size()) {
        return strdup(matches[index++].c_str());
    }
    return nullptr;
}

// Gán hàm gợi ý vào Readline
char** commandCompleter(const char* text, int start, int end) {
    rl_attempted_completion_over = 1;
    return rl_completion_matches(text, commandGenerator);
}

int main() {
    rl_attempted_completion_function = commandCompleter;

    char* input;
    while ((input = readline(">>> ")) != nullptr) {
        string cmd(input);
        free(input);

        if (cmd == "exit") break;
        if (!cmd.empty()) add_history(cmd.c_str());

        cout << "Bạn đã nhập: " << cmd << endl;
    }

    return 0;
}
