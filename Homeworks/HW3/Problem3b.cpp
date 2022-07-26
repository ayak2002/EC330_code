#include <iostream>
#include "ListNode.h"

DListNode* twowayBubble(DListNode* head) {

	// your implementation goes here
	DListNode* current1 = head;
	DListNode* current2 = head->next;
	int temp;
	int swaps;
	do{
		swaps = 0;
		while((current2->next) != NULL) { //while current2 is not pointing to the last element
			if (current1->val > current2->val) {
				temp = current1->val;
				current1->val = current2->val;
				current2->val = temp;
				swaps++;
			}
			current1 = current1->next;
			current2 = current2->next;
		}
		if(current1->val > current2->val) { //we need to check again since when current2 is pointing to the last element, the if statement is not evaluated
			temp = current1->val;
			current1->val = current2->val;
			current2->val = temp;
			swaps++;
		}
		while(current1 != head) { //while current1 is not pointing to the first element
			if(current2->val < current1->val) {
				temp = current1->val;
				current1->val = current2->val;
				current2->val = temp;
				swaps++;
			}
			current1 = current1->prev;
			current2 = current2->prev;
		}
		if(current2->val < current1->val) { //we need to check again since when current1 is pointing to the first element, the if statement is not evaluated
			temp = current1->val;
			current1->val = current2->val;
			current2->val = temp;
			swaps++;
		}
	}while(swaps != 0); //if there were no swaps, the array is sorted

	return head; // don't forget to change this
}

int main(){
	DListNode myNode1(3);
	DListNode* head = &myNode1;
	DListNode myNode2(5);
	DListNode myNode3(2);
	DListNode myNode4(1);
	myNode1.next = &myNode2;
	myNode2.next = &myNode3;
	myNode2.prev = &myNode1;
	myNode3.next = &myNode4;
	myNode3.prev = &myNode2;
	myNode4.prev = &myNode3;
	twowayBubble(head);
	for(DListNode* current = head; current != NULL; current = current->next) {
		std::cout << current->val << " " << std::endl;
	}
}
