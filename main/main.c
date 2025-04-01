#include <stdio.h>

int main() {
    int me = 10;
    char input;

    while (1) {
        system("cls");//없으면 화면 내려감(화면 초기화)
        for (int i = 0; i < 20; i++) {
            if (i == me) {
                printf("0");//내 위치
            }
            else {
                printf("_");//아닌 부분 _로 채우기
            }
        }
        puts("\n");

        input = _getch();  // A 또는 D 입력 받기
        if (input == 'A' || input == 'a'){// A 또는 a 키가 입력되면 오른쪽으로 이동
            if (me > 0) {
                me--;  // 0을 왼쪽으로 한 칸 이동
            }
        }
        else if (input == 'D' || input == 'd') {// D 또는 d 키가 입력되면 오른쪽으로 이동
            if (me < 19) {  // 화면의 크기가 20이라서 최대값은 19(인덱스 때문에 0부터 시작)
                me++;  // 0을 오른쪽으로 한 칸 이동
            }
            }
        else {//다른 키를 입력하면 0이 처음 시작(가운데)으로 이동해 처음부터 실행
            me = 10;//10인 이유는 가운데가 10이기 때문(=0으로 시작하면 맨앞에서 시작)
        }
        }
    return 0;
    }