#include <stdio.h>
#include <malloc.h>

int main(void) {
	short** pp;
	// 4����Ʈ�� �Ҵ� 
	pp = (short**)malloc(sizeof(short*)); 
	// 2����Ʈ�� �Ҵ�
	*pp = (short*)malloc(sizeof(short));

	**pp = 10; 
	printf("**pp: %d\n", **pp); // 10�� ���

	free(*pp);
	free(pp); 

	return 0;
}