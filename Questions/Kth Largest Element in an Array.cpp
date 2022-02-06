
//  Max Heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int>max_heap;
        
        for(auto i : nums)
        {
            max_heap.push(i);
        }
            for(int i=1;i<k;++i)
            {
                max_heap.pop();
            }
       return max_heap.top();
    }
};



//Min Heap
class Solution{
public:
    
 int findKthLargest(vector<int>& nums, int k) {
        
priority_queue<int, vector<int>,greater<int>>minHeap;
    
 for (int num:nums)
{ 
   minHeap.push(num);

   if(minHeap.size()>k)
       
      minHeap.pop();
 }

   return minHeap.top();
    }
};