class Solution {
public:

    void merge(vector<int>& arr, int start, int mid, int end){
        vector<int> temp;
        int i = start;
        int j = mid + 1;

        while(i <= mid && j <= end){
            if(arr[i] < arr[j]){
                temp.push_back(arr[i]);
                i++;
            } else{
                temp.push_back(arr[j]);
                j++;
            }
        }

        while(i <= mid){
            temp.push_back(arr[i]);
            i++;
        }

        while(j <= end){
            temp.push_back(arr[j]);
            j++;
        }

        // copy back
        for(int idx = 0; idx < temp.size(); idx++){
            arr[start + idx] = temp[idx];
        }
    }

    void mergeSort(vector<int>& arr, int start, int end){
        if(start >= end) return;

        int mid = start + (end - start) / 2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};