#include <stdio.h>

int* BP, * SP; // Base Pointer, Stack Pointer 시뮬레이션
int stack[1024]; // (int) 4비트 * 1024
int stackIndex = 0; 

void Show() {
	printf("--------------------------------------------\n");
	printf("현재 스택 상태 (Top -> Bottom):\n");
	for (int i = stackIndex - 1; i >= 0; i--) {
		int* addr = (int*)stack[i];
		int actualValue = *addr;
		printf("스택[%d]: %p (주소값), %d (실제값)\n", i, addr, actualValue);
	}
	printf("Base Pointer (BP): %p\n", (void*)BP);
	printf("Stack Pointer (SP): %p\n", (void*)SP);
	printf("--------------------------------------------\n");
}

void push(int value) {
	stack[stackIndex++] = value;
	SP = &stack[stackIndex]; // 스택 위로 포인터를 이동
}

int* pop() {
	if (stackIndex > 0) {
		SP = &stack[--stackIndex];
		return stack[stackIndex];
	}
	return -1; 
}

void Test(int a, int b, int c) {
	// 지역 변수
	int x = a + b;
	int y = b + c;
	int z = c + a;

	printf("Test() 함수 진입 - 스택 프레임 생성\n");
	push((int)BP);
	// BP = &stack[stackIndex - 3]; 

	push((int)&x); // 0x0645347827
	push((int)&y);
	push((int)&z);

	Show();

	printf("Test() 함수 반환 - 스택 프레임 해제\n");
	pop(); pop(); pop();
	// BP = &stack[stackIndex + 3];
	BP = pop();

	Show();
}

int main(void) {
	int a = 10,
		b = 20,
		c = 30;

	printf("Main() 함수 시작 - 초기 스택 상태\n");
	push((int)&a); 
	push((int)&b);
	push((int)&c);

	BP = &stack[0];
	Show();

	printf("Test() 함수 호출\n");
	Test(a, b, c);

	printf("Main() 함수 종료 - 스택 상태 복구\n");
	pop(); pop(); pop();
	Show();

	return 0;
}