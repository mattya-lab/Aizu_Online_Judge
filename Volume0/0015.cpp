#include<iostream>
#include<string.h>

int main(void)
{
	int n = 1;  (void)scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char s1[100 + 1] = ""; (void)scanf("%s", s1);
		char s2[100 + 1] = ""; (void)scanf("%s", s2);
		char s3[100 + 1] = "";

		if (strlen(s1) > 80 || strlen(s2) > 80) {
			printf("overflow\n");  continue;
		}
		else if (strcmp(s1, "0") == 0) {
			strcpy(s3, s2);
		}
		else if (strcmp(s2, "0") == 0) {
			strcpy(s3, s1);
		}
		else {
			char rs1[100 + 1] = "", rs2[100 + 1] = "";
			for (int i = 0; i < strlen(s1); i++) { rs1[i] = s1[strlen(s1) - 1 - i]; }
			for (int i = 0; i < strlen(s2); i++) { rs2[i] = s2[strlen(s2) - 1 - i]; }

			int rs1_idx = 0, rs2_idx = 0, flag = 0, val = 0;;
			char rs3[100 + 1] = "";
			for (int i = 0; i < 100; i++) {
				if (rs1_idx == strlen(rs1)) { val = (rs2[rs2_idx] - '0') + flag; }
				else if (rs2_idx == strlen(rs2)) { val = (rs1[rs1_idx] - '0') + flag; }
				else { val = (rs1[rs1_idx] - '0') + (rs2[rs2_idx] - '0') + flag; }

				if (val >= 10) { flag = 1; val = val % 10; }
				else { flag = 0; }
				rs3[i] = val + '0';

				if (rs1_idx < strlen(rs1)) { rs1_idx++; }
				if (rs2_idx < strlen(rs2)) { rs2_idx++; }
				if (rs1_idx == strlen(rs1) && rs2_idx == strlen(rs2)) { 
					if (flag == 1) { rs3[i + 1] = 1 + '0'; }
					break; 
				}
			}
			for (int i = 0; i < strlen(rs3); i++) {
				s3[i] = rs3[strlen(rs3) - 1 - i];
			}
		}
		if (strlen(s3) > 80) { printf("overflow\n");}
		else printf("%s\n", s3);

	}
	return 0;
}
