#include <Windows.h>
#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char choice;
	char input;//�Է¹��� ����

	while (1) {
		puts("********************");
		puts("*    �ϴ� ����     *");
		puts("********************");
		puts("");
		puts("1. ���ӽ���");
		puts("2. ��������");
		puts("");

		choice = _getch();//�Է¹ޱ�

		if (choice == '1') {
			puts("���� ����!");
			break;
		}
		else if (choice == '2') {
			puts("���� ����!");

			//������� ����
			puts("�ٽ� �Ͻðڽ��ϱ�?");
			puts("1. �ٽ� ����");
			puts("2. �ٷ� ����");

			//a
			input = _getch();
			if (input == '1') {
				puts("");
				puts("�ٽ� ����");
				puts("");
				continue;
			}
			else if (input == '2') {
				puts("�ٷ� ����");
				break;
			}
			else {
				puts("�߸��� �Է��Դϴ�. 1 �Ǵ� 2�� �Է����ּ���.\n");
				continue;//������ �κ� continue�� ó������ ���ư�(//a�κк��� �ݺ��ϰ� ������ ��ɾ� �ʿ�)
			}
			//������� ����

		}
		else {
			puts("�߸��� �Է��Դϴ�. 1 �Ǵ� 2�� �Է����ּ���.\n");
			continue;
		}

		return 0;
	}
}