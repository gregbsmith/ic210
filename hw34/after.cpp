/* Gregory Smith
 */

#include <cstring> // for strcmp
#include <iostream> // cin, cout
#include <fstream> // ifstream
using namespace std;

struct Node {
	char data[128];
	struct Node* next;
};

Node* add2front(char* c, Node* L);

void dealloc(Node* lst);

int main() {
	//propmt for filename and open file
	cout << "filename: ";
	char fname[128];
	cin >> fname;

	ifstream fin;
	fin.open(fname);

	Node* L = NULL;
	char temp[128];

	while(fin >> temp) {
		//cin >> temp;
		L = add2front(temp, L);
		//cin >> "\n";
	}

	fin.close();
	char search_word[128];
	cout << "search for: ";
	cin >> search_word;
	int words_after = 0;
	Node* cur = L;
	while(cur != NULL) {
		if ( strcmp(search_word, cur->data) < 0 ) {
			words_after++;
		}
		cur = cur->next;
	}
	dealloc(cur);
	dealloc(L);

	cout << "There are ";
	cout << words_after;
	cout << " words after ";
	cout << search_word;
	cout << " in ";
	cout << fname;
	cout << "\n";
}

Node* add2front(char* c, Node* L) {
	Node* temp = new Node;
	strcpy(temp->data, c);
	temp->next = L;
	return temp;
}

void dealloc(Node* lst) {
	if(lst) {
		dealloc(lst->next);
		delete lst;
	}
}
