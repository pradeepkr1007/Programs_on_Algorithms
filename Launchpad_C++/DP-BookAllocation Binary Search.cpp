//Book Pages

#include<iostream>
using namespace std;

bool isValidConfig(int books[], int n, int k, int ans){
	
	int students=1;
	int current_pages=0;
	for (int i=0; i<n; i++){
		if (current_pages+books[i]<=ans)       //Can be given to student
			current_pages+=books[i];
		else{
			current_pages=books[i];
			students++;
			if (students>k){
				return false;
			}
		}
	}
	
	return true;
}


int BookPages(int books[], int n, int k){
	
	int total_pages=0;
	int s=0, e=0;
	int finalans=0;
	
	for (int i=0; i<n; i++){
		total_pages+=books[i];
		s=max(s,books[i]);
	}
	
	e=total_pages;
	
	while(s<=e){
		int mid=(s+e)/2;
		if (isValidConfig(books,n,k,mid)){
			finalans=mid;
			e=mid-1;
		}
		else{
			s=mid+1;
		}
	}
	
	return finalans;
	
}

int main(){
	
	int books[]={10,20,30,40,50};
	cout<<BookPages(books,4,2);
	
	return 0;
}
