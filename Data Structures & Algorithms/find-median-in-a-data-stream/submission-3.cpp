class MedianFinder {
public:
    vector<int> result;
    int sum;
    int size;

    MedianFinder() : sum(0), size(0) {
        
    }
    
    void addNum(int num) {
        sum += num;
        size++;
        result.push_back(num);
        sort(result.begin(), result.end());
    }
    
    double findMedian() {
        if (size & 1) {
            return (double) result[size/2];
        }
        else {
            //cout<<result[(size/2) - 1]<<" "<<result[(size/2)];
            return (double)((double)result[(size/2) - 1] + (double)result[(size/2)]) / 2;
        }
    }
};
