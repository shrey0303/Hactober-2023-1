// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum possible cost
int minCost(int arr[], int N)
{
	// Creating the prefix sum array
	int pref[N + 1], dp[N][N], opt[N][N];
	pref[0] = 0;
	memset(dp, 0, sizeof(dp));
	memset(dp, 0, sizeof(dp));

	// Loop to calculate the prefix sum
	for (int i = 0; i < N; i++) {
		pref[i + 1] = pref[i] + arr[i];
		opt[i][i] = i;
	}

	// Iterating through all sub-arrays
	// of length 2 or greater
	for (int i = N - 2; i >= 0; i--) {
		for (int j = i + 1; j < N; j++) {

			// Cost function = sum of
			// all elements in the sub-array
			int cost = pref[j + 1] - pref[i];
			int mn = INT_MAX;
			for (int k = opt[i][j - 1];
				k <= min(j - 1, opt[i + 1][j]); 
				k++) {
				if (mn >= dp[i][k] 
					+ dp[k + 1][j] + cost) {

					// Updating opt table
					opt[i][j] = k;

					// Updating minimum cost
					mn = dp[i][k] 
						+ dp[k + 1][j] + cost;
				}
			}

			// dp transition
			dp[i][j] = mn;
		}
	}
	return dp[0][N - 1];
}

// Driver code
int main()
{
	int arr[] = { 3, 4, 2, 1, 7 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << minCost(arr, N);
	return 0;
}
