#include <iostream>
#include <unistd.h>
using namespace std;

int main(){
	cout << "Page size: " << getpagesize();
	return 0;
}
