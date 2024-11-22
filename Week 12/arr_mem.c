#include <stdio.h>

#define MAX_COUNT 5 

int main(void) {
	int num[MAX_COUNT],
		count = 0,
		sum = 0,
		i;

	while (count < MAX_COUNT) {
		printf("숫자를 입력하세요 (9999를 누르면 종료): ");
		// scanf_s("%d", &num[count]);
		scanf_s("%d", num + count); // *p + 1

		if (num[count] == 9999) break; 
		count++; 
	}

	for (i = 0; i < count; i++) {
		if (i > 0) printf(" + ");
		printf("%d", num[i]);
		sum = sum + num[i];
	}
	printf(" = %d\n", sum);

	return 0;
}