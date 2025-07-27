#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i + 1); }
    int rightChild(int i) { return (2 * i + 2); }

    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int smallest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;
        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void initializeHeap() {
        heap.clear();
    }

    void insert(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    int getMin() {
        if (heap.empty()) return -1;
        return heap[0];
    }

    void extractMin() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
    }

    int heapSize() {
        return heap.size();
    }

    bool isEmpty() {
        return heap.empty();
    }

    void changeKey(int ind, int val) {
        if (ind < 0 || ind >= heap.size()) return;
        int oldVal = heap[ind];
        heap[ind] = val;

        if (val < oldVal)
            heapifyUp(ind);
        else
            heapifyDown(ind);
    }
};

int main() {
    MinHeap h;
    vector<string> operations = { "initializeheap", "insert", "insert", "insert", "getMin", "heapSize", "isEmpty", "extractMin", "changeKey" , "getMin" };
    vector<vector<int>> nums = { {}, {4}, {1}, {10}, {}, {}, {}, {}, {0, 16}, {} };
    vector<string> output;

    for (int i = 0; i < operations.size(); i++) {
        if (operations[i] == "initializeheap") {
            h.initializeHeap();
            output.push_back("null");
        } else if (operations[i] == "insert") {
            h.insert(nums[i][0]);
            output.push_back("null");
        } else if (operations[i] == "getMin") {
            output.push_back(to_string(h.getMin()));
        } else if (operations[i] == "extractMin") {
            h.extractMin();
            output.push_back("null");
        } else if (operations[i] == "heapSize") {
            output.push_back(to_string(h.heapSize()));
        } else if (operations[i] == "isEmpty") {
            output.push_back(to_string(h.isEmpty()));
        } else if (operations[i] == "changeKey") {
            h.changeKey(nums[i][0], nums[i][1]);
            output.push_back("null");
        }
    }

    for (auto &x : output) cout << x << " ";
    return 0;
}
