struct Slot{
    int start = 0;
    int end = 0;
};

class Meeting{
public:
int id = 0;
int z = 0;
bool booked = false;
Slot slot;
};

struct Compare{
    bool operator()(Slot* A, Slot* B) {
        if(A->start == B->start)return A->end > B->end;
        return A->start > B->start;
    }
};

struct RoomCompare{
    bool operator()(Meeting* A, Meeting* B) {
        if(A->slot.end == B->slot.end)
            return A->id > B->id;

        return A->slot.end > B->slot.end;
    }
};

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<Slot*, vector<Slot*>, Compare>pq;
        
        for(auto i : meetings){
            Slot* slot = new Slot();
            slot->start = i[0];
            slot->end = i[1];
            pq.push(slot);
        }
        
        vector<Meeting*>rooms;
        for(int i = 0; i < n; i++){
            Meeting* room = new Meeting();
            room->id = i;
            room->booked = false;
            rooms.push_back(room);
        }

        //busy rooms
        priority_queue<Meeting*, vector<Meeting*>, RoomCompare>busy;

        while(!pq.empty()){
            Slot* topslot = pq.top();
            pq.pop();

            //free all rooms whose meeting has ended
            while(!busy.empty() and busy.top()->slot.end <= topslot->start){
                Meeting* room = busy.top();
                busy.pop();
                room->booked = false;
            }

            bool foundroom = false;
            for(int i = 0; i < n;i++ ){
                if(rooms[i]->booked == false){
                    rooms[i]->z = rooms[i]->z + 1;
                    rooms[i]->booked = true;
                    rooms[i]->slot.start = topslot->start;
                    rooms[i]->slot.end = topslot->end;
                    busy.push(rooms[i]);

                    foundroom = true;
                    break; //break as room found for the slot
                }
            }
            //room still not found because all are full
            if(!foundroom){
                Meeting* room = busy.top();
                busy.pop();
                int duration = topslot->end - topslot->start;
                room->slot.start = room->slot.end;
                room->slot.end = room->slot.end + duration;
                room->z++;
                busy.push(room);
            }


        }

        int ans = 0;

        for(int i = 1; i < n; i++){
            if(rooms[i]->z > rooms[ans]->z){
                ans = i;
            }
        }

        return ans;

    }
};