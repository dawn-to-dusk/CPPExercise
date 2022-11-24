/**
 英文浏览器直接翻译：
 我们有两个数组A和B，每个数组由N个整数组成。我们想将它们合并到数组C中。对
 于每个索引K(从0到N-1)，C[K] 可以是A[K]或B[K]。
 例如，数组A=
 [1,2,4,3]和B=[1,3,2,3]可以通过以下方式合并:
 我们的目标是获得一个数组C，使得C中不存在的最小正整数尽可能小。
 在上面的例子中，我们可以创建C=[13 3,4,3] 并且结果是 2，因为从C中排除的最小正整数是2.
 写一个函数:
 整数解(向量<int> &A，向量<int> &B)
 例子:数，该整数是通过分别从数组A或B中选择元素创建的。即，给定两个长度为 N 的整数数组A和 B，返回数组C中未出现的最小可能正整
 1.给定A=[1,2,4,3] 和 B=[1,3,2,3]，您的函数应该返回 2，如上所述。
 2.给定A= [3,2, 1, 6,5] 和 B =[4,2,1,3,3]，你的函数应该返回 3。我们可以创建C = [4, 2, 1, 6 , 5]。
 3.给定A=[1,2] 和B=[1,2]，你的函数应该返回 3。我们可以创建 C = [1,2]。
 */

/**
 5
 3 2 1 6 5
 4 2 1 3 3
 
 3
 
 
 4
 1 2 4 3
 1 3 2 3
 
 2
 
 
 2
 1 2
 1 2
 
 3
 */

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;


int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    vector<int> nums;
    for(int i = 0; i < A.size(); i++){
        nums.push_back(max(A[i], B[i]));
    }
    
    sort(nums.begin(), nums.end());
    int min = 1;
    for(int i = 0; i < nums.size(); i++){
        if(min == nums[i]){
            min++;
        }
    }
    
    return min;
}

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < N; i++){
        cin >> B[i];
    }
    
    cout << solution(A, B) << endl;
    return 0;
}

