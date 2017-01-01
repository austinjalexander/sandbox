#include <iostream>

using namespace std;

double add(int m, int n) {
	return m + n;
}
double mult(int m, int n) {
	return m * n;
}
double sub(int m, int n) {
	return m - n;
}
double div(int m, int n) {
	return m / n;
}

void operation(int a, int b, int c, int d) {
	if (add(a,b) + add(c,d) == 24) {cout << "1";}
	if (add(a,b) - add(c,d) == 24) {cout << "1";}
	if (add(a,b) * add(c,d) == 24) {cout << "1";}
	if (add(a,b) / add(c,d) == 24) {cout << "1";}

	if (mult(a,b) + mult(c,d) == 24) {cout << "2";}
	if (mult(a,b) - mult(c,d) == 24) {cout << "2";}
	if (mult(a,b) * mult(c,d) == 24) {cout << "2";}
	if (mult(a,b) / mult(c,d) == 24) {cout << "2";}

	//////

	if (add(a,b) + mult(c,d) == 24) {cout << "3";}
	if (add(a,b) - mult(c,d) == 24) {cout << "3";}
	if (add(a,b) * mult(c,d) == 24) {cout << "3";}
	if (add(a,b) / mult(c,d) == 24) {cout << "3";}

	if (mult(a,b) + add(c,d) == 24) {cout << "4";}
	if (mult(a,b) - add(c,d) == 24) {cout << "4";}
	if (mult(a,b) * add(c,d) == 24) {cout << "4";}
	if (mult(a,b) / add(c,d) == 24) {cout << "4";}

	//////

	if (sub(a,b) + sub(c,d) == 24) {cout << "5";}
	if (sub(a,b) - sub(c,d) == 24) {cout << "5";}
	if (sub(a,b) * sub(c,d) == 24) {cout << "5";}
	if (sub(a,b) / sub(c,d) == 24) {cout << "5";}

	if (add(a,b) + sub(c,d) == 24) {cout << "6";}
	if (add(a,b) - sub(c,d) == 24) {cout << "6";}
	if (add(a,b) * sub(c,d) == 24) {cout << "6";}
	if (add(a,b) / sub(c,d) == 24) {cout << "6";}

	if (sub(a,b) + add(c,d) == 24) {cout << "7";}
	if (sub(a,b) - add(c,d) == 24) {cout << "7";}
	if (sub(a,b) * add(c,d) == 24) {cout << "7";}
	if (sub(a,b) / add(c,d) == 24) {cout << "7";}

	if (sub(a,b) + mult(c,d) == 24) {cout << "8";}
	if (sub(a,b) - mult(c,d) == 24) {cout << "8";}
	if (sub(a,b) * mult(c,d) == 24) {cout << "8";}
	if (sub(a,b) / mult(c,d) == 24) {cout << "8";}

	if (mult(a,b) + sub(c,d) == 24) {cout << "9";}
	if (mult(a,b) - sub(c,d) == 24) {cout << "9";}
	if (mult(a,b) * sub(c,d) == 24) {cout << "9";}
	if (mult(a,b) / sub(c,d) == 24) {cout << "9";}

	/////

	if (div(a,b) + div(c,d) == 24) {cout << "10";}
	if (div(a,b) - div(c,d) == 24) {cout << "10";}
	if (div(a,b) * div(c,d) == 24) {cout << "10";}
	if (div(a,b) / div(c,d) == 24) {cout << "10";}

	if (add(a,b) + div(c,d) == 24) {cout << "11";}
	if (add(a,b) - div(c,d) == 24) {cout << "11";}
	if (add(a,b) * div(c,d) == 24) {cout << "11";}
	if (add(a,b) / div(c,d) == 24) {cout << "11";}

	if (div(a,b) + add(c,d) == 24) {cout << "12";}
	if (div(a,b) - add(c,d) == 24) {cout << "12";}
	if (div(a,b) * add(c,d) == 24) {cout << "12";}
	if (div(a,b) / add(c,d) == 24) {cout << "12";}

	if (div(a,b) + mult(c,d) == 24) {
			cout << a << " " << b << " " << c << " " << d << endl;
			cout << "13.1" << endl << endl;
}
	if (div(a,b) - mult(c,d) == 24) {
			cout << a << " " << b << " " << c << " " << d << endl;
			cout << "13.2" << endl << endl;
}
	if (div(a,b) * mult(c,d) == 24) {
			cout << a << " " << b << " " << c << " " << d << endl;
			cout << "13.3" << endl << endl;
}
	if (div(a,b) / mult(c,d) == 24) {
			cout << a << " " << b << " " << c << " " << d << endl;
			cout << "13.4" << endl << endl;
}

	if (mult(a,b) + div(c,d) == 24) {
			cout << a << " " << b << " " << c << " " << d << endl;
			cout << "14.1" << endl << endl;
}
	if (mult(a,b) - div(c,d) == 24) {
			cout << a << " " << b << " " << c << " " << d << endl;
			cout << "14.2" << endl << endl;
}
	if (mult(a,b) * div(c,d) == 24) {
			cout << a << " " << b << " " << c << " " << d << endl;
			cout << "14.3" << endl << endl;
}
	if (mult(a,b) / div(c,d) == 24) {
			cout << a << " " << b << " " << c << " " << d << endl;
			cout << "14.4" << endl << endl;
}

	if (div(a,b) + sub(c,d) == 24) {cout << "15";}
	if (div(a,b) - sub(c,d) == 24) {cout << "15";}
	if (div(a,b) * sub(c,d) == 24) {cout << "15";}
	if (div(a,b) / sub(c,d) == 24) {cout << "15";}

	if (sub(a,b) + div(c,d) == 24) {cout << "16";}
	if (sub(a,b) - div(c,d) == 24) {cout << "16";}
	if (sub(a,b) * div(c,d) == 24) {cout << "16";}
	if (sub(a,b) / div(c,d) == 24) {cout << "16";}

}

void go(int a, int b, int c, int d) {
	operation(a,b,c,d);
	operation(a,c,d,b);
	operation(a,d,b,c);

	operation(b,c,d,a);
	operation(b,d,a,c);
	operation(b,a,c,d);

	operation(c,d,a,b);
	operation(c,a,b,d);
	operation(c,b,d,a);

	operation(d,a,b,c);
	operation(d,b,c,a);
	operation(d,c,a,b);
}


int main() {


	int a = 1, b = 3, c = 4, d = 6;

	go(a, b, c, d);

	a = 3, b = 4, c = 6, d = 1;

	go(a, b, c, d);

	a = 4, b = 6, c = 1, d = 3;

	go(a, b, c, d);
	
	a = 6, b = 1, c = 3, d = 4;

	go(a, b, c, d);




	return 0;
}