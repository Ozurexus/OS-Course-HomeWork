#include <stdio.h>
#include <stdlib.h>
struct process {
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};
int main() {
    int n, total_tat = 0, total_wt = 0;
    printf("Number of processes: ");
    scanf("%d", &n);
    int quantum;
    printf("Enter quantum: ");
    scanf("%d", &quantum);
    struct process *p = malloc(n * sizeof(struct process));
    for (int i = 0; i < n; i++) {
        printf("Process %d. ", i + 1);
        printf("Arrival time: ");
        scanf("%d", &p[i].at);
        printf("Burst time: ");
        scanf("%d", &p[i].bt);
        p[i].id = i + 1;
    }
    int original_bt[n];
    for (int i = 0; i < n; i++) {
        original_bt[i] = p[i].bt;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                struct process tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;
            }
        }
    }
    int time = 0;
    int i = 0;
    int counter = n;
    while (i < n) {
        if (p[i].at <= time) {
            if (p[i].bt > quantum) {
                time += quantum;
                p[i].bt -= quantum;
            } else {
                if (p[i].bt > 0) {
                    time += p[i].bt;
                    p[i].bt = 0;
                    p[i].ct = time;
                    p[i].tat = p[i].ct - p[i].at;
                    p[i].wt = p[i].tat - original_bt[i];
                    total_tat += p[i].tat;
                    total_wt += p[i].wt;
                    counter--;
                }
            }
        } else {
            time++;
        }
        i++;
        if (i == n) {
            i = 0;
        }
        if (counter == 0) {
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("id: %d.\tat: %d.\tbt: %d.\tct: %d.\ttat: %d.\twt: %d.\n",
               p[i].id, p[i].at, original_bt[i], p[i].ct, p[i].tat, p[i].wt);
    }
    printf("Average TAT: %f\t", (float)total_tat / n);
    printf("Average WT: %f\n", (float)total_wt / n);
    return 0;
}