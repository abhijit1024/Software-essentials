/*
	Time complexity - O(nlogn)
	Space complexity - O(n)
*/
void mergeArrays(vector<int> arr, int l1, int h1, int l2, int h2) {
	const int N = h1 - l1 + 1;
	const int M = h2 - l2 + 1;

	vector<int> temp(M + N);
	int a1 = l1;
	int a2 = l2;
	int curr = 0;

	while(a1 <= h1 && a2 <= h2) {
		temp[curr++] = arr[a1] < arr[a2] ? arr[a1++] : arr[a2++];
	}
	while(a1 <= h1) 
		temp[curr++] = arr[a1++];
	while(a2 <= h2) 
		temp[curr++] = arr[a2++];
	for(int i = l1; i <= h2; i++) {
		arr[i] = temp[i - l1];
	}
}
vector<int> mergeSortHelper(vector<int>& arr, int l, int h) {
	if(l <= h) {
		int mid = l + (h - l) / 2;
		mergeSortHelper(arr, l, mid-1);
		mergeSortHelper(arr, mid - 1, h);
		mergeArrays(arr, l, mid - 1, mid + 1, h);
	}
	return arr;
}
vector<int> mergeSort(vector<int> arr) {
	int l = 0, h = arr.size() - 1;
	return mergeSortHelper(arr, l, h);
}

