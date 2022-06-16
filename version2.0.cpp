//version2.0 基本的实现，但还有冗余的地方 
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
  			int x=temp[0]-1, y=temp[1]-1;
            edge[x][y]=temp[2];	
        }
        

        for (int i=0;i<n;i++){		//Dijkstra算法 
       		int x=-1;
            for (int y=0;y<n;y++){
                if (!used[y]){
					if (x == -1 || dist[y]<dist[x]){		//找到目前的最小距离点 
                    	x=y;
                	}
				}
            }
        
            used[x]=1;
            ans=max(ans,dist[x]);

            for (int y=0;y<n;y++){		//收缩边 
                dist[y]=min(dist[y],dist[x]+edge[x][y]);
	   		}
    	}
    	
    	if (ans == inf){
    		return -1;
		}
		else{
			return ans;
		}
    }
};
