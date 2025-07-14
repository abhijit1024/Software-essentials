

vector<int> selectionSort(vector<int> arr) {
    int min_el;
    for(int i = 0; i < arr.size() - 1; i++) {
        min_el = i;
        for(int j = i+1; j < arr.size(); j++) {
            if(arr[j] < arr[min_el])
                min_el = j;
        }
        swap(arr[i], arr[min_el]);
    }
    return arr;
}