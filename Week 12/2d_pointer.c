#include <stdio.h>

int main(void) {
	short data = 3,
		* p = &data, 
		** pp = &p; 

	printf("[Before  ] data: %d\n", data); 
	*p = 40; // 1���� ������ p�� ����Ͽ� data ���� ���� 40���� ������
	printf("[Use *p  ] data: %d\n", data); 
	**pp = 500; // 2���� ������ pp�� ����Ͽ� data ���� ���� 500���� ������
	printf("[Use **pp] data: %d\n", data); 

	return 0;
}