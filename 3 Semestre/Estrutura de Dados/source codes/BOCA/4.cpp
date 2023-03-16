#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	
	int q, num;
	
	cin >> q;
    for(int i = 0; i < q; i++){
    	cin >> num;
    	for(int j = 0; j < num; j++){
    		cout << j << endl;
		}
	}

    return 0;
}
