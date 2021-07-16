#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "process.h"
#include "processor.h"
#include "system.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

// TODO: Return the system's CPU
Processor& System::Cpu() {
    cpu_ = Processor(); 
    return cpu_; 
}

// TODO: Return a container composed of the system's processes
vector<Process>& System::Processes() { 
    processes_.clear();
    for(int pid : LinuxParser::Pids()){
        Process p(pid);
        processes_.push_back(p);
    }

    std::sort(processes_.begin(), processes_.end());
    return processes_; 
}

// TODO: Return the system's kernel identifier (string)
std::string System::Kernel() {
    std::string kernel = LinuxParser::Kernel();
    return kernel;
}

// TODO: Return the system's memory utilization
float System::MemoryUtilization() { 
    float mem_util = LinuxParser::MemoryUtilization();
    return mem_util; 
}

// TODO: Return the operating system name
std::string System::OperatingSystem() {
    std::string os = LinuxParser::OperatingSystem();
    return os;
}

// TODO: Return the number of processes actively running on the system
int System::RunningProcesses() {
    int process = LinuxParser::RunningProcesses();
    return process;
}

// TODO: Return the total number of processes on the system
int System::TotalProcesses() {
    int process = LinuxParser::TotalProcesses();
    return process; 
 }

// TODO: Return the number of seconds since the system started running
long int System::UpTime() { 
    long uptime = LinuxParser::UpTime();
    return uptime;
 }