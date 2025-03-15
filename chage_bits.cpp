#include <stdio.h>

// 시각적으로 일단 최대한 올림. 
void print_Ejinsu(unsigned char value) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
    }
}

unsigned char is_bit_set(unsigned char value, int position) {
    return (value & (1 << position)) != 0;
}

// 특정 위치의 비트를 1로 설정하는 함수
unsigned char set_bit(unsigned char value, int position) {
    return value | (1 << position);
}

// 특정 위치의 비트를 0으로 설정하는 함수
unsigned char clear_bit(unsigned char value, int position) {
    return value & ~(1 << position);
}

int main() {
    unsigned char value = 0b00001000; // 초기 값: 3번째 비트만 1
    unsigned int position;

    // 현재 값 출력을 출력하여  
    printf("초기 값: %d (0b", value);
    print_Ejinsu(value);
    printf(")\n");

    // 비트를 끌 위치 입력
    printf("끄고 싶은 비트 위치를 입력(0~7)_ 현재 3번째만 1 임, : ");
    scanf("%d", &position);

    // 입력한 위치의 비트를 끄기
    value = clear_bit(value, position);
    printf("비트 끈 후 값: %d (0b", value);
    print_Ejinsu(value);
    printf(")\n");

    // 해당 비트가 꺼졌는지 확인
    if (is_bit_set(value, 3)) {
        printf("3번째 비트가 아직 켜져있음 .\n");
    } else {
        printf("3번째 비트가 꺼짐 .\n");
    }

    // 2번째 비트를 켜기
    value = set_bit(value, 2);
    printf("2번째 비트를 설정 한 후 값: %d (0b", value);
    
    print_Ejinsu(value);
    printf(")\n");

    return 0;
}

