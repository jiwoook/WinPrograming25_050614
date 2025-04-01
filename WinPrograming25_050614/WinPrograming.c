#include <Windows.h>
#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char choice;
	char input;//입력받을 변수

	while (1) {
		puts("********************");
		puts("*    일단 게임     *");
		puts("********************");
		puts("");
		puts("1. 게임시작");
		puts("2. 게임종료");
		puts("");

		choice = _getch();//입력받기

		if (choice == '1') {
			puts("게임 시작!");
			break;
		}
		else if (choice == '2') {
			puts("게임 종료!");

			//여기부터 실험
			puts("다시 하시겠습니까?");
			puts("1. 다시 시작");
			puts("2. 바로 종료");

			//a
			input = _getch();
			if (input == '1') {
				puts("");
				puts("다시 시작");
				puts("");
				continue;
			}
			else if (input == '2') {
				puts("바로 종료");
				break;
			}
			else {
				puts("잘못된 입력입니다. 1 또는 2를 입력해주세요.\n");
				continue;//수정할 부분 continue가 처음으로 돌아감(//a부분부터 반복하게 설정할 명령어 필요)
			}
			//여기까지 실험

		}
		else {
			puts("잘못된 입력입니다. 1 또는 2를 입력해주세요.\n");
			continue;
		}

		return 0;
	}
}