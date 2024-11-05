#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

#define DIGITS 10  // 0부터 9까지 10개의 숫자

using namespace std;

int char_to_index(char c) {
	return c - '0';  // 문자 '0'부터 시작하도록 인덱스를 조정
}

struct Trie {
	bool is_terminal;
	Trie *children[DIGITS];

	Trie() : is_terminal(false) {
		memset(children, 0, sizeof(children));
	}

	~Trie() {
		for (int i = 0; i < DIGITS; i++) {
			if (children[i]) delete children[i];
		}
	}

	bool insert(const string& key, int pos = 0) {
		if (pos == key.size()) {
			// 현재 노드에 이미 다른 번호가 존재하는 경우
			if (is_terminal) return false;
			is_terminal = true;
			return true;
		}

		if (is_terminal) {
			// 현재 노드가 번호의 끝이면 중복이 발생
			return false;
		}

		int index = char_to_index(key[pos]);
		if (children[index] == 0) {
			children[index] = new Trie();
		}
		return children[index]->insert(key, pos + 1);
	}

	Trie* find(const string& key, int pos = 0) {
		if (pos == key.size()) {
			return this;
		}

		int index = char_to_index(key[pos]);
		if (children[index] == 0) {
			return nullptr;
		}

		return children[index]->find(key, pos + 1);
	}

	bool string_exist(const string& key, int pos = 0) {
		if (pos == key.size()) {
			return is_terminal;
		}

		int index = char_to_index(key[pos]);
		if (children[index] == 0) {
			return false;
		}
		return children[index]->string_exist(key, pos + 1);
	}
};

int main() {
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		Trie *root = new Trie();
		int N;
		cin >> N;

		bool is_ok = true;
		vector<string> v;
		for (int i = 0; i < N; i++) {
			string str;
			cin >> str;
			v.push_back(str);
		}

		sort(v.begin(), v.end());

		for (auto val : v) {
			if (!root->insert(val)) {
				is_ok = false;
			}
		}

		if (is_ok) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}

		delete root; // 메모리 해제
	}

	return 0;
}
