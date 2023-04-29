#include <stdio.h>
#include <stdlib.h>
#define NUM_TRACKS 5
int main() {
    int track_positions[NUM_TRACKS] = {55, 58, 60, 70, 18};
    int head_position = 50; 
    int total_head_movement = 0;

    printf("Head movement sequence: ");

    for (int i = 0; i < NUM_TRACKS; i++) {
        int distance = abs(track_positions[i] - head_position);
        total_head_movement += distance;
        head_position = track_positions[i];
        printf("%d ", head_position);
    }

    printf("\nAverage head movement: %d\n", total_head_movement / NUM_TRACKS);

    return 0;
}
/* output 
Head movement sequence: 55 58 60 70 18
Average head movement: 14 */
