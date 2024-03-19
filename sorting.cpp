
#include<iostream>
using namespace std;
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minimum=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minimum]){
                minimum=j;}
        }
            if(minimum!=i){
                int temp=arr[minimum];
                arr[minimum]=arr[i];
                arr[i]=temp;
            }
        }
        cout<<"Output : ";
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
       }
       cout<<endl;
}
void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int current=arr[i];
        int j=i-1;
        while(arr[j]>current &&j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
    cout<<"Output : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void bubbleSort(int arr[],int n){
    int counter=1;
    while(counter<n){
        for(int i=0;i<n-counter;i++){
            if(arr[i]>arr[i+1]){
                int temp=arr[i+1];
                arr[i+1]=arr[i];
                arr[i]=temp;
            }
        }
        counter++;
    }
    cout<<"Output : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void marge(int arr[],int l,int mid,int r){
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1];
    int b[n2];
    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+1+i];
    }
    int i=0;
    int j=0;
    int k=l;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            k++; i++;
        }
        else{
            arr[k]=b[j];
            k++; j++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        k++; i++;
    }
    while(j<n2){
        arr[k]=b[j];
        k++; j++;
    }
}
void mergeSort(int arr[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        marge(arr,l,mid,r);
    }
}
void Swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int Partition(int arr[],int l,int r){
    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            Swap(arr,i,j);
        }
    }
    Swap(arr,i+1,r);
    return i+1;
}
void quickSort(int arr[],int l,int r){
    if(l<r){
        int pi=Partition(arr,l,r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
}
void countingSort(int arr[],int n){
    long k=arr[0];
    for(int i=0;i<n;i++){
        if(k<arr[i]) k=arr[i];
    }
    long Count[k];
    for(int i=0;i<k;i++){
        Count[i]=0;
    }
    for(int i=0;i<n;i++){
        Count[arr[i]]++;
    }
    for(int i=1;i<=k;i++){
        Count[i]+=Count[i-1];
    }
    long output[n];
    for(int i=n-1;i>=0;i--){
        output[--Count[arr[i]]]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}
int main()
{
    while(1){

        int n1;
        cout<<"Enter Array size : ";
        cin>>n1;
        int arr[n1];
        for(int i=0;i<n1;i++){
            cout<<"Enter Array "<<i+1<<" Element : ";
            cin>>arr[i];
        }
        cout<<"1. Selection Sort"<<endl;
        cout<<"2. Insertion Sort"<<endl;
        cout<<"3. Bubble Sort"<<endl;
        cout<<"4. Merge Sort"<<endl;
        cout<<"5. Quick Sort"<<endl;
        cout<<"6. Counting Sort"<<endl;
        cout<<"7. Exit"<<endl;
        int n;
        cin>>n;
        if(n==1) selectionSort(arr,n1);
        else if(n==2) insertionSort(arr,n1);
        else if(n==3) bubbleSort(arr,n1);
        else if(n==4){
            mergeSort(arr,0,n1-1);
            cout<<"Output : ";
            for(int i=0;i<n1;i++) cout<<arr[i]<<" ";
            cout<<endl;
        }
        else if (n==5){
            quickSort(arr,0,n1-1);
            cout<<"Output : ";
            for(int i=0;i<n1;i++) cout<<arr[i]<<" ";
            cout<<endl;
        }
        else if(n==6){
            countingSort(arr,n1);
            cout<<"Output : ";
            for(int i=0;i<n1;i++) cout<<arr[i]<<" ";
            cout<<endl;
        }
        else break;
    }

    return 0;
}
