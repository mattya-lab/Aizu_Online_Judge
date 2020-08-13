#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
using p = pair<int, int>;

#define SIZE (31)
#define vecInt vector<int>

class BookInfo {
public:
	char s[SIZE] = " ";
	vecInt index;

	BookInfo(char *ptr, int idx) {
		strcpy(s, ptr);
		index.push_back(idx);
	}
};


int main(void)
{
	vector<BookInfo> b;

	char s[SIZE] = "";
	char* ptr[2];

	rep(z, 8){
		fgets(s, SIZE, stdin); //if (s[0] == '\n') { break; }
		s[strlen(s) - 1] = '\0';
		ptr[0] = strtok(s, " ");
		ptr[1] = strtok(NULL, " "); 

		bool f = true;
		rep(i, b.size()) {
			if (strcmp(b[i].s, s) == 0) {
				b[i].index.push_back(atoi(ptr[1]));
				f = false;
			}
		}
		if (f) { b.push_back(BookInfo(ptr[0], atoi(ptr[1]))); } 
	}
	
	rep(i, b.size() - 1) {
		for (int j = (b.size() - 1); j > i; j--) {
			if (strcmp(b[j - 1].s, b[j].s) > 0) {
				char temp_s[SIZE] = " ";
				strcpy(temp_s, b[j - 1].s);
				strcpy(b[j - 1].s, b[j].s);
				strcpy(b[j].s, temp_s);

				int s = b[j - 1].index.size();
				int t = b[j].index.size();
				vecInt temp_index(s);
				copy(b[j - 1].index.begin(), b[j - 1].index.end(), temp_index.begin());
				b[j - 1].index.resize(t);
				copy(b[j].index.begin(), b[j].index.end(), b[j - 1].index.begin());
				b[j].index.resize(s);
				copy(temp_index.begin(), temp_index.end(), b[j].index.begin());

			}
		}
	}

	rep(i, b.size()) {
		cout << b[i].s << endl;
		sort(b[i].index.begin(), b[i].index.end());
		rep(j, b[i].index.size())
			cout << b[i].index[j] << " ";
		printf("\n");
	}
	
	return 0;
}