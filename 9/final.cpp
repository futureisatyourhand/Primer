#include<iostream>

#include<stack>
using std::stack;

#include<vector>
using std::vector;

#include<string>
using std::string;

#include<queue>
using std::queue;
using std::priority_queue;

#include<deque>
using std::deque;

#include<list>
using std::list;
int priority(const string &opt){
    int p=0;
    if(opt=="+" || opt=="-")
        p=1;
    if(opt=="*" || opt=="/")
        p=2;
    if(opt=="(")
        p=0;
    return p;
}

vector<string> Expre(vector<string> &vec){
    stack<string> stack_opt;
    vector<string> vec2;
    for(auto i=0;i!=vec.size();++i){
        string token=vec[i];
        if(token=="+" || token=="-" || token=="*" || token=="/"){
            if(stack_opt.size()==0)
                stack_opt.push(token);
            else{
                int token_p=priority(token);
                string top_opt=stack_opt.top();
                int opt_p=priority(top_opt);
                if(token_p>opt_p)
                    stack_opt.push(token);
                else{
                    while(token_p<=opt_p){
                        vec2.push_back(top_opt);
                        stack_opt.pop();
                        if(stack_opt.size()!=0){
                            top_opt=stack_opt.top();
                            opt_p=priority(top_opt);
                        }else
                            break;
                    }
                    stack_opt.push(token);
                }
            }
        }else if(token=="(")
            stack_opt.push(token);
        else if(token==")"){
            while(stack_opt.top()!="("){
                string top_opt=stack_opt.top();
                vec2.push_back(top_opt);
                stack_opt.pop();
            }
            stack_opt.pop();
        }else{
            vec2.push_back(token);
        }
    }
    while(stack_opt.size()!=0){
        string top_opt=stack_opt.top();
        vec2.push_back(top_opt);
        stack_opt.pop();
    }
    return vec2;
}

int cal(stack<int> &stack_opd,const string &opt){
    if(opt=="+"){
        int ropd=stack_opd.top();
        stack_opd.pop();
        int lopd=stack_opd.top();
        stack_opd.pop();
        int result=lopd+ropd;
        stack_opd.push(result);
    }
    if(opt=="-"){
        int ropd=stack_opd.top();
        stack_opd.pop();
        int lopd=stack_opd.top();
        stack_opd.pop();
        int result=lopd-ropd;
        stack_opd.push(result);
    }
    if(opt=="*"){
        int ropd=stack_opd.top();
        stack_opd.pop();
        int lopd=stack_opd.top();
        stack_opd.pop();
        int result=ropd*lopd;
        stack_opd.push(result);
    }
    if(opt=="/"){
        int ropd=stack_opd.top();
        stack_opd.pop();
        int lopd=stack_opd.top();
        stack_opd.pop();
        int result=lopd/ropd;
        stack_opd.push(result);
    }
}

int cal_Exp(vector<string> &vec){
    stack<int> stack_opd;
    for(auto token:vec){
        //string token=vec[i];
        if(token=="+" || token=="-" || token=="*" || token=="/")
            cal(stack_opd,token);
        else
            stack_opd.push(atoi(token.c_str()));
    }
    return stack_opd.top();
}

int main(int argv,char **argc){
    vector<string> v1={"(","1","+","2",")","*","4","/","(","1","+","1",")"};
    for(auto &v:v1)
        std::cout<<v<<"  ";
    std::cout<<std::endl;

    vector<string> v2=Expre(v1);
    for(auto &v:v2)
        std::cout<<v<<" ";
    std::cout<<std::endl;

    std::cout<<"result:"<<cal_Exp(v2)<<std::endl;

    priority_queue<int> q;
    for(int i=1;i<10;++i)
        q.push(i);

    deque<int>di(5,5);
    list<int> li(5,5);
    queue<int> q1(di);//right
    //queue<int> q2(li); //error queue based on deque not list;
    std::cout<<"queue top:"<<q.top()<<" || queue front"<<std::endl;
    return 0;
}
