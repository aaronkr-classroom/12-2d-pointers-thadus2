#include <stdio.h>
#include <malloc.h>

void GetMyData(int **q) { 
	*q = (int*)malloc(8);
}

int main(void) {
	int* p; 
	GetMyData(&p);
	*p = 5; 

	printf("p (�ּ�): %p\n", p);
	printf("*p (��): %d\n", *p);

	free(p); 

	return 0;
}