#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
	
	//float num; //adiciona 123456.51 como 123456.509...
    double num; //com double n acontece

    cin >> num;
    while(num != 0){
    	cout << num; //arredonda 123456.51
	    cout << endl;
	    printf("%f",num);
	    
	    cin >> num;
	}
    
    return 0;
}
