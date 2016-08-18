#include "utils.h"

using namespace std;

Utils::Utils() {
}

Memory Utils::current_mem_usage() {
    Memory resident_set = 0.0;

    // 'file' stat seems to give the most reliable results
    ifstream stat_stream("/proc/self/stat", ios_base::in);

    // dummy vars for leading entries in stat that we don't care about
    string pid, comm, state, ppid, pgrp, session, tty_nr;
    string tpgid, flags, minflt, cminflt, majflt, cmajflt;
    string utime, stime, cutime, cstime, priority, nice;
    string O, itrealvalue, starttime, vsize;

    // the field we want
    long rss;

    stat_stream >> pid >> comm >> state >> ppid >> pgrp >> session >> tty_nr
            >> tpgid >> flags >> minflt >> cminflt >> majflt >> cmajflt
            >> utime >> stime >> cutime >> cstime >> priority >> nice
            >> O >> itrealvalue >> starttime >> vsize >> rss; // don't care about the rest

    stat_stream.close();

    // in case x86-64 is configured to use 2MB pages
    Memory page_size_kb = (Memory) sysconf(_SC_PAGE_SIZE) / MEMORY_MEGABYTE;
    resident_set = rss * page_size_kb;

    return resident_set;
}
