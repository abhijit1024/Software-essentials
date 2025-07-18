/*
	Time complexity - O(n^2)
	Space complxity - O(nlogn)
*/
vector<int> quickSortHelper(vector<int>& arr, int l, int h, default_random_engine gen) {
	if(l <= h) {
		int pivot_idx = uniform_int_distribution<int>{l,h}(gen);

		int partition_idx = partitionArray(arr, pivot_idx, l, h);

		quickSortHelper(arr, l, partition_idx-1, gen);
		quickSortHelper(arr, partition_idx+1, h, gen);
	}
	return arr;
}
vector<int> quickSort(vector<int> arr) {
	int l = 0, h = arr.size() - 1;
	default_random_engine((random_device())());
	return quickSortHelper(arr, l, h, gen);
}
