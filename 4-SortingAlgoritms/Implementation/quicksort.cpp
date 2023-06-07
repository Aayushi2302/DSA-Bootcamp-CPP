#include<bits/stdc++.h>
using namespace std;

int partition(int l, int h, int* arr){
	int pivot = arr[l];
	cout<<pivot<<endl;
	int i = l, j = h;
	while(i<j){
	do{
		i++;
	}
	while(arr[i] <= pivot);
	
	do{
		j--;
	}
	while(arr[j] > pivot);

	if(i < j){
		int temp = arr[i]; 
		arr[i] = arr[j];
		arr[j] = temp;
	}
}
		int temp2 = arr[j];
		arr[j] = arr[l];
		arr[l] = temp2;

		cout<<"  "<<arr[l]<<endl;
		return j;

}
		
void quicksort(int l, int h, int* arr){
	if(l < h){
		int j = partition(l, h, arr);
		quicksort(l, j, arr);
		quicksort(j+1, h, arr);
	}
}

int main(){
	int arr[] = {10, 9, 15, 78, 5, 32, 1};
	quicksort(0, sizeof(arr)/sizeof(arr[0]), arr);
	for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
		cout<<arr[i]<<" ";
	}
}