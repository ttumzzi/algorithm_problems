#include <iostream>
#include <map>
using namespace std;

struct node {
	int w;
	int h;
};

struct node node_arr[50];
int idx = 0;

bool is_bigger (struct node mine, struct node cmp) {
	if (mine.w < cmp.w && mine.h < cmp.h)
		return true;
	else
		return false;
}

int main() {
	int t, w, h;

	cin >> t;
	while (t--) {
		cin >> w >> h;
		struct node new_node = { w, h };
		node_arr[idx] = new_node;
		idx++;
	}

	for (int i = 0; i < idx; i++) {
		int ord = 1;
		for (int j = 0; j < idx; j++) {
			if (i == j) continue;
			if (is_bigger(node_arr[i], node_arr[j]))
				ord++;
		}
		printf("%d ", ord);
	}
	

}