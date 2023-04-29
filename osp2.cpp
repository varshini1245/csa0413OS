#include<stdio.h>

int main()
{
    int n, frames[10], pages[30], page_faults = 0, first = 0, last = 0, found = 0;
    printf("Enter the number of page frames: ");
    scanf("%d", &n);
    printf("Enter the page reference sequence: ");
    for(int i = 0; i < 8; i++)
    {
        scanf("%d", &pages[i]);
    }

    for(int i = 0; i < n; i++)
    {
        frames[i] = -1;  //initialize frames with -1 to indicate they are empty
    }

    for(int i = 0; i < 8; i++)
    {
        found = 0;
        for(int j = 0; j < n; j++)
        {
            if(frames[j] == pages[i])  //page already present in frames
            {
                found = 1;
                break;
            }
        }
        if(found == 0)  //page not present in frames
        {
            page_faults++;
            frames[last] = pages[i];  //replace the page at last position in frames with the new page
            last = (last + 1) % n;  //increment last pointer, wrap around if it reaches the end of frames
        }
        printf("\n%d\t", pages[i]);
        for(int j = 0; j < n; j++)
        {
            printf("%d\t", frames[j]);
        }
    }
    printf("\nNumber of page faults = %d", page_faults);
    return 0;
}
