/*Problem Statemen: Implement a hash table using quadratic probing with formula:
h(k, i) = (h(k) + i*i) % m*/
#include <stdio.h>
#include <string.h>
#define SIZE 100

int table[SIZE];
int hash(int key, int m) {
    return key % m;
}
void insert(int key, int m) {
    int i = 0;
    int index;
    while (i < m) {
        index = (hash(key, m) + i * i) % m;
        if (table[index] == -1) {
            table[index] = key;
            return;
        }
        i++;
    }
}
void search(int key, int m) {
    int i = 0;
    int index;
    while (i < m) {
        index = (hash(key, m) + i * i) % m;
        if (table[index] == key) {
            printf("FOUND\n");
            return;
        }
        if (table[index] == -1) break;
        i++;
    }
    printf("NOT FOUND\n");
}
int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    for (int i = 0; i < m; i++)
        table[i] = -1;

    char op[10];
    int key;
    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);
        if (strcmp(op, "INSERT") == 0)
            insert(key, m);
        else if (strcmp(op, "SEARCH") == 0)
            search(key, m);
    }
    return 0;
}
