#include <iostream>
using namespace std;

// ---------------- Merge Sort ----------------
void merge(int arr[], int l, int m, int r) {
    int n1 = m-l+1, n2 = r-m;
    int L[n1], R[n2];
    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int i=0;i<n2;i++) R[i]=arr[m+1+i];

    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]) arr[k++]=L[i++];
        else arr[k++]=R[j++];
    }
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int m = l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

// ---------------- Quick Sort ----------------
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
            i++;
            int t=arr[i]; arr[i]=arr[j]; arr[j]=t;
        }
    }
    int t=arr[i+1]; arr[i+1]=arr[high]; arr[high]=t;
    return i+1;
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

// ---------------- Radix Sort ----------------
int getMax(int arr[], int n){
    int mx=arr[0];
    for(int i=1;i<n;i++) if(arr[i]>mx) mx=arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp){
    int output[n]; int count[10]={0};
    for(int i=0;i<n;i++) count[(arr[i]/exp)%10]++;
    for(int i=1;i<10;i++) count[i]+=count[i-1];
    for(int i=n-1;i>=0;i--){
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++) arr[i]=output[i];
}

void radixSort(int arr[], int n){
    int m = getMax(arr,n);
    for(int exp=1;m/exp>0;exp*=10) countSort(arr,n,exp);
}

void display(int arr[], int n){
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int arr1[] = {38,27,43,3,9,82,10};
    int n = sizeof(arr1)/sizeof(arr1[0]);

    cout<<"Original Array: ";
    display(arr1,n);

    // Merge Sort
    int arrM[n]; for(int i=0;i<n;i++) arrM[i]=arr1[i];
    mergeSort(arrM,0,n-1);
    cout<<"Merge Sorted: "; display(arrM,n);

    // Quick Sort
    int arrQ[n]; for(int i=0;i<n;i++) arrQ[i]=arr1[i];
    quickSort(arrQ,0,n-1);
    cout<<"Quick Sorted: "; display(arrQ,n);

    // Radix Sort
    int arrR[n]; for(int i=0;i<n;i++) arrR[i]=arr1[i];
    radixSort(arrR,n);
    cout<<"Radix Sorted: "; display(arrR,n);

    return 0;
}