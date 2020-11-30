/* Gregory Smith
 */

#include <cstring> // for strcmp
#include <iostream> // cin, cout
#include <fstream> // ifstream
using namespace std;

int main() {
	//propmt for filename and open file
	cout << "filename: ";
	char fname[128];
	cin >> fname;
	
	ifstream fin;
	fin.open(fname);
	
	
}
