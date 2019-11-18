#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<map>
using namespace std;

stack<int> st;
queue<int> q;
vector<int> v;
set<string> s;

map<string, int> name_num;

int main(){
    
    string mode;
    cout<<"enter the mode: "<<endl;
    cin >> mode;

    if(mode == "stack"){
        cout<<"enter the number of items"<<endl;
        int lines;
        cin >> lines;
        for(int i = 0; i < lines; i++){
            int item;
            cin>>item;
            st.push(item);
        }
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
    }else if(mode == "queue"){
        cout<<"enter the number of items in queue"<<endl;
        int lines;
        cin>> lines;
        for(int i = 0; i < lines; i ++){
            int item;
            cin>>item;
            q.push(item);
        }
        while(!q.empty()){
            cout<<q.front()<<" ";
            q.pop();
        }
    }else if(mode == "map"){
        cout<<"enter the number of items in map\n";
        int item_num;
        cin>>item_num;
        for(int i = 0; i < item_num; i++){
            int id;
            cout<<"enter the name and id: "<< endl;
            string name;
            cin>>name>>id;
            name_num.insert(make_pair(name, id));
            cout<<endl;
        }
        for(map<string, int>::iterator it = name_num.begin(); it != name_num.end(); it++){
            cout<<it->first<<": "<<it->second<<endl;
        }
    
    }else
        cout<<"wrong command"<<endl;
    cout<<endl;
return 0;
}
