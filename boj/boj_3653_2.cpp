#include <iostream>
#include <string>
using namespace std;

struct record storage;

struct record{
	int idx;
	int num_above;
	struct record* above;
	struct record* below;
};

void init_record(int n){
	
}

int main() {
	int case_num, n, m;
	string book_idx;
	string result = "";
	cin >> case_num;

	for (int i = 0; i < case_num; i++) {
		cin >> n; // num of movies owned
		cin >> m; // num of movies to see
		init_storage(n);

		for (int j = 0; j < m; j++) {
			cin >> book_idx;
			result.append(to_string(get_movie_num_above(book_idx)));
			result.append(" ");
		}
		result.append("\n");
	}
	cout << result;
}