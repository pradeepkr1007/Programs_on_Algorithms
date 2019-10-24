#include<iostream>
#include<unordered_map>

using namespace std;

class node{
	
	public:
	char data;
	unordered_map < char, node* > m;
	bool isTerminal;
	
	node(char d){
		data=d;
		isTerminal=false;
	}
	
};

class Trie{
	
	node* root;
	
	public:
		
		Trie(){
			root=new node('\0');
		}
		
		void addWord(char *word){
			node* temp=root;
			for (int i=0; word[i]!='\0'; i++){
				char ch=word[i];
				
				if (temp->m.count(ch)){           //Count function returns 1 if ch exists in m hash map and 0 of not.
					node* child=new node(ch);
					temp->m[ch]=child;            //temp-> m = hash map of node temp. m[ch] = value bucket of ch character 
				}
				else{
					temp=temp->m[ch];
				}
		
			}
			
			temp->isTerminal=true;
			
		}
		
		bool isPresent(char *word){
			node* temp=root;
			
			for(int i=0; word[i]!='\0'; i++){
				char ch=word[i];
				
				if (temp->m.count(ch)){
					temp=temp->m[ch];
				}
				
				else{
					return false;
				}
			}
			
			return temp->isTerminal;
		}
		
};

int main(){
	
	Trie t;
	
	t.addWord("Apple");
	t.addWord("Ape");
	t.addWord("Not");
	t.addWord("News");
	
	char ch[100];
	while (1){
		cin>>ch;
		if (t.isPresent(ch)){
			cout<<"Exists"<<endl;
		}
		else{
			cout<<"Doesn't exist"<<endl;
		}
	}
	
	return 0;
}
