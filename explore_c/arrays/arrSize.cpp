#include <iostream>

int main(){

	int arr[5];
	int size = sizeof(arr)/sizeof(arr[0]);
	std::cout<<"arr: "<<size<<"\n";
	int sizeInt = sizeof(int);
	std::cout<<"int: "<<sizeInt<<"\n";
	//printf("%d\n", sizeof(arr)/sizeof(arr[0]));
	return 0;

}
