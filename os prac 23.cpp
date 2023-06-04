#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int n = sizeof(tracks) / sizeof(tracks[0]);
    int head_position = 50; // initial head position
    int direction = 1; // 1 for moving towards higher tracks, -1 for lower tracks

    int total_head_movement = 0;
    int i, j;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (tracks[j] > tracks[j + 1]) {
                int temp = tracks[j];
                tracks[j] = tracks[j + 1];
                tracks[j + 1] = temp;
            }
        }
    }

   
    int insert_index = 0;
    for (i = 0; i < n; i++) {
        if (head_position < tracks[i]) {
            insert_index = i;
            break;
        }
    }
    for (i = insert_index; i < n; i++) {
        total_head_movement += abs(head_position - tracks[i]);
        head_position = tracks[i];
    }
    for (i = insert_index - 1; i >= 0; i--) {
        total_head_movement += abs(head_position - tracks[i]);
        head_position = tracks[i];
    }

    float average_head_movement = (float) total_head_movement / n;
    printf("Average head movement: %.2f\n", average_head_movement);

    return 0;
}

