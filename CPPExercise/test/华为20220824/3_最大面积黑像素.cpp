/**
 某产品使用黑白摄像头采集图像，摄像头采集完每一帧图像后都会输出一个m*n的二维数组，二维数组中的每个元素表示一个像素。元素值1则表示黑色，0则表示白色。要求最多只能改动2个白色像素，使整个图像中互相连通的黑色像素区域面积最大。其中”黑色像素区域面积”是指黑色像素互相连通的个数，“连通”是指任意两个黑色像素水平相邻或垂直相邻。
 
 输入n、m，然后输入一个二维数组。
 1<=n,m<=100
 输出最大的互相联通的黑***域面积

 input:
 4 4
 1 1 0 1
 1 1 0 1
 0 0 0 0
 1 1 1 1

 output:
 12

 intput:
 6 4
 1 1 0 1
 0 0 0 0
 0 0 0 0
 0 0 0 0
 1 1 1 1
 1 1 1 1
 output:
 10
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

static int dirs[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1},
}

int m, n;
vector<vector<int>> matrix;


class UnionFind{
    vector<int> parent;
    vector<int> rank;
public:
    int m, n;
    
    int find(int x){
        return x == parent[x] ? x : find(parent[x]);
    }
    
    void merge(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px == py){
            return ;
        }
        
        if(rank[px] <= rank[py]){
            // 秩小的合到秩大的
            parent[px] = py;
            // 更新大的秩
            rank[py] += rank[px];
        } else {
            parent[py] = px;
            rank[px] += rank[py];
        }
    }
    
    int max_rank(){
        return *max_element(rank.begin(), rank.end());
    }
    
    UnionFind(const vector<vector<int>> & matrix){
        m = matrix.size();
        if(m == 0){
            return;
        }
        n = matrix[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int idx = i * n + j;
                if(matrix[i][j]){
                    parent[idx] = idx;
                    rank[idx] = 1;
                }
            }
        }
        
        queue<int> q;
        vector<bool> visited(m * n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int idx = i * n + j;
                if(visited[idx] || matrix[i][j] == 0){
                    continue;
                }
                q.push(idx);
                while(!q.empty()){
                    int cur = q.front();
                    q.pop();
                    for(auto k: dirs){
                        int i = cur / n;
                        int j = cur % n;
                        int ii = i + k[0];
                        int jj = j + k[0];
                        int idx = ii * n + jj;
                        if(ii >= m || ii < 0 || jj >= n || jj < 0 || visited[idx] || matrix[ii][jj] == 0){
                            continue;
                        }
                        merge(cur, idx);
                        q.push(idx);
                        visited[idx] = true;
                    }
                }
            }
        }
    }

};


int main(){
    cin >> m >> n;
    matrix.resize(m);
    for(int i = 0; i < m; i++){
        matrix[i].resize(n);
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    
    UnionFind uf(matrix);
    
    
}


/*
 //
 //  tmp1.cpp
 //  Test
 //
 //  Created by Baozhu Fang on 2022/8/24.
 //

 #include<iostream>
 #include<vector>
 #include<queue>
 #include<algorithm>
 #include<string.h>
 using namespace std;

 #define N 40000

 static const int dirs[4][2] = {
     {-1, 0},
     {1, 0},
     {0, -1},
     {0, 1},
 };

 class UnionFind{
     int parent[N];
     int rank[N];
 public:
     int n_rows, n_cols;
     UnionFind(const vector<vector<int> > & matrix){
         memset(parent, 0, sizeof(int)*N);
         memset(rank, 0, sizeof(int)*N);
         this->reset(matrix);
     }
     
     UnionFind(const UnionFind& obj){
         copy(obj.parent, obj.parent+N, parent);
         copy(obj.rank, obj.rank+N, rank);
     }
     
     void reset(const vector< vector<int> > & matrix){
         n_rows = matrix.size();
         n_cols = matrix[0].size();
         for(int i = 0; i < n_rows; i++){
             for(int j = 0; j < n_cols; j++){
                 int idx = i * n_cols + j;
                 parent[idx] = idx;
                 rank[idx] = 1;
             }
         }
         
         queue<int> q;
         vector<char> visited(n_cols * n_rows);
         
         for(int i = 0; i < n_rows; i++){
             for(int j = 0; j < n_cols; j++){
                 int idx = i*n_cols + j;
                 if(visited[idx] || matrix[i][j] == 0){
                     continue;
                 }
                 q.push(idx);
                 visited[idx] = true;
                 while(!q.empty()){
                     int curr = q.front();
                     q.pop();
                     for(const auto& dir: dirs){
                         int i = curr / n_cols, j = curr % n_cols;
                         int ii = i+dir[0], jj = j+dir[1];
                         int idx = ii*n_cols + jj;
                         if(ii < 0 || ii >= n_rows || jj < 0 || jj >= n_cols || visited[idx]){
                             continue;;
                         }
                         if(matrix[ii][jj] == 0){
                             continue;
                         }
                         merge(curr, idx);
                         visited[idx] = true;
                         q.push(idx);
                     }
                 }
                 
             }
         }
     }
     
     
     int find(int x){
         return x == parent[x] ? x : (parent[x] = find(parent[x]));
     }
     
     void merge(int x, int y){
         int px = find(x), py = find(y);
         if(px == py){
             return;
         }
         if(rank[px] <= rank[py]){
             parent[px] = py;
             rank[py] += rank[px];
         } else {
             parent[py] = px;
             rank[px] += rank[py];
         }
     }
     
     int get_hightedt_rank() const{
         return *std::max_element(rank, rank+N);
     }

 };

 class Solution{
     int res = 0;
     int depth = 0;
 public:
     int solve(vector<vector<int>> & matrix){
         auto union_find = UnionFind(matrix);
         res = max(res, modify_one(union_find, matrix, 0));
         return res;
     }
     
     int modify_one(UnionFind& union_find, vector<vector<int>> & matrix, int st_idx){
         depth += 1;
         if(depth > 2){
             depth -= 1;
             return 0;
         }
         
         if(matrix.empty() || matrix[0].empty())
             return 0;
         for(int i = 0; i < union_find.n_rows; i++){
             for(int j = 0; j < union_find.n_cols; j++){
                 if(matrix[i][j] == 1){
                     continue;
                 }
                 int idx = i*union_find.n_cols + j;
                 if(idx < st_idx){
                     continue;
                 }
                 UnionFind temp(union_find);
                 matrix[i][j] = 1;
                 int cnt = 0;
                 for(const auto & dir: dirs){
                     int ii = i + dir[0], jj = j + dir[1];
                     if(ii < 0 || ii >= union_find.n_rows || jj < 0 || jj >= union_find.n_cols){
                         continue;
                     }
                     if(matrix[ii][jj] == 0){
                         continue;
                     }
                     int idxx = ii * union_find.n_cols + jj;
                     temp.merge(idx, idxx);
                     cnt++;
                 }
                 
                 if(cnt == 0){ continue;}
                 res = max(res, temp.get_hightedt_rank());
                 res = max(res, modify_one(temp, matrix, idx + 1));
                 matrix[i][j] = 0;
             }
             
         }
         
         depth--;
         return res;
     }
 };


 int main(){
     int m, n;
     cin >> m >> n;
     vector<vector<int> > matrix(m, vector<int> (n));
     for(int i = 0; i < m; i++){
         for(int j = 0; j < n; j++){
                     cin >> matrix[i][j];
         }
     }
     
     cout << Solution().solve(matrix) << endl;
     
     return 0;
 }



 */
