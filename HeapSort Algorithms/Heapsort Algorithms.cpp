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

void Heapsort(vector<int>& heap)
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
    }
}

int main()
{
    vector<int> heap{9,6,8,2,1,4,3}; //Max heap
    Heapsort(heap);

    cout<<"heap is ASC"<<endl;
    for(int i=0;i<heap.size();++i)
    {
      cout<<heap[i]<<" "<<endl;
    }
    return 0;
}
