class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](vector<int>& a,vector<int>& b){
            return (a[1]!=b[1])?a[1]<b[1]:a[0]<b[0];
        });
        unordered_map<int,bool> used;       
        
        int count=0;
        for(auto& task:tasks){
            int usedTime=0;
            for(int t=task[0];t<=task[1];t++)   if(used.count(t))   usedTime++;      

            for(int t=task[1];usedTime<task[2];t--){
                if(!used.count(t)){         
                    usedTime++;             
                    used[t]=1;              
                    count++;                
                }
            }
        }
        return count;
    }
};
