#include<bits/stdc++.h>
using namespace std;

void Heapify(vector<int>& heap,int curr,int size)
{
    int largest = curr;

    int left = 2*curr+1; //left child
    int right = 2*curr+2; //right child

    if(left<size and heap[left]>heap[largest])
    {
        largest = left;
    }

    if(right<size and heap[right]>heap[largest])
    {
        largest = right;
    }

    if(largest != curr)
    {
        int temp = heap[curr];
        heap[curr] = heap[largest];
        heap[largest] = temp;

        Heapify(heap,largest,size);
    }
}

void Heapsort(vector<int>& heap,int comparision=0)
{
    //Build heap (rearrange array)
    for(int i=heap.size()/2-1;i >= 0;--i)
      Heapify(heap,i,heap.size());

    for(int i=heap.size()-1;i>0;--i)
    {
        int temp = heap[0]; //Swap heap root with the last element
        heap[0] = heap[i];
        heap[i] = temp;

        Heapify(heap,0,i); //Heapify root with heapsize = i
        comparision++;
    }
    cout<<"Number of comparisions are :"<<comparision<<endl;
}

int main()
{
    vector<int> heap{9,6,8,2,1,4,3,7}; //Max heap
    Heapsort(heap);

    cout<<"heap is ASC"<<endl;
    for(int i=0;i<heap.size();++i)
    {
      cout<<heap[i]<<" "<<endl;
    }
    return 0;
}



// its parent floor( (x - 1) / 2 )
// its left child 2x + 1
// its right child 2x + 2
// The index of the last non-leaf node of a n-sized heap is floor( n / 2 ) - 1.

	// void siftDown(vector<int>& nums, int n, int i){
    //     int biggest = i;
    //     int l = 2 * i + 1;
    //     int r = 2 * i + 2;
    //     if(l < n && nums[biggest] < nums[l])
    //         biggest = l;
    //     if(r < n && nums[biggest] < nums[r])
    //         biggest = r;
    //     if(biggest != i){
    //         swap(nums[i], nums[biggest]);
    //         siftDown(nums, n, biggest);
    //     }
    // }
    
	// // heapSort(nums);
    // void heapSort(vector<int>& nums){
    //     // heapify stage (bottom up approach)
    //     for(int i = nums.size() / 2 - 1; i >= 0; i--)
    //         siftDown(nums, nums.size(), i);
    //     // sorting stage
    //     for(int i = nums.size() - 1; i > 0; i--){
    //         swap(nums[0], nums[i]);
    //         siftDown(nums, i, 0);
    //     }
    // }
