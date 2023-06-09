#include <stdlib.h> 
 int main() { 
     int queue[] = {55, 58, 60, 70, 18}; 
     int head = 50; 
     int total_tracks = 200; 
     int direction = 1; 
     int i, j, k, seek_time = 0, current_track, next_track, min, max, min_index, max_index; 
     int visited[5] = {0}; 
     int visited_count = 0; 
     min = max = queue[0]; 
     for (i = 1; i < 5; i++) { 
         if (queue[i] < min) { 
             min = queue[i]; 
         } 
         if (queue[i] > max) { 
             max = queue[i]; 
         } 
     } 
     current_track = head; 
     while (visited_count < 5) { 
         min_index = -1; 
         max_index = -1; 
         for (i = 0; i < 5; i++) { 
             if (!visited[i]) { 
                 if (queue[i] <= current_track && (min_index == -1 || queue[i] > queue[min_index])) { 
                     min_index = i; 
                 } 
                 if (queue[i] >= current_track && (max_index == -1 || queue[i] < queue[max_index])) { 
                     max_index = i; 
                 } 
             } 
         } 
         if (min_index == -1 && max_index == -1) { 
             direction = -direction; 
             continue; 
         } 
         if (direction == 1 && max_index != -1) { 
             next_track = queue[max_index]; 
         } else if (direction == -1 && min_index != -1) { 
             next_track = queue[min_index]; 
         } else if (max_index != -1) { 
             next_track = queue[max_index]; 
         } else { 
             next_track = queue[min_index]; 
         } 
         seek_time += abs(next_track - current_track); 
         current_track = next_track; 
         for (i = 0; i < 5; i++) { 
             if (queue[i] == current_track) { 
                 visited[i] = 1; 
                 visited_count++; 
                 break; 
             } 
         } 
     } 
     printf("Average head movement: %.2f\n", (float)seek_time/5); 
 }
[8:39 AM, 5/23/2023] ...vαrѕhíní...: #include <stdio.h> 
 #include <stdlib.h> 
 #define MAX 1000 
 int main() { 
     int n = 5;  
     int tracks[] = {55, 58, 60, 70, 18};  
     int start = 50;  
     int head = start;  
     int visited[MAX] = {0};  
     int total_head_movement = 0; 
     int max_track = tracks[0]; 
     int min_track = tracks[0]; 
     for (int i = 1; i < n; i++) { 
         if (tracks[i] > max_track) { 
             max_track = tracks[i]; 
         } 
         if (tracks[i] < min_track) { 
             min_track = tracks[i]; 
         } 
     } 
     int next_track = start; 
     while (next_track <= max_track) { 
         if (visited[next_track] == 0) { 
             total_head_movement += abs(head - next_track); 
             head = next_track; 
             visited[head] = 1; 
         } 
         next_track++; 
     } 
     next_track = max_track; 
     while (next_track >= min_track) { 
         if (visited[next_track] == 0) { 
             total_head_movement += abs(head - next_track); 
             head = next_track; 
             visited[head] = 1; 
         } 
         next_track--; 
     } 
     printf("Track Positions: "); 
     for (int i = 0; i < n; i++) { 
         printf("%d ", tracks[i]); 
     } 
     printf("\nStarting Track: %d\n", start); 
     printf("Sequence of Tracks Visited: %d ", start); 
     for (int i = start + 1; i <= max_track; i++) { 
         if (visited[i] == 1) { 
             printf("%d ", i); 
         } 
     } 
     for (int i = max_track; i >= min_track; i--) { 
         if (visited[i] == 1) { 
             printf("%d ", i); 
         } 
     } 
     printf("\nTotal Head Movement: %d\n", total_head_movement); 
     printf("Average Head Movement: %f\n", (float)total_head_movement / n); 
 }
