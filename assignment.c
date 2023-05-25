#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int min_cables(int n, int** connections, int connectionsSize, int* connectionsColSize);
int main(int argc, char** argv)
{
int n = 4;
int connectionsSize = 3;
int connectionsColSize = 2;
int** connections =(int*)malloc(connectionsSize * sizeof(int));
for (int i = 0; i < connectionsSize; i++) {
connections[i] = (int*)malloc(connectionsColSize * sizeof(int));
}
connections[0][0] = 0; connections[0][1] = 1;
connections[1][0] = 0; connections[1][1] = 2;
connections[2][0] = 1; connections[2][1] = 2;
printf("%d\n", min_cables(n, connections, connectionsSize, connectionsColSize));
for (int i = 0; i < connectionsSize; i++) {
free(connections[i]);
}
free(connections);
return 0;
}
int min_cables(int n, int** connections, int connectionsSize, int* connectionsColSize) {
if (n < 2) {
return 0;
}
if (connectionsSize == 0) {
return -1;
}
int* arr = (int*)calloc(n, sizeof(int));
int count = 0;
for (int i = 0; i < connectionsSize; i++) {
int a = connections[i][0];
int b = connections[i][1];
if (arr[a] == 0 && arr[b] == 0) {
arr[a] = ++count;
arr[b] = count;
}
else if (arr[a] != 0 && arr[b] == 0) {
arr[b] = arr[a];
}
else if (arr[b] != 0 && arr[a] == 0) {
arr[a] = arr[b];
}
else if (arr[a] != arr[b]) {
int t = arr[b];
for (int j = 0; j < n; j++) {
if (arr[j] == t) {
arr[j] = arr[a];
}
}
}
}
int ret = 0;
for (int i = 0; i < n; i++) {
if (arr[i] == 0) {
ret++;
}
}
free(arr);
return ret - 1;
}
