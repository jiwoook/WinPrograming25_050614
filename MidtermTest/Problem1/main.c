#include <stdio.h>

// PassOrFail �Լ� ����
int PassOrFail(int score) {
    if (score >= 50) {
        return 1;
    }
    else {
        return 0; // Fail
    }
}

int main() {

    int myScore = 51;

    int result = PassOrFail(myScore);

    if (result == 1) {
        printf("����� �����ϴ�!\n");
    }
    else {
        printf("�츮�� ���ߴ١�  ������̴١�\n");
    }

    return 0;
}