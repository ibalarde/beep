#include <utilapiset.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define MIN_SLEEP 30000
#define MAX_SLEEP 120000
#define FREQ 880
#define DURATION 125

int random(int min, int max) {
    /*
        returns a sort-of random number in the range [min, max)
    */
    return min + rand() % max; 
}

int main() {
    int ret = EXIT_FAILURE;

    srand(time(NULL));

    while (1) {
        Sleep(random(MIN_SLEEP, MAX_SLEEP));
        if (!Beep(FREQ, DURATION)) {
            goto cleanup;
        }
    }

    ret = EXIT_SUCCESS;
cleanup:
    return ret;
}