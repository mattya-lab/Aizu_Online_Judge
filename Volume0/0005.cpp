int gcd(int x, int y) { return (x % y == 0) ? y : gcd(y, x % y); }

int main(void) {
	int a, b; cin >> a >> b;
	cout << gcd(a, b) << " " << (a * b) / gcd(a, b) << endl;
	return 0;
}