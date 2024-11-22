#include <stdio.h>

int main(void) {
	short data = 3,
		* p = &data, 
		** pp = &p; 

	printf("[Before  ] data: %d\n", data); 
	*p = 40; // 1차원 포인터 p를 사용하여 data 변수 값을 40으로 수정함
	printf("[Use *p  ] data: %d\n", data); 
	**pp = 500; // 2차원 포인터 pp를 사용하여 data 변수 값을 500으로 수정함
	printf("[Use **pp] data: %d\n", data); 

	return 0;
}