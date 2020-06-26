//#include<iostream>
//#include<vector>
#include<iostream>
#include<stdlib.h>
using namespace std;

struct maze {
    int north;
    int east;
    int south;
    int west;
};

struct route {
    char* s;
    int row;
    int col;
    int from;
    int to;
    struct route* next;
};

int row = 0;
int col = 0;

void setmap(struct maze** m);
void record_s(struct maze** m, struct route* q);
struct route* generate_route(struct maze** m, struct route* r);


int main(void)
{
    struct maze* m[6];
    for (int i = 0; i < 6; i++) { m[i] = (struct maze*)malloc((sizeof(struct maze)) * 5); }
    setmap(&m[0]);
    struct route* r = NULL, * s;

    while (true) {
        r = generate_route(&m[0], r);
        s = r;
        while (s->next != NULL) { s = s->next; }
        if (row == 1 && col == 0 && s->from == 1) { break; }
    }

    while (r != NULL) {
        printf("%c", r->s[0]);
        r = r->next;
    }
    printf("\n");

    return 0;
}

void setmap(struct maze** m) {
    int j = 0;
    for (int i = 0; i < 9; i++) {
        if (i % 2 == 0) {
            char s[5] = ""; cin >> s;
            for (unsigned int k = 0; k < strlen(s); k++) {
                if (s[k] == '1') {
                    m[j][k].south = 1;
                    m[j + 1][k].north = 1;
                }
                else {
                    m[j][k].south = 0;
                    m[j + 1][k].north = 0;
                }
            }
            j = j + 1;
        }
        else {
            char s[6] = ""; cin >> s;
            if (s[0] == '1') { m[j][0].west = 1; }
            else { m[j][0].west = 0; }


            for (unsigned int k = 0; k < strlen(s) - 1; k++) {
                if (s[k + 1] == '1') {
                    m[j][k].east = 1;
                    m[j][k + 1].west = 1;
                }
                else {
                    m[j][k].east = 0;
                    m[j][k + 1].west = 0;
                }
            }
        }
    }
}

struct route* generate_route(struct maze** m, struct route* r)
{
    struct route* q = NULL, * q2 = r;

    q = (struct route*)malloc(sizeof(struct route));
    q->s = (char*)malloc(sizeof(char) * 1);
    q->s[0] = ' ';
    q->next = NULL;
    int tmp = 0;
    bool edge = false;

    if (r == NULL) { q->from = 3; }
    else {
        while (r->next != NULL) { r = r->next; }
        if (row == 0 && col == 4) {
            row++;
            tmp = (r->to + 2) % 4;
            q->from = 0;
            edge = true;

        }
        else if (row == 5 && col == 4) {
            col--;
            tmp = (r->to + 2) % 4;
            q->from = 1;
            edge = true;
        }
        else if (row == 5 && col == 0) {
            row--;
            tmp = (r->to + 2) % 4;
            q->from = 2;
            edge = true;
        }

        else {
            q->from = (r->to + 2) % 4;
        }
    }
    q->row = (row);
    q->col = (col);
    record_s(m, q);
    if (edge) { q->from = tmp; }

    //printf("%s : (row, col) = (%d, %d), %d -> %d\n", q->s, q->row, q->col, q->from, q->to);

    if (r == NULL) {
        r = q;
    }
    else {
        r->next = q;
        r = q2;
    }
    return r;
}

void record_s(struct maze** m, struct route* q)
{
    int tmp;
    bool edge = false;

    if (m[row][col].east == 1 && m[row][col].south == 1 && q->from == 3) {
        q->s[0] = 'U';
        q->to = (q->from + 1) % 4;
    }
    else if (m[row][col].east == 1 && m[row][col].north == 1 && q->from == 2) {
        q->s[0] = 'L';
        q->to = (q->from + 1) % 4;
    }
    else if (m[row][col].west == 1 && m[row][col].north == 1 && q->from == 1) {
        q->s[0] = 'D';
        q->to = (q->from + 1) % 4;
    }
    else if (m[row][col].west == 1 && m[row][col].south == 1 && q->from == 0) {
        q->s[0] = 'R';
        q->to = (q->from + 1) % 4;
    }
    else {
        if (m[row][col].north == 1 && m[row][col].east == 0 && q->from == 2) {
            col++; q->col = col; tmp = q->from; q->from = 3; edge = true;
        }
        else if (m[row][col].east == 1 && m[row][col].south == 0 && q->from == 3) {
            row++; q->row = row; tmp = q->from; q->from = 0; edge = true;
        }
        else if (m[row][col].south == 1 && m[row][col].west == 0 && q->from == 0) {
            col--; q->col = col; tmp = q->from; q->from = 1; edge = true;
        }
        else if (m[row][col].west == 1 && m[row][col].north == 0 && q->from == 1) {
            row--; q->row = row; tmp = q->from; q->from = 2; edge = true;
        }

        if (m[row][col].north == 1 && q->from == 1) {
            q->s[0] = 'L';
            q->to = (q->from + 2) % 4;
            col = (m[row][col].west == 1) ? col : col - 1;
        }
        else if (m[row][col].east == 1 && q->from == 2) {
            q->s[0] = 'U';
            q->to = (q->from + 2) % 4;
            row = (m[row][col].north == 1) ? row : row - 1;
        }
        else if (m[row][col].south == 1 && q->from == 3) {
            q->s[0] = 'R';
            q->to = (q->from + 2) % 4;
            col = (m[row][col].east == 1) ? col : col + 1;
        }
        else if (m[row][col].west == 1 && q->from == 0) {
            q->s[0] = 'D';
            q->to = (q->from + 2) % 4;
            row = (m[row][col].south == 1) ? row : row + 1;
        }
        q->to = (q->from + 2) % 4;
        if (edge) { q->from = tmp; }

    }
}