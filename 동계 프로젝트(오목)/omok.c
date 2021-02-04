# include "omok.h"

int status = BLACK;
int block[20][20] = { 0, };

void game_control(void) {
    // ��ü���� ������ �帧�� �����ϴ� �Լ�
    int x = 9, y = 9;   // x,y ��ǥ ��
    show_map();

    while (1)
    {
        move_position(x, y);
        int stone = Finish(block);
        gotoxy(1, 23);

        if (stone == 0)
        {
            gotoxy(1, 24);
            printf("�������� �̰���ϴ�.\n");
            break;
        }
        else if (stone == 1)
        {
            gotoxy(1, 24);
            printf("���� �̰���ϴ�.\n");
            break;
        }
    };
};

void gotoxy(int x, int y) {
    // ȭ����� Ŀ�� ��ġ�� �ľ��ϰ� �����ϴ� �Լ�
    COORD pos = { x * 2 ,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
};

void show_stone(int x, int y) {
    // �ٵϵ��� �����ִ� �Լ�
    if (block[y][x] == 0) {                        // 2���� �迭�� ���� ���� ��
        if (status == WHITE) {                     // status = �ٵϵ� �� ���� ����(status -> ���� ����)
            printf("��");                        // �����ʸ� �� ����
            block[y][x] = WHITE;                  // 2���� �迭�� �� ǥ�� (block �迭 -> ���� ����)
            status = BLACK;                        // ���� ���� �浹 ���� ����
        }
        else if (status == BLACK) {
            //�浹
            printf("��");
            block[y][x] = BLACK;
            status = WHITE;
        }
    }
}

void move_position(int x, int y) {
    // ����ڰ� �Է��ϴ� ȭ��ǥ Ű�� ���� ��ǥ x, y���� �����ϴ� �Լ�
    char loc;      // Ű �Է� ��

    while (1)
    {
        gotoxy(x, y);
        if (_kbhit())
        {
            loc = _getch();

            switch (loc)
            {
            case 72:         //��   = �ƽ�Ű �ڵ�
                y--;
                break;
            case 75:         // ��  = �ƽ�Ű �ڵ�
                x--;
                break;
            case 77:         // ��  = �ƽ�Ű �ڵ�
                x++;
                break;
            case 80:         //��   = �ƽ�Ű �ڵ�
                y++;
                break;
            case 32: // Space Bar = �ƽ�Ű �ڵ�
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
    //�ٵ����� �����ִ� �Լ�
    int Row;
    int Col;

    for (Row = 0; Row < 20; Row++) {
        for (Col = 0; Col < 20; Col++) {
            if (Row == 0 && Col == 0)
                printf("�� ");
            else if (Col == 19 && Row == 0)
                printf("�� ");
            else if (Col == 0 && Row == 19)
                printf("�� ");
            else if (Col == 19 && Row == 19)
                printf("�� ");
            else if (Col == 0)
                printf("�� ");
            else if (Col == 19)
                printf("�� ");
            else if (Row == 0)
                printf("�� ");
            else if (Row == 19)
                printf("�� ");
            else
                printf("�� ");
        }
        printf("\n");
    }
};

int Finish(int block[20][20])
{
    int count = 0;

    for (int x = 0; x < 20; x++) {              //���ΰ˻�
        for (int y = 0; y < 20; y++) {
            if (block[x][y] == BLACK)
                count++;
            else
                count = 0;

            if (count == 5) {
                return 0;
            }
        }
    }
    for (int x = 0; x < 20; x++) {              
        for (int y = 0; y < 20; y++) {
            if (block[x][y] == WHITE)
                count++;
            else
                count = 0;

            if (count == 5) {
                return 1;
            }
        }
    }
    for (int y = 0; y < 20; y++) {              //���ΰ˻�
        for (int x = 0; x < 20; x++) {
            if (block[x][y] == BLACK)
                count++;
            else
                count = 0;

            if (count == 5) {
                return 0;
            }
        }
    }
    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 20; x++) {
            if (block[x][y] == WHITE)
                count++;
            else
                count = 0;

            if (count == 5) {
                return 1;
            }
        }
    }
    for (int x = 0; x < 20; x++)
    {
        for (int y = 0; y < 20; y++)
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

    for (int x = 0; x <20; x++)
    {
        for (int y = 0; y <20; y++)
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

    for (int x = 0; x <20; x++)
    {
        for (int y = 0; y <= 20; y++)
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

    for (int x = 0; x <20; x++)
    {
        for (int y = 0; y <= 20; y++)
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