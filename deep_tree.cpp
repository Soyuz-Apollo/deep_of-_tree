#include <iostream>
#include <vector>

using namespace std;

int maxDeep (int a, int b){
	if(a >= b){
		return a;
	}else{
		return b;
	}
}


int deepTree(int root ,vector<int> tree){
	int deep = 1;

	//cout <<"вход с корнем:" << root << "\n";
	for(int i = 0; i < tree.size(); i++){
		if(tree[i] == root){
		//	cout << "i: "<< i <<" tree[i] "<< tree[i] <<" root "<< root<< endl;
			deep = maxDeep(deep,(1 + deepTree(i , tree)));	
		}
	}

	return deep;
}


int main(){
	
	int Num , elem , root;
	cin >> Num;
	vector<int> tree;

	for(int i = 0; i < Num; i++){
		cin >> elem;
		//root = (elem == -1)? i:-1;
		if (elem == -1){
			root = i;
		}

		tree.push_back(elem);
	}
	//cout << tree.size() << endl;
	cout << deepTree(root, tree) << "\n";


}