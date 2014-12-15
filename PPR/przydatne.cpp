/*
Funkcja isSubst zwraca true jezeli string child zawiera sie w stringu parent.
W przeciwnym wypadku zwraca false.
*/
bool isSubstr(std::string child, std::string parent) {
    return parent.find(child) != std::string::npos;
}

/*
Funkcja isPalindrome zwraca true jezeli string s jest palindromem.
*/
bool isPalindrome(std::string s) {
	std::string rev = std::string(s.rbegin(), s.rend());
	return s == rev;
}

/*
Funkcja NWD zwraca najwiekszy wspolny dzielnik dwoch liczb lub calej tablicy liczb.
*/
int NWD(int a, int b) {
	int c;
	while(b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int NWD(int array[], int length) {
    int result = array[0];
    for(int i = 1; i < length; i++) {
        result = NWD(result, array[i]);
    }
    return result;
}

/*
Funkcja average zwraca srednia arytmetyczna wartosci liczb calkowitych znajdujacych sie
w tablicy array o dlugosci length.
*/
float average(int array[], int length) {
    int s = 0;
	for(int i = 0; i < length; i++) {
	   s += array[i];
    }
	return (float)s / length;
}

/*
Funkcja sumSubarray zwraca sume wszystkich elementow tablicy array znajdujacych sie w indeksach od x do y (wlacznie).
*/
int sumSubarray(int array[], int x, int y) {
    int result = 0;
    for(int i = x - 1; i < y; i++) {
        result += array[i];
    }
    return result;
}

/*
Funkcja swap przypisuje zmiennej x wartosc zmiennej y, a zmiennej y wartosc zmiennej x.
*/
void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}