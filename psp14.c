#include <stdio.h>
#define MAX_FRAMES 3

int main()
{
    int frames[MAX_FRAMES], pages[MAX_FRAMES], page_faults = 0;
    int page_reference[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int num_pages = sizeof(page_reference)/sizeof(page_reference[0]);
    int i, j, k, max_future_distance, page_to_replace;

    for(i = 0; i < MAX_FRAMES; i++)
    {
        frames[i] = -1;
        pages[i] = -1;
    }

    for(i = 0; i < num_pages; i++)
    {
        int page_found = 0;
        int page = page_reference[i];

        for(j = 0; j < MAX_FRAMES; j++)
        {
            if(frames[j] == page)
            {
                page_found = 1;
                break;
            }
        }

        if(page_found == 0)
        {
            for(j = 0; j < MAX_FRAMES; j++)
            {
                int page_exists = 0;
                int future_distance = 0;

                for(k = i + 1; k < num_pages; k++)
                {
                    if(frames[j] == page_reference[k])
                    {
                        page_exists = 1;
                        future_distance = k - i;
                        break;
                    }
                }

                if(page_exists == 0)
                {
                    page_faults++;
                    frames[j] = page;
                    break;
                }

                if(future_distance > max_future_distance)
                {
                    max_future_distance = future_distance;
                    page_to_replace = j;
                }
            }

            page_faults++;
            frames[page_to_replace] = page;
        }
    }

    printf("Number of Page Faults: %d", page_faults);

    return 0;
}
