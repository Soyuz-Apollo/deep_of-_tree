#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(){
	
	int Num, elem, root;
	bool flag = true;
	vector<list<int>> tree;
	list <int> essen;
	cin >> Num;

	for(int i = 0; i < Num; i++){
		cin >> elem;
		
		if (elem == -1){
			flag = false;
			root = i;
		}else{
			for(int j = 0 ; j < tree.size(); j++){
				if(tree[j].front() == elem){
					flag = false;
					tree[j].push_back(i);
				}
			}
		}

		if(flag){
			essen.push_back(elem);
			essen.push_back(i);
			tree.push_back(essen);
			essen.clear();

		}

		flag = true;
	}

	for(int i = 0; i < tree.size(); i++){
		cout <<" root "<< tree[i].front()<<endl;
		cout <<" childrens ";
		for(list<int>::iterator it = tree[i].begin()+1; it != tree[i].end(); it++){
			cout << *it <<" ";
		}
		cout << endl;
	}
}