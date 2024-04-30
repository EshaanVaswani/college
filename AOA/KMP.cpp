#include<bits/stdc++.h>
using namespace std;

vector<int> computeLPSArray(const string& pattern) {
    int length = pattern.length();
    vector<int> lps(length, 0);
    int len = 0;
    int i = 1;

    while (i < length) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void KMPsearch(const string& text, const string& pattern) {
    int N = text.length();
    int M = pattern.length();
    vector<int> lps = computeLPSArray(pattern);

    int i = 0;  // index for text
    int j = 0;  // index for pattern
    while (i < N) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == M) {
            cout << "Found pattern at index " << i - j << endl;
            j = lps[j - 1];
        }

        else if (i < N && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

int main() {
    string text = "ABCDFABABCDE";
    string pattern = "ABCD";
    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;

    KMPsearch(text, pattern);

    return 0;
}
