#include <bits/stdc++.h>
using namespace std;




struct MinHeapNode {
    int element;
    int idx;
};


void swap(MinHeapNode *a, MinHeapNode *b) {
    MinHeapNode temp = *a;
    *a = *b;
    *b = temp;
}



class MinHeap {
    
    MinHeapNode* harr;
    int heap_size;

public:

    MinHeap(MinHeapNode a[], int size);

    void MinHeapify(int);

    int left(int i) { return (2*i+1); }

    int right(int i) { return (2*i+2); }

    MinHeapNode getMin() { return harr[0]; }

    void replaceMin(MinHeapNode x) {
        harr[0] = x;
        MinHeapify(0);
    }
};


MinHeap::MinHeap(MinHeapNode a[], int size) {
    heap_size = size;
    harr = a;
    int i = (heap_size-1)/2;
    while (i >= 0) {
        MinHeapify(i);
        i--;
    }
}



void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heap_size && harr[l].element < harr[i].element) smallest = l;
    if (r < heap_size && harr[r].element < harr[smallest].element) smallest = r;
    if (smallest != i) {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}


void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m-l+1;
    int n2 = r-m;

    int L[n1], R[n2];

    for (i=0; i < n1; i++) L[i] = arr[l+i];
    for (j=0; j < n2; j++) R[j] = arr[m+1+j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}


void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r-l)/2;

        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}



FILE* openFile(char* fileName, char* mode) {
    FILE* fp = fopen(fileName, mode);
    if (!fp) {
        perror("Error While opening the file.\n");
        exit(EXIT_FAILURE);
    }
    return fp;
}


void mergeFiles(char* output_file, int n, int k) {
    FILE* in[k];

    for (int i=0; i < k; i++) {
        char fileName[2];

        snprintf(fileName, sizeof(fileName), "%d", i);

        in[i] = openFile(fileName, "r");
    }

    FILE* out = openFile(output_file, "w");

    MinHeapNode* harr = new MinHeapNode[k];

    int i;

    for (i=0; i < k; i++) {
        MinHeapNode temp;
        fscanf(in[i], "%d", &temp.element);
        temp.idx = i;
        harr[i] = temp;
    }

}