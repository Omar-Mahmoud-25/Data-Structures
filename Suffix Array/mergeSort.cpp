template <class T>
void Merge(T a[],int left,int mid, int right){
    int n1 = mid - left + 1,n2 = right - mid;
    T l[n1],r[n2];
    for (int i = 0; i<n1; i++)
        l[i] = a[left+i];
    for (int i = 0; i<n2; i++)
        r[i] = a[mid+i+1];
    int i = 0,j = 0,k = left;
    while(i < n1 && j < n2)
        if (l[i] < r[j])
            a[k++] = l[i++]; 
        else 
            a[k++] = r[j++];
    while(i<n1) 
        a[k++] = l[i++];
    while(i<n2)
        a[k++] = r[j++];
}

template <class T>
void MergeSort(T a[], int left, int right) {
    if (left >= right)
        return;
    
    int mid = left + (right - left) / 2;
    MergeSort(a, left, mid);
    MergeSort(a, mid + 1, right);
    Merge(a, left, mid, right);
}

template <class T>
void MergeSort(T a[],int n){
    return MergeSort(a,0,n-1);
}