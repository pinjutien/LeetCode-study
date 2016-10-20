// Given a matrix of dimensions mxn having all entries as 1 or 0, 
// find out the size of maximum size square sub-matrix with all 1s. 
#include <iostream>
using std::min;

void printMaxSubSquare(bool M[R][C]) {
	bool S[R][C];
	
	// copy first column and first row of M to S
	for (int i = 0; i < R; i++) {
		S[i][0] = M[i][0];
	}
	
	for (int j = 0; j < C; j++) {
		S[0][j] = M[0][j];
	}
	
	for (int i = 1; i < R; i++) {
		for (int j = 1; j < C; j++) {
			
			if (M[i][j] == 1) {
				S[i][j] = min(S[i-1][j], S[i][j-1], S[i-1][j-1]) + 1;
			}
			else {
				S[i][j] = 0;
			}
		}
	}
}




int main()
{
	bool M[R][C] =  {{0, 1, 1, 0, 1}, 
		{1, 1, 0, 1, 0}, 
		{0, 1, 1, 1, 0},
		{1, 1, 1, 1, 0},
		{1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0}};
	printMaxSubSquare(M);
	getchar();  
}