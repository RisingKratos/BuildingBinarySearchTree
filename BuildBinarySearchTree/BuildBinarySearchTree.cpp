#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define inf 2000000000
using namespace std;

int parent[6000001];
int key[6000001];
int leftchild[6000001];
int rightchild[6000001];
int a[6000001];

int n, root, cnt, height;

void Insert(int value, int it = root, int depth = 1) {
	if (!root) 
	{
		cnt++;
		root = cnt;
		key[root] = value;
		height = max(height, depth);
		return;
	}
	if (value < key[it]) 
	{
		if (!leftchild[it]) 
		{
			cnt++;
			leftchild[it] = cnt;
			key[leftchild[it]] = value;
			parent[leftchild[it]] = it;
			height = max(height, depth + 1);
		}
		else 
		{
			Insert(value, leftchild[it], depth + 1);
		}
	}
	if (value >= key[it]) 
	{
		if (!rightchild[it]) 
		{
			cnt++;
			rightchild[it] = cnt;
			key[rightchild[it]] = value;
			parent[rightchild[it]] = it;
			height = max(height, depth + 1);
		}
		else {
			Insert(value, rightchild[it], depth + 1);
		}
	}
}

int main() 
{
	int input;
	srand(time(NULL));
	cin >> input;	//575000
	for (int t = 1; t <= 20; ++t) 
	{
		n = input * t;

		root = cnt = height = 0;
		for (int i = 1; i <= 6000000; ++i)
		{
			parent[i] = 0;
			key[i] = 0;
			leftchild[i] = 0;
			rightchild[i] = 0;
		}

		cout << t << ". " << n << endl;

		for (int i = 1; i <= n; i++)
		{
			a[i] = rand() % inf + 1;
		}

		clock_t time;
		time = clock();
		for (int i = 1; i <= n; ++i) 
		{
			Insert(a[i]);
		}
			
		time = clock() - time;

		cout << (double)(time/(CLOCKS_PER_SEC)) << endl;

		cout << "Height: " << height << endl;

	}

	return 0;
}