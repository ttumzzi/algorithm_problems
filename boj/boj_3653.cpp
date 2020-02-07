#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> s;

void init_storage(int n) {
	s.clear();
	for (int i = n; i > 0; i--)
		s[to_string(i)] = i - 1;
}

int get_movie_num_above(string movie_idx) {
	int num_above = s[movie_idx];
	for (auto it = begin(s); it != end(s); it++) {
		if (it->first == movie_idx)
			break;
		it->second++;
	}
	s[movie_idx] = 0;

	return num_above;
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