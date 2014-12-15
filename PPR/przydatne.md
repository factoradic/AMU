
bool isSubstr(std::string child, std::string parent) {
    return parent.find(child) != std::string::npos;
}

bool isPalindrome(std::string s) {
	std::string rev = std::string(s.rbegin(), s.rend());
	return s == rev;
}

int NWD(int array[], int length) {
    int result = array[0];
    for(int i = 1; i < length; i++) {
        result = NWD(result, array[i]);
    }
    return result;
}

int NWD(int a, int b) {
	int c;
	while(b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

float avg_grades() {
    int s = 0;
	for(int i = 0; i < counter; i++) {
	   s += T[i];
    }
	return (float)s / counter;
}

int sumSubarray(int T[], int x, int y) {
    int result = 0;
    for(int i = x - 1; i < y; i++) {
        result += T[i];
    }
    return result;
}

void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}