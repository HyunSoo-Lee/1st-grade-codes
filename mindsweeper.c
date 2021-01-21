#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <windows.h>
#define MAX_MINE_COUNT 10
#define SIZE 9

int neighborhood_count(int, int); //주변 지뢰 수 
int click(int, int); //열림 함수
int UI(); //최종 인터페이스, 블록 모양
int lose(); //패배 조건
int win(); //승리 조건

struct cell {
	int mine; // 지뢰 존재 유무 1 or 0
	int count; // 주위 지뢰 개수 0 ~ 9
	int open; // clicked(1), unclick(0)
	int ui; 
	//네모블럭 전 숫자 ui: 클릭된 cell은 0, 오픈 안된 cell은 9, 지뢰 위치가 눌렸을때는 10, 나머지는 count 숫자 그대로
};

struct cell arr_cl[SIZE][SIZE] = { 0 };
int main(void) {
	srand(time(NULL));
	int count = 0;
	while (count < MAX_MINE_COUNT) {
		int x = rand() % SIZE;
		int y = rand() % SIZE;
		if (arr_cl[x][y].mine != 1) {
			arr_cl[x][y].mine = 1;
			count++;
		}//랜덤한 위치에 지뢰 심어둠
	}

	for (int x = 0; x < SIZE; x++) {
		for (int y = 0; y < SIZE; y++) {
			arr_cl[x][y].ui = 9;
			if (arr_cl[x][y].mine == 0) {
				arr_cl[x][y].count = neighborhood_count(x, y); // 0,0부터 8,8까지
			}
		}
	}//인근에 지뢰가 있는경우 count 속성에 갯수만큼 넣어주기, 숫자 ui 9로 통일해주기

	//printf("Mine|Count : Answer\n");
	//for (int x = 0; x < SIZE; x++) {
	//	for (int y = 0; y < SIZE; y++) {
	//		printf("%d|%d  ", arr_cl[x][y].mine, arr_cl[x][y].count);
	//	}
	//	printf("\n");
	//}//답지 프린트

	while (1) {
		system("cls");
		UI();//인터페이스 프린트

		printf("\n");
		int a, b = 0;
		printf("행 : ");
		scanf("%d", &a);
		printf("열 : ");
		scanf("%d", &b);
		click(a - 1, b - 1); //사용자로부터 행, 열 입력받기

		if (lose() == 1) {
			system("cls");
			UI();
			printf("\n!!!! You lose !!!!\n");
			break;
		}//패배
		if (win() == 1) {
			system("cls");
			UI();
			printf("\n!!!! You win !!!!\n");
			break;
		}//승리
	}	
	return 0;
}

int neighborhood_count(int x, int y) {
	int count = 0;
	for (int i = x - 1; i < x + 2; i++) {
		for (int j = y - 1; j < y + 2; j++) {
			if(i >= 0 && j >= 0 && i < SIZE && j < SIZE) {
				if (arr_cl[i][j].mine == 1)
					count++;
			}
		}
	}
	return count; //주위 8개 칸에 지뢰가 있는지 확인한 후 있으면 count++
}

int click(int a, int b) {
	if (arr_cl[a][b].count == 0 && arr_cl[a][b].mine == 0) {
		arr_cl[a][b].ui = 0;
		arr_cl[a][b].open = 1; // 선택된 cell 주변에 지뢰 없으면 open 올리고, 띄워지는 블록은 공백
		for (int i = a - 1; i <= a + 1; i++) {
			for (int j = b - 1; j <= b + 1; j++) {
				if (i >= 0 && j >= 0 && i < SIZE && j < SIZE) {
					if (arr_cl[i][j].count == 0 && arr_cl[i][j].open == 0 && arr_cl[i][j].mine == 0) {
						click(i, j); // 선택된 cell 주변의 cell'이 count 0인 경우, 그 cell'에 대한 click 함수 다시 호출
					}
					if (arr_cl[i][j].count != 0) {
						arr_cl[i][j].ui = arr_cl[i][j].count;
						arr_cl[i][j].open = 1;
					}
				}
			}
		}
	}
	else if (arr_cl[a][b].count != 0 && arr_cl[a][b].mine == 0) {
		arr_cl[a][b].ui = arr_cl[a][b].count;
		arr_cl[a][b].open = 1;
	}
	else if (arr_cl[a][b].count == 0 && arr_cl[a][b].mine == 1) {
		for (int x = 0; x < SIZE; x++) {
			for (int y = 0; y < SIZE; y++) {
				if (arr_cl[x][y].mine == 1) {
					arr_cl[x][y].ui = 10;
				}
			}
		}
		arr_cl[a][b].open = 1;
	}
return 0;
}

int UI() {
	printf("  ");
	for (int a = 1; a <= SIZE; a++) {
		printf("%d  ", a);
	}
	printf("\n");
	for (int x = 0; x < SIZE; x++) {
		printf("%d ", x + 1);
		for (int y = 0; y < SIZE; y++) {
			if (arr_cl[x][y].ui == 0 && arr_cl[x][y].mine == 0) {
				printf("   ");
			}
			if (arr_cl[x][y].ui > 0 && arr_cl[x][y].ui < 9) {
				printf("%d  ",arr_cl[x][y].ui);
			}
			if (arr_cl[x][y].ui == 9) {
				printf("■ ");
			}
			if (arr_cl[x][y].ui == 10) {
				printf("※ ");
			}
		}
		printf("%d ", x + 1);
		printf("\n");
	}
	printf("  ");
	for (int b = 1; b <= SIZE; b++) {
		printf("%d  ", b);
	}
	printf("\n");
	return 0;
}

int lose() {
	for (int x = 0; x < SIZE; x++) {
		for (int y = 0; y < SIZE; y++) {
			if (arr_cl[x][y].mine == 1 && arr_cl[x][y].open == 1) {
				return 1;
			}
		}
	}
	return 0;
}

int win() {
	int count = 0;
	for (int x = 0; x < SIZE; x++) {
		for (int y = 0; y < SIZE; y++) {
			if (arr_cl[x][y].open == 1) {
				count++;
			}
		}
	}
	if (SIZE * SIZE - MAX_MINE_COUNT == count) {
		return 1;
	}
	return 0;
}
