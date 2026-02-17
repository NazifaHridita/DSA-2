#include<bits/stdc++.h>
using namespace std;

class Patient
{ 
    public:
    int id;
    int severity;
    int age;
    int time;
    Patient(){}
    Patient(int i,int s,int a,int t)
    {
        id = i;
        severity = s;
        age = a;
        time = t;
    }
    
};
class Heap
{
    Patient *arr;
    int capacity;
    int sz;
    bool priority(Patient a,Patient b)
    {
        if(a.severity != b.severity)
        {
            return a.severity > b.severity;
        }
        if(a.age != b.age)
        {
            return a.age > b.age;
        }
        return a.time < b.time ;
    }
    public :
    Heap(int cap)
    {
        int capacity = cap;
        arr = new Patient[cap+1];
        sz = 0;
    }

    void insert(Patient a)
    {
        if(sz == capacity) return ;
        sz++;
        arr[sz] = a;
        percolate_up(sz);
    }
    void percolate_up(int i)
    {
        int parent = i/2;
        if(parent >=1)
        {
            if(priority(arr[i],arr[parent]))
            {
                swap(arr[parent],arr[i]);
                percolate_up(parent);
            }
        }
    }
    Patient treat_next()
    {
        Patient nx = arr[1];
        arr[1] = arr[sz];
        sz --;
        percolate_down(1);
        return nx;
    }
    void percolate_down(int i)
    {
        int largest = i;
        int left = 2*i;
        int right =2*i+1;
        if(left<=sz && priority(arr[largest],arr[left]))
        {
            largest = left;
        }
        if(right <= sz && priority(arr[largest],arr[right]))
        {
            largest = right;
        }
        if(largest != i)
        {
            swap(arr[largest],arr[i]);
            percolate_down(largest);
        }

    }
     
};
