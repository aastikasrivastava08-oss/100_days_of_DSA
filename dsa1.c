#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];  // assuming maximum size 100

    // Input array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int pos, x;
    scanf("%d", &pos);
    scanf("%d", &x);

    // Shift elements to the right
    for(int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert element at correct position (1-based to 0-based index)
    arr[pos - 1] = x;

    // Print updated array
    for(int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
