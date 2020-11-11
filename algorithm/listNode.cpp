#include<iostream>
#include<algorithm>
#include<vector>

#include<iterator>
using std::vector;

void update_bubble(int a[],int size){
    int low=0,high=size-1;
    while(low<high){
        for(auto i=low;i<high;++i){
            if(a[i]>a[i+1]){
                int temp=a[i+1];
                a[i+1]=a[i];
                a[i]=temp;
            }
        }
        --high;
        for(auto i=high;i>low;--i){
            if(a[i-1]>a[i]){
                int temp=a[i-1];
                a[i-1]=a[i];
                a[i]=temp;
            }
        }
        ++low;
    }
    for(auto i=0;i<size;++i)
        std::cout<<a[i]<<" ";
    std::cout<<std::endl;
}

void replaceSpace(char *str,int length){
    if(str==NULL)
        return;
    int countOfBlanks=0;
    int Originallength=0;
    for(int i=0;str[i]!='\0';i++){
        Originallength++;
        if(str[i]==' ')
            ++countOfBlanks;
    }
    int len=Originallength+2*countOfBlanks;
    if(len+1>length)
        return;
    char *pstr1=str+Originallength;
    char *pstr2=str+len;
    while(pstr1<pstr2){
        if(*pstr1==' '){
            *pstr2--='0';
            *pstr2--='2';
            *pstr2--='%';
        }else
            *pstr2--=*pstr1;
        --pstr1;
    }
}

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

//print list node
void printListNode(ListNode *head,vector<int> &vec){
    ListNode *p=head;
    while(p){
        vec.push_back(p->val);
        p=p->next;
    }   
}


//create tree by list
struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
TreeNode *createTreeNode(vector<int> pre,vector<int> in){
    vector<int> left_pre,right_pre,left_in,right_in;
    if(in.size()==0)
        return NULL;
    TreeNode *head=new TreeNode(pre[0]);
    int m=0;
    for(size_t i=0;i<in.size();++i)
        if(in[i]==pre[0]){
            m=i;
            break;
        }
    for(auto i=0;i<m;++i){
        left_pre.push_back(pre[i+1]);
        left_in.push_back(in[i]);
    }

    for(auto i=m+1;i<in.size();++i){
        right_pre.push_back(pre[i]);
        right_in.push_back(in[i]);
    }
    head->left=createTreeNode(left_pre,left_in);
    head->right=createTreeNode(right_pre,right_in);
    return head;
}

//
int minNumberRotate(vector<int> &arr){
    size_t right=arr.size()-1,left=0;
    
    while(left<right){
        size_t m=left+(right-left)/2;
        if(m-1>=0 && arr[m]<arr[m-1]){
            return arr[m];
        }
        if(arr[right]>arr[m])
            right=m;
        else if(arr[right]<arr[m])
            left=m+1;
        else
            right-=1;
    }
}

//
int jumpFloor(int n){
    if(n==0 || n==1)
        return 1;
    if(n==2)
        return 2;
    int sum=0;
    for(auto i=0;i<n;++i)
        sum+=jumpFloor(i);
    return sum;
}

//
int RectCover(){
    int target=10;
    constexpr int x=10;
    int *a=new int[x]{0};
    if(target<3)
        return target;
    a[1]=1;
    a[2]=1;
    for(auto i=3;i<=target;++i)
        a[i]=a[i-1]+a[i-2];
    return a[target];
}
int RectCov(int target){
    if(target<=2)
        return target;
   return RectCov(target-1)+RectCov(target-2);
}

int main(int argv,char **argc){
    int val;
    int a[]={10,2,192,1,191,198,900,1,3,2};
    std::cout<<sizeof(a)<<" "<<sizeof(*a)<<std::endl;
    update_bubble(a,10);
    
    //std::string strs="hello word! happy";
    //std::string c="%20";
    //changeStrs(strs,c);
    //std::string<<strs<<std::endl;
    
    //
    ListNode *head=new ListNode(0);
    ListNode *p=head;
    for(auto i=1;i<12;++i){
        p->next=new ListNode(i);
        p=p->next;
    }
    vector<int> vec;
    printListNode(head,vec);
    for(auto &v:vec)
        std::cout<<v<<" ";
    std::cout<<std::endl;
    delete p,head;
   
    //
    vector<int> prev{3,9,20,15,7},in{9,3,15,20,7};
    TreeNode *treeNode=createTreeNode(prev,in);
    
    vector<int> arr={4,5,6,7,1,2,3,4};
    std::cout<<minNumberRotate(arr)<<std::endl;
    
    int i;
    std::cin>>i;
    std::cout<<"jump:"<<jumpFloor(i)<<std::endl;
    std::cout<<RectCover()<<std::endl;
    
    std::cout<<RectCov(i)<<std::endl;
    return 0;
}
