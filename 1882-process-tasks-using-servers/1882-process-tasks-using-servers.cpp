#define ll long long
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        
         int n = servers.size();
         int m = tasks.size();

         queue<int>tasks_order;
         priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>free;

         priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>not_free;

         for(int i = 0; i< n; i++){

               free.push({servers[i], i});
         }

         vector<int>ans(m);

         for(int j = 0; j < m;){

               ll time = j;

               while(!not_free.empty() && not_free.top().first <= time){

                     int idx = not_free.top().second;

                     not_free.pop();

                     free.push({servers[idx], idx});
               }

               if(free.empty()){

                     time = not_free.top().first;

                     while(!not_free.empty() && not_free.top().first <= time){

                     int idx = not_free.top().second;

                     not_free.pop();

                     free.push({servers[idx], idx});
                    }
               }

                   while(j <= min(1LL*m -1 , time) && !free.empty()){

                    int idx_assigned_server = free.top().second;

                    ans[j] = idx_assigned_server;

                    not_free.push({(ll)time + tasks[j], idx_assigned_server});

                    free.pop();

                    j++;

                   }
         }

         return ans;
    }
};