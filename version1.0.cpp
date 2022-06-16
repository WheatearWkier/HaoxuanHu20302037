//version1.0 大概的算法框架 
class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int inf=0x3f3f3f3f;

        vector<vector<int>> edge(n,vector<int>(n,inf));
        int ans=0;
        
        vector<int> dist(n,inf);
        dist[k-1]=0;
        vector<int> used(n,0);
		
		//将边权加入数组中，方便遍历
        for (auto &temp: times){
        }
        

        for (int i=0;i<n;i++){		//Dijkstra算法 
    	}
    	
    }
};
