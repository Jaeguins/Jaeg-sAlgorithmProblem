#include <stdio.h>
int field[100][100];
int N;
int count, totLvl;
void recursion(int, int, int);
int checkPossible(int, int);

int main() {
	FILE *file;
	fopen_s(&file, "input.txt", "r");
	
	int K;
	fscanf_s(file, "%d", &K);
	for (int k = 0; k < K; k++) {
		count = 0, totLvl = 0;
		fscanf_s(file, "%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				fscanf_s(file, "%d", &field[i][j]);
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if(field[i][j]!=1)
				recursion(i, j, 1);
			}
		}
		printf("%d¸í %d°¡Áö\n", totLvl, count);
	}
	getchar();
	getchar();
}
void recursion(int x, int y, int lvl) {
	field[x][y] = 2;
	if (lvl > totLvl) {
		totLvl = lvl;
		count = 1;
	}
	else if (totLvl == lvl) {
		count += 1;
	}
	int isSkipped = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!isSkipped) {
				i = x;
				j = y;
				isSkipped = 1;
			}
			if (!field[i][j]&&checkPossible(i, j)) {
				recursion(i, j, lvl + 1);
			}
		}
	}
	field[x][y] = 0;
}
int checkPossible(int x, int y) {
	for (int i = x; i < N; i++) {
		if (field[i][y] == 2) {
			return 0;
		}
		else if (field[i][y] == 1) {
			break;
		}
	}
	for (int i = x; i >= 0; i--) {
		if (field[i][y] == 2) {
			return 0;
		}
		else if (field[i][y] == 1) {
			break;
		}
	}
	for (int i = y; i < N; i++) {
		if (field[x][i] == 2) {
			return 0;
		}
		else if (field[x][i] == 1) {
			break;
		}
	}
	for (int i = y; i >=0; i--) {
		if (field[x][i] == 2) {
			return 0;
		}
		else if (field[x][i] == 1) {
			break;
		}
	}
	return 1;
}