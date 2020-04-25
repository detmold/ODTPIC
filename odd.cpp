// Example program
using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#define SIZE 10e5
#define BSIZE 4005

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    long long n,m,q,rand_a,rand_b;
    cin>>n>>m>>q;
    vector<bitset<BSIZE>> a(SIZE);
    vector<bitset<BSIZE>> b(SIZE);
    long long rand_edges[4];
    
    for (long long i = 1; i <= n; i++) {
        cin >> rand_a;
       
        if (a[i-1].test(rand_a)) {  // check if rand_a[i] bit is set in a[i] cell
            a[i] |= a[i-1];
            a[i].set(rand_a,0);
        } else {  // if not set this bit with OR from the previous element
            a[i] |= a[i-1];
            a[i].set(rand_a,1);
        }
        
    }
    
    
    
    for (long long j = 1; j <= m; j++) {
        cin >> rand_b;
        
        if (b[j-1].test(rand_b)) {  // check if rand_b[j] bit is set in b[j] cell
            b[j] |= b[j-1];
            b[j].set(rand_b,0);
        } else {  // if not set this bit with OR from the previous element
            b[j] |= b[j-1];
            b[j].set(rand_b,1);
        } 
    }
    

    while (q--) {
        bitset<BSIZE> ans;
        bitset<BSIZE> ans1;
        bitset<BSIZE> ans2;
        for (int k=0; k<4; k++) {
           cin >> rand_edges[k];
        }
		
		// need to assign not the value of XOR operation but the value of bitset after XOR operation
        ans1 |= (a[ rand_edges[0]-1 ] ^ a[ rand_edges[1] ]);
        ans2 |= (b[ rand_edges[2]-1 ] ^ b[ rand_edges[3] ]);
        ans |= (ans1^ans2);
        
       
        // if (rand_edges[0] == 1) {
        //     ans1 = a[n-1];
        // } else {
        //   ans1 = (a[ rand_edges[0]-1 ] ^ a[ rand_edges[1] ]);
        // }
        // if (rand_edges[2] == 1) {
        //     ans2 = b[m-1];
        // } else {
        //     ans2 = (b[ rand_edges[2]-1 ] ^ b[ rand_edges[3] ]);
        // }
        // ans = (ans1 ^ ans2).count();
        
        
        cout << ans.count() << endl;
    }
    
    return 0;
}
