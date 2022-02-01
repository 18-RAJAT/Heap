#include<bits/stdc++.h>
using namespace std;

#define SIZE 1001

int heap[SIZE];
int heapsize;

void Heap_Push(int val)
{
    if(heapsize >= SIZE)
    {
        cout<<"Overflow"<<endl;
        return;
    }

    heap[heapsize] = val; //Push 1st element to the end of heap

    int curr = heapsize;

    //Percolate-up

    while(curr>0 and heap[(curr-1)/2]>heap[curr])
    {
        int temp = heap[(curr-1)/2];
        heap[(curr-1)/2] = heap[curr];
        heap[curr] = temp;

        curr = (curr-1)/2; //Current pointer move to parent 
    }

    heapsize += 1;
}

int Head_Pop()
{
    if(heapsize <= 0)
    {
        cout<<"Underflow"<<endl;
    }

    int  curr = 0;
    
    int Poped = heap[0]; //Save the element to be poped
    heap[0] = heap[heapsize - 1]; //Copy last element to the root
    heapsize -= 1; //Reduce heapsize by 1

    //Max_heapify
    while((2*curr+1) < heapsize) //While we don't reach a leaf node
    {
        int child;
        
        if((2*curr + 2) == heapsize) //If we only have left child

        child = 2*curr+1;

        else  //If both left and right child are present then find which is maximum
        {
            if(heap[2*curr+1] < heap[2*curr+2])
            child = 2*curr+1;

            else

            child = 2*curr+2;
        }

        //If curr node is lower than max(leftchild , rightchild) then swap and do max_hepify again for that child

        if(heap[curr]>heap[child])
        {
            int temp = heap[curr];
            heap[curr] = heap[child];
            heap[child] = temp;

            curr = child;
        }

        else  //Max heapify is done (because the curr node is higher value than both leftchild and rightchild)

        break;
    }

    return Poped;
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
        cout<<"1:Push...2:Pop...3:Show_Heap...4:Terminate"<<endl;

        int option;
        int element;
        cin>>option;

        switch(option)
        {
            case 1:
            cout<<"Enter the elements"<<endl;
            cin>>element;

            Heap_Push(element);
            break;

            case 2:
            cout<<"Poped"<<Head_Pop()<<endl;
            break;

            case 3:
            Show_Heap();
            break;

            default:
            return 0;
        }
    }
}