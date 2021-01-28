# include "omok.h"

int status = BLACK;
int block[20][20] = { 0, };

void game_control(void) {
    // 전체적인 게임의 흐름을 제어하는 함수
    int x = 9, y = 9;   // x,y 좌표 값
    show_map();

    while (1)
    {
        move_position(x, y);
        int stone = Finish(block);
        gotoxy(1, 23);

        if (stone == 0)
        {
            gotoxy(1, 24);
            printf("검은돌이 이겼습니다.\n");
            break;
        }
        else if (stone == 1)
        {
            gotoxy(1, 24);
            printf("흰돌이 이겼습니다.\n");
            break;
        }
    };
};

void gotoxy(int x, int y) {
    // 화면상의 커서 위치를 파악하고 제어하는 함수
    COORD pos = { x * 2 ,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
};

void show_stone(int x, int y) {
    // 바둑돌을 보여주는 함수
    if (block[y][x] == 0) {                        // 2차원 배열에 돌이 없을 때
        if (status == WHITE) {                     // status = 바둑돌 색 놓는 순서(status -> 전역 변수)
            printf("●");                        // 흰돌차례면 흰돌 놓기
            block[y][x] = WHITE;                  // 2차원 배열에 흰돌 표시 (block 배열 -> 전역 변수)
            status = BLACK;                        // 다음 차례 흑돌 차례 변경
        }
        else if (status == BLACK) {
            //흑돌
            printf("○");
            block[y][x] = BLACK;
            status = WHITE;
        }
    }
}

void move_position(int x, int y) {
    // 사용자가 입력하는 화살표 키에 따라 좌표 x, y값을 변경하는 함수
    char loc;      // 키 입력 값

    while (1)
    {
        gotoxy(x, y);
        if (_kbhit())
        {
            loc = _getch();

            switch (loc)
            {
            case 72:         //↑   = 아스키 코드
                y--;
                break;
            case 75:         // ←  = 아스키 코드
                x--;
                break;
            case 77:         // →  = 아스키 코드
                x++;
                break;
            case 80:         //↓   = 아스키 코드
                y++;
                break;
            case 32: // Space Bar = 아스키 코드
                show_stone(x, y);
                goto RE;
            case 8:
                return;
            default:
                break;
            }
        }
    }
    RE:
    return;
};

void show_map() {
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

int Finish(int block[20][20])
{
    int count = 0;

    for (int x = 1; x < 20; x++) {              //가로검사
        for (int y = 1; y < 20; y++) {
            if (block[x][y] == BLACK)
                count++;
            else
                count = 0;

            if (count == 5) {
                return 0;
            }
        }
    }
    for (int x = 1; x < 20; x++) {              
        for (int y = 1; y < 20; y++) {
            if (block[x][y] == WHITE)
                count++;
            else
                count = 0;

            if (count == 5) {
                return 1;
            }
        }
    }
    for (int y = 1; y < 20; y++) {              //세로검사
        for (int x = 1; x < 20; x++) {
            if (block[x][y] == BLACK)
                count++;
            else
                count = 0;

            if (count == 5) {
                return 0;
            }
        }
    }
    for (int y = 1; y < 20; y++) {
        for (int x = 1; x < 20; x++) {
            if (block[x][y] == WHITE)
                count++;
            else
                count = 0;

            if (count == 5) {
                return 1;
            }
        }
    }
    for (int x = 1; x < 16; x++)
    {
        for (int y = 1; y < 16; y++)
        {
            int arr1 = x;
            int arr2 = y;

            for (int i = 0; i < 5; i++)
            {
                if (block[arr1++][arr2++] == BLACK) {
                    count++;
                }
                else
                    count = 0;
            }
            if (count == 5)
                return 0;
        }
    }

    for (int x = 1; x < 16; x++)
    {
        for (int y = 1; y < 16; y++)
        {
            int arr1 = x;
            int arr2 = y;

            for (int i = 0; i < 5; i++)
            {
                if (block[arr1++][arr2++] == WHITE) {
                    count++;
                }
                else
                    count = 0;
            }
            if (count == 5)
                return 1;
        }
    }

    for (int x = 1; x < 16; x++)
    {
        for (int y = 1; y < 16; y++)
        {
            int arr1 = x;
            int arr2 = y;

            for (int i = 0; i < 5; i++)
            {
                if (block[arr1++][arr2--] == BLACK) {
                    count++;
                }
                else
                    count = 0;
            }
            if (count == 5)
                return 0;
        }
    }

    for (int x = 1; x < 16; x++)
    {
        for (int y = 1; y < 16; y++)
        {
            int arr1 = x;
            int arr2 = y;

            for (int i = 0; i < 5; i++)
            {
                if (block[arr1++][arr2--] == WHITE) {
                    count++;
                }
                else
                    count = 0;
            }
            if (count == 5)
                return 1;
        }
    }
    return 3;
}