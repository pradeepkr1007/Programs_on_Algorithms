//Greedy- Activity Selection

#include<iostream>
#include<algorithm>
using namespace std;

class Activity{
	public:
		int s;
		int e;
		
		Activity(int s=0, int e=0){
			this->s=s;
			this->e=e;
		}
};

bool mycompare(Activity a, Activity b){
	return a.e<b.e;
}

int main(){
	int n;
	cin>>n;
	Activity a[1000];
	for (int i=0; i<n; i++){
		int e;       //cin>>a[i].s>>a[i].e;
		int s;
		cin>>s>>e;
		Activity A(s,e);
		a[i]=A;
	}
	
	sort(a, a+n, mycompare);
	
	//for (int i=0; i<n; i++){
	//	cout<<a[i].s<<" "<<a[i].e<<endl;
	//}
	
	Activity sol[1000];
	
	sol[0]=a[0];
	int k=1;
	int compare_e=a[0].e;
	
	for (int i=1; i<n; i++){
		if (a[i].s >= compare_e){
			sol[k]=a[i];
			k++;
			compare_e=a[i].e;
		}
	}
	
	cout<<"Can do the following activities: "<<endl;
	for (int i=0; i<k; i++){
		cout<<sol[i].s<<" "<<sol[i].e<<endl;
	}
	cout<<"Number of activities= "<<k;
	return 0;
}
