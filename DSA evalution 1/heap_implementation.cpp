#include<bits/stdc++.h>
using namespace std;

class Heap
{
    int *arr;
    int capacity;
    int sz;
    public:
    Heap(int cap)
    {
        capacity = cap;
        arr = new int[cap+1];
        sz=0;
    }
    Heap(int cap,int a[])
    {
        sz=0;
        capacity = cap;
        arr = new int[cap+1];
        for(int i=1;i<=cap;i++)
        {
            sz++;
            arr[i]=a[i-1];
        }
    }
    void insert(int v)
    {
        if(sz==capacity)
        {
            cout << "Can not be inserted"<<endl;
            return;
        }
        sz++;
        arr[sz]=v;
        percolate_up(sz);
    }
    void percolate_up(int i)
    {
        int parent = i/2;
        if(parent >= 1)
        {
            if(arr[i] > arr[parent]) 
            {
                swap(arr[i],arr[parent]);
                percolate_up(parent);
            }
        }
    }
    int delete_max()
    {
        if(sz == 0)
        {
            cout <<"heap is empty" <<endl;
            return -1;
        }
        int mx = arr[1];
        arr[1] = arr[sz];
        sz --;
        percolate_down(1);
        return mx;

    }
    void percolate_down(int i)
    {
        int left = 2*i;
        int right = 2*i+1;
        int largest = i;

        if(left <= sz && arr[left] > arr[largest])
        {
            largest = left ; // store korlam largest value kon index e ache
        }
        if(right <= sz && arr[right] > arr[largest] )
        {
            largest = right;
        }
        if(largest != i)
        {
            swap(arr[largest],arr[i]);
            percolate_down(largest);
        }
    }
    void build_heap()
    {
        for(int i= sz/2 ;i >=1 ;i--) //starts from the last parent
        {
            percolate_down(i);
        }
    }
    void heap_sort()
    {
        int n = sz;
        for(int i = n ;i>=2;i--)
        {
            swap(arr[1],arr[i]);
            sz--;
            percolate_down(1);
        }
        sz=n;
    }
    void print()
    {
        for(int i=1;i<=sz;i++)
        {
            cout << arr[i] <<" ";
        }
        cout << endl;
    }

    int min_value()
    {
        if(sz == 0) 
        {
            cout << "Heap is empty" <<endl;
            return -1;
        }
        int leaf_index = (sz/2)+1;
        int mn = arr[leaf_index];
        for(int i = leaf_index+1 ;i <=sz ;i++)
        {
            mn = min(arr[i],mn);
        }
        return mn;

    }

};

int main()
{
    int n;
    cin >> n;
    Heap h(n);
    int i = n;
    while(i--)
    {
        int a;
        cin >> a;
        h.insert(a);
    }
    cout << "Heap: " ;
    h.print();
    cout<< h.delete_max() <<endl;
    cout << "Heap: " ;
    h.print();
    cout << "min value: " << h.min_value() <<endl;
    cout << "Sorted heap: ";
    h.heap_sort();
    h.print();
    h.build_heap();
    cout << "Heap: " ;
    h.print();
    cout << "min value: " << h.min_value() <<endl;
}