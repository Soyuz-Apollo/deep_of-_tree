#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

int main(){

	int Num, elem, root;
	
	cin >> Num;

	vector<list<int>> tree(Num);
	vector<list<int>> :: iterator flash;


	for (int i = 0; i < Num; ++i){
		cin >> elem;
		if(elem != -1){
			tree[elem].push_back(i);
		}else{root = i;}

	}



	int deep = 1;
	int numV1 = 0;
	int numV2 = 0;
	queue<int> verx;
	

	while(!(tree[root].empty())){
		verx.push((tree[root]).front());
		tree[root].pop_front();
		numV1++;
	}


	while(!verx.empty()){
		while(numV1 > 0){
			root = verx.front();
			while(!(tree[root].empty())){
				verx.push(tree[root].front());
				tree[root].pop_front();
				numV2++;
			}
			numV1--;
			verx.pop();
		}
		numV1 = numV2;
		numV2 = 0;
		deep++;
	}

cout << deep << endl;


}