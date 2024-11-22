#include <stdio.h>
#include <malloc.h>

int main(void) {
	short** pp;
	// 4바이트를 할당 
	pp = (short**)malloc(sizeof(short*)); 
	// 2바이트를 할당
	*pp = (short*)malloc(sizeof(short));

	**pp = 10; 
	printf("**pp: %d\n", **pp); // 10을 출력

	free(*pp);
	free(pp); 

	return 0;
}