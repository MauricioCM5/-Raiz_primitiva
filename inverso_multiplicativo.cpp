// Mauricio Colque Morales
#include<iostream>
using namespace std;

//Variables del algoritmo de euclides extendido
int x_p = 0, y_p = 0;
int x = 0, y = 0;
int gcd = 0;
int d = 0;

int euclides_extendido(int a, int b) {
	if (a % b == 0) {
		x_p = 0; y_p = 1;
		return b;
	}

	d = euclides_extendido(b, a % b);

	x = y_p;
	y = x_p - int(a / b) * y_p;
	x_p = x;
	y_p = y;
	return d;
}


int inverso(int a, int n) {
	if (euclides_extendido(a, n) == 1) return (x_p % n);
	return -1;
}

int main() {

	int a, n, res;
	cout << "INVERSO MULTIPLICATIVO\n";
	while (true)
	{
		cout << "Ingrese a: "; cin >> a;
		cout << "Ingrese n: "; cin >> n;
		res = inverso(a, n);
		if (res == -1) cout << "a no tiene inverso multiplicativo modulo n\n";
		else {
			cout << "El inverso multiplicativo es: ";
			if (res < 0) res += n;
			cout << res << "\n";
		}
	}

	return 0;
}


