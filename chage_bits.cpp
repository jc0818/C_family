#include <stdio.h>

// �ð������� �ϴ� �ִ��� �ø�. 
void print_Ejinsu(unsigned char value) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
    }
}

unsigned char is_bit_set(unsigned char value, int position) {
    return (value & (1 << position)) != 0;
}

// Ư�� ��ġ�� ��Ʈ�� 1�� �����ϴ� �Լ�
unsigned char set_bit(unsigned char value, int position) {
    return value | (1 << position);
}

// Ư�� ��ġ�� ��Ʈ�� 0���� �����ϴ� �Լ�
unsigned char clear_bit(unsigned char value, int position) {
    return value & ~(1 << position);
}

int main() {
    unsigned char value = 0b00001000; // �ʱ� ��: 3��° ��Ʈ�� 1
    unsigned int position;

    // ���� �� ����� ����Ͽ�  
    printf("�ʱ� ��: %d (0b", value);
    print_Ejinsu(value);
    printf(")\n");

    // ��Ʈ�� �� ��ġ �Է�
    printf("���� ���� ��Ʈ ��ġ�� �Է�(0~7)_ ���� 3��°�� 1 ��, : ");
    scanf("%d", &position);

    // �Է��� ��ġ�� ��Ʈ�� ����
    value = clear_bit(value, position);
    printf("��Ʈ �� �� ��: %d (0b", value);
    print_Ejinsu(value);
    printf(")\n");

    // �ش� ��Ʈ�� �������� Ȯ��
    if (is_bit_set(value, 3)) {
        printf("3��° ��Ʈ�� ���� �������� .\n");
    } else {
        printf("3��° ��Ʈ�� ���� .\n");
    }

    // 2��° ��Ʈ�� �ѱ�
    value = set_bit(value, 2);
    printf("2��° ��Ʈ�� ���� �� �� ��: %d (0b", value);
    
    print_Ejinsu(value);
    printf(")\n");

    return 0;
}

