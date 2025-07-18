/*
	Time complexity - O(n^2)
	Space complexity - O(1)
*/
vector<int> bubblesort(vector<int> arr) {
	bool sorted = true;
	for(int i = 0; i < arr.size() - 1; i++) {
		for(int j = 0; j < arr.size() - i - 1; j++) {
			if(arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				sorted = false;
			}
		}
		if(sorted) {
			return arr;
		}
	}
	return arr;
}
