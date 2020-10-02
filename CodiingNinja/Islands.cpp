#include<queue>

//BFS
void BFS(int **adj,int n,bool*filled,int sv){
    queue<int>q;
    q.push(sv);
    while(q.size()!=0){
        int val=q.front();
        q.pop();
        filled[val]=true;
        for(int i=0;i<n+1;i++){
            if(adj[val][i]==1 && filled[i]==false){
                q.push(i);
            }
        }
    }
    return;
}
int solve(int n,int m,vector<int>u,vector<int>v)
{
	
    //n =no of vetices 
    // m= no of edges
    //creation **adjaceny matrix**
    
    
    
    int **adj=new int*[n+1];
    for(int i=0;i<n+1;i++){
        adj[i]=new int[n+1];
        for(int j=0;j<n+1;j++){
            adj[i][j]=0;
        }
    }
    //Getting  input
    for(int i=0;i<m;i++){
      adj[v[i]][u[i]] =1;
       adj[u[i]][v[i]] =1;
        
    }
    //Filled array to check which nodes has entered
    bool*filled=new bool[n+1];
    for(int i=0;i<n+1;i++){
        filled[i]=false;
    }
    int start=0;
    int count=0;
    while(start<n+1){
        if(filled[start]==true){
            start++;
            continue;}
        BFS(adj,n,filled,start);
        start++;
        count++;
    }
    return count-1;
    
}
