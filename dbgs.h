#ifndef ANALYZE
#define ANALYZE 0
#endif

#define dbgs \
    if (!ANALYZE) {} else std::cerr
