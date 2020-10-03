#include <iostream>
#include <sstream>

struct entry {
	std::string data;
	int value;
	entry * next;
};

unsigned int hash(std::string s, int hash_size) {
	unsigned long hash = 5381;
	for (int i = 0; i < s.length(); ++i) {
		int c = s[i];
		hash = (hash << 5) + hash + c;
	}
	return hash % hash_size;
}

void hash_insert(entry ** hash_table, const size_t hash_size, const std::string word) {
	unsigned int hash_val = hash(word, hash_size);
	entry *& hlist = hash_table[hash_val];
	if (hlist) {
		// find where to put it
		while (hlist->next && hlist->next->data <= hlist->data)
			hlist = hlist->next;

		if (hlist->data == word) {
			hlist->value += 1;
		}
		else {
			entry * next_node = hlist->next;
			hlist->next = new entry;
			hlist->next->data = word;
			hlist->next->next = next_node;
			hlist->next->value = 1;
		}
	}
	else {
		hlist = new entry;
		hlist->next = NULL;
		hlist->data = word;
		hlist->value = 1;
	}
}

int main() {

	const size_t const_hash_size = 255;

	std::string s = "the quick brown fox jumped over the lazy dog";

	// create the hash table
	entry * hash_table[const_hash_size];
	for (int i = 0; i < const_hash_size; ++i)
		hash_table[i] = NULL;

	// insert into the hash table
	std::string word;
	std::stringstream ss(s);
	while (ss >> word) {
		hash_insert(hash_table, const_hash_size, word);
	}

	// print out contents of histogram
	// and delete it along the way.
	for (int i = 0; i < const_hash_size; ++i) {
		if (hash_table[i]) {
			entry * hlist = hash_table[i];
			while (hlist) {
				entry * p = hlist;
				std::cout << p->data << " " << p->value << std::endl;
				hlist = p->next;
				delete p;
			}
		}
	}

	return 0;
}