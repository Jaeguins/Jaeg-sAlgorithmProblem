#include <stdio.h>
int field[100][100];
int N;
int main() {
	FILE *file;
	fopen_s(&file, "input.txt", "r");
	int tmp;
	fscanf_s(file, "%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			fscanf_s(file, "%d", &field[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", field[i][j]);
		}
		printf("\n");
	}


	getchar();
	getchar();
}