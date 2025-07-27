#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

struct Node {
    int key, value, freq;
    Node(int k, int v) : key(k), value(v), freq(1) {}
};

class LFUCache {
private:
    int capacity, minFreq;
    unordered_map<int, list<Node>::iterator> keyNode;
    unordered_map<int, list<Node>> freqList;

    void updateFreq(int key) {
        auto it = keyNode[key];
        int freq = it->freq;
        Node node = *it;
        freqList[freq].erase(it);
        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq) minFreq++;
        }
        node.freq++;
        freqList[node.freq].push_front(node);
        keyNode[key] = freqList[node.freq].begin();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }

    int get(int key) {
        if (capacity == 0 || keyNode.find(key) == keyNode.end()) return -1;
        updateFreq(key);
        return keyNode[key]->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyNode.find(key) != keyNode.end()) {
            keyNode[key]->value = value;
            updateFreq(key);
            return;
        }

        if (keyNode.size() == capacity) {
            auto it = freqList[minFreq].back();
            keyNode.erase(it.key);
            freqList[minFreq].pop_back();
            if (freqList[minFreq].empty()) freqList.erase(minFreq);
        }

        Node node(key, value);
        freqList[1].push_front(node);
        keyNode[key] = freqList[1].begin();
        minFreq = 1;
    }
};
