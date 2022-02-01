#include<bits/stdc++.h>
using namespace std;
#define SIZE 1001

int heap[SIZE];
int heapsize;

void heap_push(int val)
{
    if(heapsize >= SIZE)
    {
        cout<<"Overflow"<<endl;
        return;
    }

    heap[heapsize] = val; //Push 1st element to the end of heap
    int curr = heapsize;

    //Percolate-up

    while(curr > 0 and heap[(curr -1)/2] < heap[curr])
    {
        int temp = heap[(curr-1)/2];
        heap[(curr-1)/2] = heap[curr];
        heap[curr] = temp;

        curr = (curr-1)/2; //Current pointer moves to parent
    }

    heapsize += 1;
}

int heap_pop()
{
    if(heapsize <= 0)
    {
        cout<<"Underflow"<<endl;
        return -1;
    }

    int curr = 0; // current index is 0 which is root (storing the max element)
    int poped = heap[0]; //Save the element to be poped
    heap[0] = heap[heapsize -1]; //Copy last element to the root
    heapsize -= 1; //Reduce heapsize by 1

    //Max_Heapify

    while((2*curr+1) <heapsize) //While we don't reach a leaf node
    {
        int child;
        
        if((2*curr+2) == heapsize) //If we only have have ieftchild
        child = 2*curr+1;

        else
        {
           if(heap[2*curr+1] > heap[2*curr+2])
           child = 2*curr+1;

           else
           child = 2*curr+2;
        }

    if(heap[curr] < heap[child])
    {
        int temp = heap[curr];
        heap[curr] = heap[child];
        heap[child] = temp;

        curr = child;
    }
    else //Max hepify is done (because the curr node is having higher value than both left child and right child)
    break;
}
return poped;
}

void Show_Heap()
{
    for(int i=0;i<heapsize;++i)
    {
        cout<<heap[i]<<" "<<endl;
    }
}

   void init()
   {
   heapsize = 0;
   }

 int main()
{
    init();
    while(1)
    {
            cout<<"1:Push... 2:Pop... 3:Show_Heap... 4:Terminate"<<endl;

            int option;
            int element;

            cin>>option;

            switch (option)
            {
              case 1:
              cout<<"Enter the element->"<<endl;
              cin>>element;
              heap_push(element);
              break;


              case 2:
              cout<<"Poped"<<heap_pop()<<endl;
              break;


              case 3:
              cout<<"Elements are ::";
              Show_Heap();
              break;

              default:
              return 0;
            }
        }
    }
