#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    int arr[30], key1, key2, status;
    pid_t p1, p2;

    srand(time(NULL));

    printf("Array: ");
    for (int i = 0; i < 30; i++) {
        arr[i] = rand() % 50 + 1;
        printf("%d ", arr[i]);
    }

    printf("\n\nEnter Key 1 and Key 2: ");
    scanf("%d %d", &key1, &key2);

    // -------- Child 1 --------
    p1 = fork();
    if (p1 == 0) {   // child process
        for (int i = 0; i < 30; i++) {
            if (arr[i] == key1) {
                exit(1);   // key found
            }
        }
        exit(0);           // key not found
    }

    // Parent waits for Child 1
    waitpid(p1, &status, 0);
    int res1 = WEXITSTATUS(status);

    // -------- Child 2 --------
    p2 = fork();
    if (p2 == 0) {   // child process
        for (int i = 0; i < 30; i++) {
            if (arr[i] == key2) {
                exit(1);   // key found
            }
        }
        exit(0);           // key not found
    }

    // Parent waits for Child 2
    waitpid(p2, &status, 0);
    int res2 = WEXITSTATUS(status);

    // -------- Result --------
    if (res1)
        printf("\nKey %d found in array\n", key1);
    else
        printf("\nKey %d not found in array\n", key1);

    if (res2)
        printf("Key %d found in array\n", key2);
    else
        printf("Key %d not found in array\n", key2);

    return 0;
}
