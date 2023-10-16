#include <bits/stdc++.h> 
using namespace std;
#define SPEED ios_base::sync_with_stdio(0);

int main() {
    SPEED; 
    int n, m, k, res;
    cin>>n>>m>>k;
    for(int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            res = (i+1 * j+1);
            k--;
            if (k==0){
                cout<<res;
                break;
            }
        }
    }
    return 0;
}
