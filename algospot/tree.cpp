#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void push_heap(vector<int>& heap, int newValue) {
    heap.push_back(newValue);
    int idx = heap.size() - 1;
    
    while(idx > 0 && heap[(idx - 1)/2] < heap[idx]) {
        swap(heap[idx], heap[(idx-1)/2]);
        idx = (idx - 1)/2;
    }
}

int pop_heap(vector<int>& heap) {
    int ret = heap[0];
    int idx = 0;
    int size = heap.size() - 1;
    heap[0] = heap.back();
    heap.pop_back();
    
    while(1) {

        if(idx*2 + 1 >= size) break;
        int next = idx;

        if(heap[idx] < heap[idx*2+ 1])
            next = idx * 2 + 1;
        if(idx * 2 + 2 < size && heap[next] < heap[idx*2 + 2])
            next = idx * 2 + 2;

        if(next == idx) break;
        swap(heap[idx], heap[next]);
        idx = next;
    }
    return ret;
}

int main()
{
    vector<int> a;
    int size= 0;
    cin>>size;
    for(int i = 0; i < size ; i++)
    {
        int k = 0;
        cin>>k;
        push_heap(a, k);
    }
    for(int i = 0 ; i < size; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    for(int i = 0; i < size; i++)
    {
        cout<<pop_heap(a)<<" ";
    }
    cout<<"\n";
}