#include <algorithm>
const int ALPHABETS = 26;
int toNumber(char ch) { 
	return ch - 'A'; 
} 
struct TrieNode {
	TrieNode* child[ALPHABETS];
	bool terminal;

	TrieNode() : terminal(false) {
		memset(child, NULL, sizeof(child));
	}
	~TrieNode() {
		for (int i = 0; i < ALPHABETS; i++) {
			if (child[i]) delete child[i];
		}
	}

	void insert(const char* key) {
		if (*key == 0) terminal = true;
		else {
			int next = toNumber(*key);
			if (child[next] == NULL) child[next] = new TrieNode();
			child[next]->insert(key + 1);
		}
	}

	TrieNode* find(const char* key) {
		if (*key == 0) return this;
		int next = toNumber(*key);
		if (child[next] == NULL) return NULL;
		return child[next]->find(key + 1);
	}
};