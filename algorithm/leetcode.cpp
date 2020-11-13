#include<iostream>

#include<vector>
using std::vector;

#include<algorithm>

//leetcode  (time)=n*n!
void MySort(vector<vector<int>> &vec,vector<int> &output,int first,int len){
    if(first==len){
        vec.emplace_back(output);
        return;
    }
    for(auto i=first;i<len;++i){
        std::swap(output[i],output[first]);
        MySort(vec,output,first+1,len);
        std::swap(output[i],output[first]);
    }
}

vector<vector<int>> permute(vector<int> &nums){
    vector<vector<int>> res;
    MySort(res,nums,0,nums.size());
    return res;
}

//47
//vec:save our result;  output:orginal array;   perm: save our sub-result;  vis: save our state
void MySort2(vector<vector<int>> &vec,const vector<int> &output,vector<int> &perm,vector<int> &vis,int first,int len){
    if(first==len){
        vec.emplace_back(perm);
        return;
    }
    for(auto i=0;i<len;++i){
        if(vis[i] || (i>0 && output[i]==output[i-1] && vis[i-1]))
            continue;
        perm.push_back(output[i]);
        vis[i]=1;
        MySort2(vec,output,perm,vis,first+1,len);
        perm.pop_back();
        vis[i]=0;
    }

}
vector<vector<int>> permute2(vector<int> &nums){
    vector<vector<int>> res;
    std::sort(nums.begin(),nums.end(),[](const int &a,const int &b){return a<=b;});
    vector<int> vis(nums.size());
    vector<int> perm;
    MySort2(res,nums,perm,vis,0,nums.size());
    return res;
}

int main(int argv,char **argc){
    int i;
    vector<int> nums;
    while(std::cin>>i){
        if(i<0)
            break;
        nums.push_back(i);
    }
    vector<vector<int>> vec=permute2(nums);
    for(auto v:vec){
        for(auto &vv:v)
            std::cout<<vv<<" ";
        std::cout<<std::endl;
    }
    return 0;
}
