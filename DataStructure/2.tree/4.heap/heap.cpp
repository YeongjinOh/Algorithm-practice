#include <iostream>
#include <vector>
using namespace std;

void push_heap (vector<int> & heap, int value) {
    heap.push_back(value);
    int idx = heap.size() - 1;
    while (idx > 0 && heap[(idx-1)/2] < heap[idx]) {
        swap(heap[(idx-1)/2], heap[idx]);
        idx = (idx-1)/2;
    }
}

void show_heap (vector<int> & heap) {
    int sum = 1, mult = 1;
    for (int i=0; i<heap.size(); i++) {
        printf("%d ", heap[i]);
        if (i+1 == sum) {
            cout << endl;
            mult *= 2;
            sum += mult;
        }
    }
    cout << endl;
}

int pop_heap (vector<int> & heap) {
    int ret = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    int idx = 0;
    while(idx*2+1 < heap.size()) {
        int nextIdx = idx*2+1;
        if (idx*2+2 < heap.size() && heap[idx*2+2] > heap[idx*2+1])
            nextIdx++;
        if (heap[idx] > heap[nextIdx])
            break;
        swap(heap[idx], heap[nextIdx]);
        idx = nextIdx;
    }
    return ret;
}
int main() {
    int n;
    cout << "number of inputs:";
    cin >> n;

    int input;
    vector<int> heap;
    for (int i=0; i<n; i++) {
        cin >> input;
        push_heap(heap, input);
    }
    show_heap(heap);

    cout << "number of deletes:";
    cin >> n;
    for (int i=0; i<n; i++) {
        int top = pop_heap(heap);
        printf("pop : %d\n",top);
        show_heap(heap);
    }
    return 0;
}
