/*
Samuel C.
CS2150
'linkedlist.c'
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define PUSH_FRONT 	0
#define PUSH_BACK 	1
#define POP_FRONT 	2
#define POP_BACK 	3
#define PRINT_LIST 	4
#define HELP 		5
#define QUIT 		6
#define INVALID 	7

#define BUFFER_SIZE 20

void printOptions();
int readInput(int* val);
int isNumber(const char* token);
int isEmpty(const char* input);

struct linked_list
{
	int data;
	struct linked_list* Next;
	struct linked_list* Prev;
};

struct linked_list* head;
struct linked_list* tail;

void create_node(int input, char* pos){
	struct linked_list* new_node = (struct linked_list*) malloc(sizeof(struct linked_list));
	new_node ->Prev = 0;
	new_node ->Next = 0;
	new_node ->data =input;
	if (head == 0){

		head = tail = new_node;


	}else if (strcmp(pos, "Front")==0){
        new_node ->Prev = 0;
        new_node ->Next = 0;
		head -> Prev = new_node;
		new_node -> Next = head;
		head = new_node;

	}else if (strcmp(pos, "Back")==0){
		tail -> Next = new_node;
		new_node -> Prev = tail;
		tail = new_node;
	}
}

void delete_node(char* pos){
	struct linked_list* temp;
	if (head != NULL && pos =="Front"){
		temp = head;
		head = head ->Next;
		head -> Prev = 0;
		free(temp);

	}else if(tail != NULL && pos =="Back"){
		temp = tail;
		tail -> Prev -> Next =0;
		tail = tail ->Prev;
		free(temp);
	}
}
int main(){

	// TODO: INSTANTIATE YOUR LINKED LIST HERE.




	//----END----


	int option, val;
	printOptions();

	do {
		option = readInput(&val);

		switch(option){
			case PUSH_FRONT:				// push onto front of list
				// TODO: Insert code to push val onto front of linked list here.

                create_node(val, "Front");
				//----END----
				break;
			case PUSH_BACK: 				// push onto back of list
				// TODO: Insert code to push val onto back of linked list here.
                create_node(val, "Back");

				//----END----
				break;
			case POP_FRONT: 				// remove from front of list
				// TODO: Insert code to remove from front of linked list here.
				// If list is empty, do nothing.

                delete_node("Front");
				//----END----
				break;
			case POP_BACK:					// remove from back of list
				// TODO: Insert code to remove from back of linked list here.
				// If list is empty, do nothing.

                delete_node("Back");
				//----END----
				break;
			case PRINT_LIST:				// print list
				// TODO: Insert code to print list forwards here.
				// Simply print each element separated by a space as shown below:
				// Elements: 1 2 3 4 5

				printf("Elements: ");
				struct linked_list *p = head;
				while(p != NULL){
                    printf("%d ", p->data);
                    p =p->Next;
				}
				printf("");
				printf("\n");





				//----END----
				break;
			case HELP: 						// print menu
				printOptions();
				break;
			case QUIT: 						// quit
				break;
			case INVALID: 					// bad input
				fprintf(stderr,"Invalid command or operand, please input a valid command or help to see the list again.\n");
				break;
		}

	} while(option != QUIT);

	// TODO: free any memory used by your linked list here
    free(head);
    free(tail);

	//----END----

	return 0;
}



//---------------------------------------
//NOTE: EVERYTHING BELOW THIS LINE SHOULD NOT BE TOUCHED. IT HANDLES INPUT AND SUCH FOR YOU
//---------------------------------------

int readInput(int* val){
	char input[BUFFER_SIZE]="";
	while(isEmpty(input)){
		printf("Enter command: ");
		fgets(input, BUFFER_SIZE, stdin);
		input[strcspn(input, "\n")] = 0;
	}

	char* token = strtok(input, " ");

	if ((strcmp(token, "af")) == 0){
		token = strtok(NULL, " ");
		if (isNumber(token)){
			*val = atoi(token);
			return PUSH_FRONT;
		} else return INVALID;
	} else if ((strcmp(token, "ab")) == 0){
		token = strtok(NULL, " ");
		if (isNumber(token)){
			*val = atoi(token);
			return PUSH_BACK;
		} else return INVALID;
	} else if ((strcmp(token, "rf")) == 0){
	 	return POP_FRONT;
	} else if ((strcmp(token, "rb")) == 0){
	 	return POP_BACK;
	} else if ((strcmp(token, "p")) == 0){
	 	return PRINT_LIST;
	} else if((strcmp(token, "help")) == 0){
	 	return HELP;
	} else if((strcmp(token, "-1")) == 0){
	 	return QUIT;
	} else {
		return INVALID;
	}
}

void printOptions(){
	printf("----------------------------------------------------\n");
	printf("This test harness operates with one linked list.\n");
	printf("Use any of the following options to manipulate it:\n");
	printf("\t* af <num> --- add integer to front\n");
	printf("\t* ab <num> --- add integer to back\n");
	printf("\t* rf       --- remove front element\n");
	printf("\t* rb       --- remove back element\n");
	printf("\t* p        --- print list forward\n");
	printf("\t* help     --- print off this list\n");
	printf("\t* -1       --- exit harness\n\n");
}

int isNumber(const char* token){
	int length, i = 0;
	if (token == NULL)	return 0;
	if(token[0] == '-') 	i = 1;
	length = strlen(token);
	for (; i < length; i++){
	    if (!isdigit(token[i]))
	    	return 0;
	}

	return 1;
}

int isEmpty(const char* input){
	while (*input != '\0'){
		if (!isspace((unsigned char)*input))
			return 0;
		input++;
	}

	return 1;
}
