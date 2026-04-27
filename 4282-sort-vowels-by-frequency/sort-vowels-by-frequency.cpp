class Solution {
public:
    bool isvowel(char a)
    {
        if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
            return true;
        return false;
    }
    string sortVowels(string s) {
        int n=s.length();

        unordered_map<char, int> mp;
        unordered_map<char,int> occur;
        for(int i=0;i<n;i++)
            {
                if(isvowel(s[i]))
                {
                    mp[s[i]]++;
                    if(occur.find(s[i])==occur.end())
                    occur[s[i]]=-i;
                }
            }
        priority_queue<pair<pair<int,int>,char> > pq;

        for(auto i:mp)
            {
                pq.push({{i.second,occur[i.first]},i.first});
            }
        unordered_map<char,int> used;
        for(int i=0;i<n;i++)
            {
                if(isvowel(s[i]))
                {
                    int freq=pq.top().first.first;
                    int cha=pq.top().second;

                    while(freq==used[cha])
                    {
                        pq.pop();
                        freq=pq.top().first.first;
                        cha=pq.top().second; 
                        
                    }
                    
                    if(!pq.empty() && used[cha]<freq)
                    {
                        s[i]=cha;
                       used[cha]++;
                    }
                }
            }
        return s;
    }
};