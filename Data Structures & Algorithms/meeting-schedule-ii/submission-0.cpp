/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(),[](Interval A, Interval B){
            return A.start<B.start;
        });
        priority_queue<int, vector<int>, greater<int>>minheap;
        for(auto &interval : intervals){
            if(!minheap.empty() and minheap.top() <= interval.start){
                minheap.pop();
            }
            minheap.push(interval.end);
        }
        return minheap.size();


    }
};
