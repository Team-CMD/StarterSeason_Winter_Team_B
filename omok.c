# include "omok.h"

void game_control(void){
    // 전체적인 게임의 흐름을 제어하는 함수
    show_map();
};

void gotoxy(){
    // 화면상의 커서 위치를 파악하고 제어하는 함수
};

void show_stone(){
    // 바둑돌을 보여주는 함수
};

void move_position(){
    // 사용자가 입력하는 화살표 키에 따라 좌표 x, y값을 변경하는 함수
};

void show_map(){
    //바둑판을 보여주는 함수
    int Row;
	int Col;

	for (Row = 0; Row < 20; Row++) {
		for (Col = 0; Col < 20; Col++) {
			if (Row == 0 && Col == 0)
				printf("┌ ");
			else if (Col == 19 && Row == 0)
				printf("┐ ");
			else if (Col == 0 && Row == 19)
				printf("└ ");
			else if (Col == 19 && Row == 19)
				printf("┘ ");
			else if (Col == 0)
				printf("├ ");
			else if (Col == 19)
				printf("┤ ");
			else if (Row == 0)
				printf("┬ ");
			else if (Row == 19)
				printf("┴ ");
			else
				printf("┼ ");
		}
		printf("\n");
	}
};