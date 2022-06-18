#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int u_int;

int n, m;

int count(int **matrix, int i, int j, int **dp){
	if( (i == n && j == m-1) || (i == n-1 && j == m) )
		return 0;	
	else if(i == n || j == m)
		return -2;
	
	if(dp[i][j] != -10)
		return dp[i][j];
		
	int a = count(matrix, i+1, j, dp);
	int b = count(matrix, i, j+1, dp);
	
	int x = n-i;
	int y = m-j;
	
	if(matrix[i][j] == 1){
		a += 1;
		b += 1;
	}
	
	
	int& ret = dp[i][j];
	if(a == (x+y-1)/2 || ((x+y)%2 == 0 && a == (x+y-1)/2+1)){
		ret = a;
	}else if(b == (x+y-1)/2 || ((x+y)%2 == 0 && b == (x+y-1)/2+1))
		ret = b;
	else 
		ret = -2;
		
	return ret;
}

void solve(){
	cin>>n>>m;
	
	int **matrix = new int*[n];
	int **dp = new int*[n];
	
	for(int i = 0; i < n; i++){
		matrix[i] = new int[m];
		dp[i] = new int[m];
		for(int j = 0; j < m; j++){
			cin>>matrix[i][j];
			dp[i][j] = -10;
		}
	}
	
	if((n+m)%2 == 0)
		cout<<"NO\n";
	else{
		cout<<(count(matrix, 0, 0, dp) == (n+m-1)/2 ? "YES\n" : "NO\n");
	}
	
	delete [] matrix;
	delete [] dp;
}

int main(){
	
	freopen("input.txt", "r", stdin);
	
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	
	return 0;
}
