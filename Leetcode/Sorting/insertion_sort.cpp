

vector<int> insertionSort(vector<int> arr) {
	int j = 0;
	
	for(int i = 1; i < arr.size(); i++) {
		j = i;
		while(j > 0 && arr[j-1] > arr[j]) {
			swap(arr[j-1], arr[j]);
			--j;
		}
	}
	
	return arr;
}