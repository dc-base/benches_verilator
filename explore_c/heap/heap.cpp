#include <iostream>

void swap(int *a, int *b){
	int temp = a;
	a* = b*;
	b* = temp;
}



struct maxHeap{
	int max;
	int count = 0;
	vector<int> myHeap;

	void insertKey(int key){
		count++;
		int i = count - 1;
		myHeap[i] = k;
		while(i !=0 && myHeap[(i-1)/2] < myHeap[i]){
			swap(&myHeap[i], &myHeap[(i-1)/2]);
			i = (i-1)/2;
		}
	}

	void printHeap(){
		for(int i = 0; i < myHeap.size(); i++){
			printf("%d\n", myHeap[i]);
		}
	}
};

int main(){
	maxHeap = new maxHeap();
	maxHeap.insertKey(10);
	maxHeap.printHeap();
}

