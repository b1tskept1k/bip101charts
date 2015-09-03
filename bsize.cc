#include <math.h>
#include <time.h>
#include <iostream>

using namespace std;

typedef __int64_t uint64;

uint64 max_blocksize (time_t block_timestamp) {
    uint64 time_start = 1452470400;
    uint64 time_double = 60*60*24*365*2;
    uint64 size_start = 8000000;

    if (block_timestamp < time_start) {
        return 1000000;
    }

    if (block_timestamp >= time_start+time_double*10) {
        return size_start << 10;
    }

    // Piecewise-linear-between-doublings growth:
    int time_delta = block_timestamp - time_start;
    int doublings = time_delta / time_double;
    uint64 remainder = time_delta % time_double;
    uint64 interpolate = ((size_start << doublings) * remainder) / time_double;
    uint64 max_size = (size_start << doublings) + interpolate;

    return max_size;
}

int main() {
    for (uint64 t = time(NULL); t <= 2222121600; t+=86400) {
        uint64 bsize = max_blocksize(t);
        cout << t << "," << bsize << endl;
    }
}
