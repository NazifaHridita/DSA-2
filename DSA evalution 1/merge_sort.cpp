#include<bits/stdc++.h>
using namespace std;
void merge_array(int *a,int left,int mid,int right)
{
    int n1,n2;
    n1 =(mid-left)+1;
    n2 =(right-mid);
    int l[n1],r[n2];
    for(int i=0;i<n1;i++)
    {
        l[i] = a[left+i];
    }
    for(int i=0;i<n2;i++)
    {
        r[i] = a[mid+1+i];
    }
    int i=0,j=0,k=left; //k is trrack array
    while(i<n1 && j<n2)
    {
        if(l[i]<r[i])
        {
            a[k]=l[i];
            i++;
        }
        else{
            a[k] = r[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k] = l[i];
        i++;k++;
    }
    while(j<n2)
    {
        a[k] = r[j];
        j++;k++;
    }
}
void merge_sort(int *a,int left,int right)
{
    if(left < right)
    {
        int mid = (left+right)/2;
        merge_sort(a,left,mid);
        merge_sort(a,mid+1,right);
        merge_array(a,left,mid,right);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    merge_sort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}