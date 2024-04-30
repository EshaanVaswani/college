#include<bits/stdc++.h>
using namespace std;

string LCS(string& s1, string& s2){
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m+1,vector<int>(n+1));

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    string lcs;
    int i=m,j=n;
    while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            lcs += s1[i-1];
            i--;
            j--;
        } else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());

    return lcs;
}

int main(){
    string s1 = "ABCBDAB";
    string s2 = "BDCAB";

    string lcs = LCS(s1,s2);

    cout << "LCS: " << lcs << "\nLength = " << lcs.length() << endl;

    return 0;
}
