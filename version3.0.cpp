//version3.0 �Դ��������ϸ΢���Ż����ӿ��ٶ� 
class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int inf=INT_MAX / 2;

        vector<vector<int>> edge(n,vector<int>(n,inf));
        int ans=0;

        for (auto &temp: times){
            int x=temp[0]-1, y=temp[1]-1;
            edge[x][y]=temp[2];		//����Ȩ���������У�������� 
        }
        

        vector<int> dist(n,inf);
        dist[k-1]=0;
        vector<int> used(n,0);

        for (int i=0;i<n;i++){		//Dijkstra�㷨 
            int x=-1;
            for (int y=0;y<n;y++){
                if (!used[y] && (x==-1 || dist[y]<dist[x])){		//�ҵ�Ŀǰ����С����� 
                    x=y;
                }
            }
            used[x]=1;
            ans=max(ans,dist[x]);

            for (int y=0;y<n;y++){			//������ 
                dist[y]=min(dist[y],dist[x]+edge[x][y]);
            }
        }
        return ans==inf ? -1 :ans;
    }
};
