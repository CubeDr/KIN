//
// Created by HyunI on 2019-10-10.
//
#include <stdio.h>

// 판의 가로, 세로 길이
#define L 3

// 판을 공백으로 초기화
void initBoard(char board[L][L]) {
    for(int y=0; y<L; y++)
        for(int x=0; x<L; x++)
            board[y][x] = ' ';
}

// 판을 격자와 함께 출력
void printBoard(const char board[L][L]) {
    // 가로 줄 번호
    printf("  ");
    for(int x=0; x<L; x++)
        printf("%d ", x+1);
    printf("\n");

    for(int y=0; y<L; y++) {
        // 세로 줄 번호와 플레이어 말 출력
        printf("%d ", y+1);
        for(int x=0; x<L; x++) {
            printf("%c", board[y][x]);
            if(x != L-1) printf("|");
        }
        printf("\n");

        // 세로 격자 줄 출력
        if(y != L-1) {
            printf("  ");
            for(int x=0; x<L; x++) {
                printf("-");
                if(x != L-1) printf("+");
            }
            printf("\n");
        }
    }
}

// 판 범위 밖으로 나가는지 검사
int isInRange(int x, int y) {
    return x >= 0 && x < L && y >= 0 && y < L;
}

// 판의 해당 칸에 새로운 말을 놓을 수 있는지 검사
int isValid(const char board[L][L], int x, int y) {
    return isInRange(x, y) && board[y][x] == ' ';
}

// 전달받은 플레이어에게서 말을 놓을 위치를 입력받음
// 1: 입력 성공
// 2: 잘못된 입력
int playerInput(const char *name, const char board[L][L], int *x, int *y) {
    printf("%s 차례\n", name);
    printf("줄, 칸 수 입력: ");

    scanf("%d %d", y, x);
    (*x)--;
    (*y)--;
    if(!isValid(board, *x, *y)) return 0;
    return 1;
}

// 가로, 세로, 우하 대각선, 우상 대각선 방향에 대한 x, y 변화량
int dx[] = {-1, 1, 0, 0, -1, 1, 1, -1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
// 해당 칸이 승리한 줄에 속해있는지 검사하는 함수
int isWinner(const char board[L][L], int x, int y) {
    // 모든 방향 검사
    for(int d=0; d<4; d++) {
        // 같은 말의 개수를 셈
        int count = 1;
        for(int b=0; b<2; b++) {
            int index = 2*d + b;

            int cx = x + dx[index];
            int cy = y + dy[index];
            while(isInRange(cx, cy)) {
                if(board[cy][cx] == board[y][x])
                    count++;
                cx += dx[index];
                cy += dy[index];
            }
        }
        // 말의 개수가 한 줄을 모두 채웠으면 승리
        if(count == L)
            return 1;
    }
    return 0;
}

// 실제 게임 로직
void play(char board[L][L], const char* playerNames[], const char marks[]) {
    // 몇번째 라운드인지를 저장하는 함수
    int round = 0;
    // 누구의 차례인지를 저장하는 함수
    int turn = 0;
    // 말을 놓을 위치
    int x, y;

    // 게임이 끝날 때까지 반복
    while(1) {
        printf("\n\n%d번째 턴\n", turn + 1);
        printBoard(board);

        if(!playerInput(playerNames[turn], board, &x, &y))
            continue;

        board[y][x] = marks[turn];
        round++;

        if(isWinner(board, x, y)) {
            printf("%s 승리!\n", playerNames[turn]);
            break;
        } else if(round == L * L) {
            printf("무승부!\n");
            break;
        }
        turn = !turn;
    }
}

int main() {
    char board[L][L];
    initBoard(board);

    // 플레이어 이름
    const char* names[] = {
            "Player 1", "Player 2"
    };
    // 플레이어 말
    const char marks[] = {'O', 'X'};

    play(board, names, marks);

    return 0;
}