#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int a[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    // ===== RECOVERY =====
    for (int i = 0; i < N; i++) {
        if (a[i] == -1) {
            int left = -1, right = -1;

            // cari kiri
            for (int j = i - 1; j >= 0; j--) {
                if (a[j] != -1) {
                    left = a[j];
                    break;
                }
            }

            // cari kanan
            for (int j = i + 1; j < N; j++) {
                if (a[j] != -1) {
                    right = a[j];
                    break;
                }
            }

            if (left != -1 && right != -1)
                a[i] = (left + right) / 2;
            else if (left != -1)
                a[i] = left;
            else if (right != -1)
                a[i] = right;
            else
                a[i] = 0;
        }
    }

    // ===== PRINT RECOVERED =====
    printf("RECOVERED ");
    for (int i = 0; i < N; i++) {
        printf("%d", a[i]);
        if (i < N - 1) printf(" ");
    }
    printf("\n");

    // ===== KADANE =====
    int max_sum = a[0];
    int current = a[0];

    for (int i = 1; i < N; i++) {
        if (current + a[i] > a[i])
            current = current + a[i];
        else
            current = a[i];

        if (current > max_sum)
            max_sum = current;
    }

    printf("MAX_SUM %d\n", max_sum);

    return 0;
}
