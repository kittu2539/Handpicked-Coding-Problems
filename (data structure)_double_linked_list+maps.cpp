#include <bits/stdc++.h>
using namespace std;
class node{
    public:
        int val;
        node *next,*prev;
        node(int val){
            this->val=val;
            next=NULL,prev=NULL;
        }
};
class dlist{
    private:
        node *head,*tail;
        map<int,node*>address;
    public:
        dlist(){
            head=new node(-1);
            tail=new node(-1);
            head->next=tail;
            tail->prev=head;
        }
        void insert(int val,node *cur){
        	if(address.find(val)!=address.end()){
        		return;
        	}
        	node *left = cur->prev;
        	node *right = cur;
        	node *tmp = new node(val);
        	tmp->next=right;
        	tmp->prev=left;
        	right->prev=tmp;
        	left->next=tmp;
        	address[val]=tmp;
        }
        void insert(int val){
        	if(address.find(val)!=address.end()){
        		return;
        	}
        	node *cur = tail;
        	node *left = cur->prev;
        	node *right = cur;
        	node *tmp = new node(val);
        	tmp->next=right;
        	tmp->prev=left;
        	right->prev=tmp;
        	left->next=tmp;
        	address[val]=tmp;
        }
        void remove(node *cur){
        	node *left = cur->prev;
        	node *right = cur->next;
        	left->next=right;
        	right->prev=left;
        	address.erase(cur->val);
        	free(cur);
        }
        void remove(int val){
        	node*cur=address[val];
        	node *left = cur->prev;
        	node *right = cur->next;
        	left->next=right;
        	right->prev=left;
        	address.erase(val);
        	free(cur);
        }
        node* get_node(int val){
        	return address[val];
        }
        void show(){
        	cout<<"dlist = ";
        	node *cur=head->next;
        	while(cur!=NULL && cur!=tail){
        		cout<<cur->val<<" ";
        		cur=cur->next;
        	}cout<<endl;
        }
};

int main(){
	int q = 10;
	class dlist li;
	vector<vector<int>>v = {
		{1,1},{1,2},{1,3},{1,4},{2,1},{1,10},{2,10},{2,2},{1,13},{1,7}
	};
	for(int i=0;i<q;i++){
		int ch=v[i][0],x=v[i][1];
		if(ch==1){
			li.insert(x);
		}else if(ch==2){
			li.remove(x);
		}
		li.show();
	}
	return 0;
}
