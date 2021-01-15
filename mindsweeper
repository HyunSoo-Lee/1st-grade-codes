#include<stdio.h>
#include<stdlib.h>
#define MAX_MINE_COUNT 10 //지뢰 갯수
#define SIZE 9

struct cell {
	int mine; // 1 or 0
	int count; // 0 ~ 9
	int click; // clicked(1), unclick(0)
};
struct cell arr_cl[9][9] = { 0 };

int main(void) {
	int count = 0;
	while(count <= MAX_MINE_COUNT) {
		int x = rand() % SIZE;
		int y = rand() % SIZE;
		if (arr_cl[x][y].mine != 1) {
			arr_cl[x][y].mine = 1;
			count++;
		}//랜덤한 위치에 지뢰 심어둠
	} 
	for (int x = 0; x < SIZE; x++) {
		for (int y = 0; y < SIZE; y++) {
			if (arr_cl[x][y].mine == 0) {
				arr_cl[x][y].count = get_neighborhood_count(x, y); // 0,0부터 8,8까지
			}
			else
				break; //지뢰가 있다는 뜻
		}
	}
	return 0;
}

int get_neighborhood_count(int x, int y) {
	int count = 0;
	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			if (i < 0 || j < 0 || i > SIZE || j > SIZE) {
				break;
			}
			if (arr_cl[i][j].mine == 1) {
				count++;
			}
		}
	}
	return count; //주위 8개 칸에 지뢰가 있는지 확인한 후 있으면 count 올려줌
}
