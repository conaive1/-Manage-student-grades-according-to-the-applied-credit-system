#include <iostream>

using namespace std;

struct node{
	int before;
	struct node *next;
	int mid;
};

int main(){
	int n=0;
	
	int before, start, mid;
	before = start = mid = n;
	
	while (1){
		cout << "nhap lua chon: 1: ( + )     2: ( - )";
		int m;
		
		node *truoc = new node;
		truoc->next = NULL;
		
		
		cin >> m;
		if(m == 1){
			int i;
			if(before != mid){
				before = mid;
			}
			if(start != mid){
				mid = start;
			}
			for(i = start; i < start + 10; i++){
				cout << i << " ";
			}
			start = i;
			cout << endl;
		}
		else if(m == 2){
			int i;
			for(i = before; i < before + 10; i++){
				cout << i << " ";
			}
			start = mid;
			cout << endl;
		}
		else{
			return 0;
		}
	}
}
