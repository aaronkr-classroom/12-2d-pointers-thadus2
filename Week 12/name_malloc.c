#include <stdio.h>
#include <malloc.h>

int main(void) {
	char* p_name;
	p_name = (char*)malloc(20); 
	if (p_name != NULL) { 
		printf("Enter your name: ");
		gets(p_name);

		printf("Hi~~ %s\n", p_name); 
		free(p_name); 
	}
	else {
		printf("Memory allocation error!!");
	}

	return 0;
}