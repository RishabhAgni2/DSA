class EventManager {
public:
    unordered_map<int,int> map;//id->priority
    priority_queue<pair<int,int>> pq;//{priority,-Id}
    EventManager(vector<vector<int>>& events) {
        for(auto &e:events){
            int id = e[0];
            int p = e[1];
            map[id]=p;
            pq.push({p,-id});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        map[eventId] = newPriority;
        pq.push({newPriority,-eventId});
    }
    
    int pollHighest() {
        while(!pq.empty()){
            auto [p,eId] = pq.top();
            int id = -eId;
            if(map.count(id)&&map[id]==p){
                pq.pop();
                map.erase(id);
                return id;
            }
            pq.pop();
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */