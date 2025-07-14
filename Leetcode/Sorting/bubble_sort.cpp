vector<int> bubbleSort(vector<int> arr) {
	bool sorted = true;
	
	for(int i = 0; i < arr.size() - 1; i++) {
		for(int j = 0; j < arr.size() - i - 1; j++) {
			if(arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
				sorted = false;	
			}
		}
		if(sorted)
			return arr;	
	}
	return arr;
}
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