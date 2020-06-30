#include<iostream>
using namespace std;

int main(void)
{
	for (int z = 0; z < 4; z++) {
		double a; cin >> a;
		if (a <= 48.00) printf("light fly\n");
		else if (48.00 < a && a <= 51.00) printf("fly\n");
		else if (51.00 < a && a <= 54.00) printf("bantam\n");
		else if (54.00 < a && a <= 57.00) printf("feather\n");
		else if (57.00 < a && a <= 60.00) printf("light\n");
		else if (60.00 < a && a <= 64.00) printf("llight welter\n");
		else if (64.00 < a && a <= 69.00) printf("welter\n");
		else if (69.00 < a && a <= 75.00) printf("light middle\n");
		else if (75.00 < a && a <= 81.00) printf("middle\n");
		else if (81.00 < a && a <= 91.00) printf("light heavy\n");
		else printf("heavy\n");
	} 
	return 0;
}