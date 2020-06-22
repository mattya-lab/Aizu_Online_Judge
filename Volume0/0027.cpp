#include<iostream>
using namespace std;

int getmonthmaxday(int month)
{
	switch (month) {
	case 1: return 31;
	case 2: return 29;
	case 3: return 31;
	case 4: return 30;
	case 5: return 31;
	case 6: return 30;
	case 7: return 31;
	case 8: return 31;
	case 9: return 30;
	case 10: return 31;
	case 11: return 30;
	case 12: return 31;
	}
}
int main(void)
{
	const char date[7][10] = {
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday",
		"Sunday"
	};

	while (true) {
		/* 01 / 01 / 2004 */
		int month = 1;
		int day = 1;
		int date_idx = 3;
		int day_max = getmonthmaxday(month);
		int s, t; cin >> s >> t;
		if (s == 0 && t == 0) { break; }

		while (true) 
		{
			if (month >= s && day >= t) { 
				break;
			}

			day = day + 1;
			date_idx = (date_idx + 1) % 7;

			if (day - 1>= day_max) {
				day = 1;
				month = month + 1;
				day_max = getmonthmaxday(month);
			}
		}
		
		cout << date[date_idx] << endl;

	}
	return 0;
}