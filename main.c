/*
============================================================
                    CMD_Winter Mini Ptj
    1. 담당 팀 : Starter Season_Winter_Team_A, B
    2. ptj 목적 : 오목
    3. 해당 기능 ▼
        01. 게임 규칙 보여주기
        02. 바둑판 표시하기
        03. 화살표 키에 따라 바둑돌의 위치가 변경되게 하고 스페이스바를 이용해 바둑돌 놓기
        04. 오목의 승패를 구분할 수 있기
============================================================
*/



// Import Header file
# include "omok.h"

// Main Function
void printMenu() {
    printf("☆★☆★☆★CMD Winter Mini project★☆★☆★☆\n");
    printf("===================  Team B  ===================\n");
    printf("1. 규칙\n");
    printf("2. 시작\n");
    printf("3. 종료\n");
    printf("===================  Team B  ===================\n");
    printf("숫자 입력 : ");
}
int main() {

    int game = 1;
    char input = '0';
    while (game == 1) {

        printMenu();

        scanf_s("%c", &input);
        getchar();
        switch (input) {
            case '1':
                system("cls");
                printf("============== CMD W M P Team B  ==============\n\n");
                printf("- spacebar를 누르면 돌을 놓을 수 있습니다..\n");
                printf("- 검은돌 먼저 돌을 놓기 시작합니다.\n");
                printf("- 가로, 세로, 대각선 방향으로 같은색 돌이 5개가 이어질 경우 승리하게 됩니다.\n\n");
                break;

            case '2':
                system("cls");
                game_control();
                break;

            case '3':
                game = 0;
                break;

        }

    }

    return 0;
}