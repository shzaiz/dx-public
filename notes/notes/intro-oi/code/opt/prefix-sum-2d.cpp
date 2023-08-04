// C++ Program to find prefix sum of 2d array
#include <iostream>
using namespace std;

#define R 6
#define C 6

void prefixSum2D(int a[][C]){
	int s[R][C];
	s[0][0] = a[0][0];

	for (int i = 1; i < C; i++)
		s[0][i] = s[0][i - 1] + a[0][i];
	for (int i = 1; i < R; i++)
		s[i][0] = s[i - 1][0] + a[i][0];

	for (int i = 1; i < R; i++) {
		for (int j = 1; j < C; j++)

			s[i][j] = s[i - 1][j] + s[i][j - 1]
						- s[i - 1][j - 1] + a[i][j];
	}
	
}
