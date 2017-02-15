/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:

    bool is_overlap(Interval interval_a, Interval interval_b) {
        
        if ((interval_a.end < interval_b.start) | (interval_a.start > interval_b.end)) {
            return false;
        }
        else {
            return true;
        }
    }

    struct compare_Interval {
        bool operator()(const Interval &a, const Interval &b) const {
            return (a.start < b.start);
        }
    };

    vector<Interval> merge(vector<Interval>& intervals) {
        
        if ((intervals.size() == 0) | (intervals.size() == 1)) {
            return intervals;
        }
	
        // sorted the input vector first by first element, ie start element.
        // compare the current element in the vector to the result vector which
        // stores the current merge interval. 
        // If the current element has overlap with last element of result vector, we need to merge it.
        sort(intervals.begin(), intervals.end(), compare_Interval());
        vector <Interval> result;
        result.push_back(intervals[0]);
        int k = 0;
        for (int i = 1; i < intervals.size() ; i++) {
            Interval temp = result[k];
            if (is_overlap(intervals[i], temp)) {
                Interval res;
                int s_p = min(intervals[i].start, temp.start);
                int e_p = max(intervals[i].end, temp.end);
                res = Interval(s_p, e_p);
                result.pop_back();
                result.push_back(res);
            }
            else {
                result.push_back(intervals[i]);
                k += 1;
            }
        }
        
        return result;
        
    }
};
