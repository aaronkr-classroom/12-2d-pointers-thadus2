#include <stdio.h>
#include <malloc.h>

void GetMyData(int **q) { 
	*q = (int*)malloc(8);
}

int main(void) {
	int* p; 
	GetMyData(&p);
	*p = 5; 

	printf("p (ÁÖ¼Ò): %p\n", p);
	printf("*p (°ª): %d\n", *p);

	free(p); 

	return 0;
}