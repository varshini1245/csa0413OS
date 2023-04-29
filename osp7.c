#include <stdio.h>
#define MAX_FRAMES 3
#define MAX_REFERENCES 25
int main() {
    int reference_sequence[MAX_REFERENCES] = {1,2,3,2,1,5,2,1,6,2,5,6,3,1,3,6,1,2,4,3};
    int page_frames[MAX_FRAMES] = {-1, -1, -1}; 
    int page_faults = 0;
    for (int i = 0; i < MAX_REFERENCES; i++) {
        int page_reference = reference_sequence[i];
        int page_hit = 0;
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (page_frames[j] == page_reference) {
                page_hit = 1;
                break;
            }
        }
        if (!page_hit) {
            int lru_index = 0;
            for (int j = 1; j < MAX_FRAMES; j++) {
                if (page_frames[j] == -1) { 
                    lru_index = j;
                    break;
                } else if (page_frames[j] < page_frames[lru_index]) {
                    lru_index = j;
                }
            }
            page_frames[lru_index] = page_reference;
            page_faults++;
        }
        printf("%d: ", page_reference);
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (page_frames[j] == -1) {
                printf("[ ] ");
            } else {
                printf("[%d] ", page_frames[j]);
            }
        }
        printf("\n");
    }

    printf("Number of page faults: %d\n", page_faults);

    return 0;
}
/* OUTPUT
1: [ ] [1] [ ]
2: [ ] [1] [2]
3: [3] [1] [2]
2: [3] [1] [2]
1: [3] [1] [2]
5: [3] [5] [2]
2: [3] [5] [2]
1: [3] [5] [1]
6: [3] [5] [6]
2: [2] [5] [6]
5: [2] [5] [6]
6: [2] [5] [6]
3: [3] [5] [6]
1: [1] [5] [6]
3: [3] [5] [6]
6: [3] [5] [6]
1: [1] [5] [6]
2: [2] [5] [6]
4: [4] [5] [6]
3: [3] [5] [6] */
