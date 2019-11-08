#include <iostream>
#include <list>
#include <vector>
#include <queue>


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

	/*for(int i = 0; i < tree.size(); i++){
		cout <<" root "<< tree[i].front()<<endl;
		cout <<" childrens ";
		for(list<int>::iterator it = tree[i].begin(); it != tree[i].end(); it++){
			cout << *it <<" ";
		}
		cout << endl;
	}
	 */

	int deep = 1;
	int numV1 = 0;
	int numV2 = 0;
	queue<int> verx;

	for(vector<list<int>> :: iterator flash = tree.begin(); flash < tree.end(); flash++){
		if((*flash).front() == root){
			(*flash).pop_front();
			while(!(*flash).empty()){
				verx.push((*flash).front());
				(*flash).pop_front();
				numV1++;
			}
			tree.erase(flash);
		}
	}

	while(!verx.empty()){
		while(numV1 > 0){
			root = verx.front();
			for (vector<list<int>> :: iterator flash = tree.begin(); flash < tree.end(); flash ++){
				if((*flash).front() == root){
					(*flash).pop_front();
					while(!(*flash).empty()){
						verx.push((*flash).front());
						(*flash).pop_front();
						numV2++;
					}
					tree.erase(flash);
				}
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

