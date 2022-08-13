#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#define SIZE 32
#define TRUE 1
#define FALSE 0
#define byte_to_bit_size(x) (x*8)

struct stack {
	unsigned short int p;
	bool list[SIZE];
};

typedef struct stack STACK;
void INIT_STACK(STACK *stack_ptr);
bool STACK_EMPTY(STACK stack);
bool STACK_FULL(STACK stack);
bool push(STACK *stack_ptr, bool x);
bool pop(STACK *stack_ptr, bool *x);


int main(int argc, char const *argv[])
{
	STACK *binary=malloc(sizeof(STACK));
	unsigned int num;
	bool bit;
	do {
		if (argc==2) {
			num=atoi(argv[1]);
		}
		else {
			printf("Type a decimal (0-%u)(%ld BITS): ",UINT_MAX, byte_to_bit_size(sizeof(UINT_MAX)));
			scanf("%d", &num);
			system("clear");
		}
		
		
	} while(num>UINT_MAX || num<0);
	INIT_STACK(binary);

	for (short int i=0;i<SIZE;i++) {
		bit=num%2;
		num/=2;
		push(binary, bit);
	}
	for (short int i=0;i<SIZE;i++) {
		pop(binary, &bit);
		printf("%d",bit);
	}
	printf("\n");
	free(binary);
	return 0;
}
void INIT_STACK(STACK *stack_ptr) {
	stack_ptr->p=-1;
}
bool STACK_EMPTY(STACK stack) {
	return stack.p==-1;
}
bool STACK_FULL(STACK stack) {
	return stack.p==SIZE-1;
}
bool push(STACK *stack_ptr, bool x) {
	if (STACK_FULL(*stack_ptr))
		return FALSE;
	stack_ptr->p++;
	stack_ptr->list[stack_ptr->p]=x;
	return TRUE;
}
bool pop(STACK *stack_ptr, bool *x) {
	if (STACK_EMPTY(*stack_ptr))
		return FALSE;
	*x=stack_ptr->list[stack_ptr->p];
	stack_ptr->p--;
	return TRUE;
}
