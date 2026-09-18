class MedianFinder {

    struct cmp {
        bool operator() (auto& x, auto& y) {
            return x > y;
        }
    };

    priority_queue<int> maxHeap;
    priority_queue<
        int,
        vector<int>,
        cmp
    > minHeap;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        if(!minHeap.empty() && maxHeap.top() > minHeap.top()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        
        if(maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if(minHeap.size() > maxHeap.size() + 1) { 
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(minHeap.size() == maxHeap.size()) {
            double res = minHeap.top() + maxHeap.top();
            return res / 2;
        } else if(maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            return minHeap.top();
        }
    }
};