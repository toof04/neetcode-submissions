import heapq
class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        # sort by pickup location
        trips.sort(key=lambda x: x[1])

        minHeap = [] # (end, num_passengers)
        curr_passenger_cnt = 0

        for num_passengers, start, end in trips:
            # Need to unload passengers because N number of trips have ended
            while minHeap and minHeap[0][0] <= start:
                curr_passenger_cnt -= heapq.heappop(minHeap)[1]

            # Need to load more passengers and we haven't reached capacity
            if (curr_passenger_cnt + num_passengers) <= capacity:
                curr_passenger_cnt += num_passengers
                heapq.heappush(minHeap, (end, num_passengers))
            # Need to load more passengers and we've reached capacity
            else:
                return False
        
        return True