#include "process.h"

#include <unistd.h>

#include <cctype>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::to_string;
using std::vector;

Process::Process() {}
Process::Process(int p) : pid_(p) {
  CpuUtilization();
  Command();
  Ram();
  User();
  UpTime();
}

// TODO: Return this process's ID
int Process::Pid() { return pid_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() {
  string line, str, val;
  float utime, stime, cutime, cstime, starttime, totaltime;
  vector<string> vec;
  int count = 1;
  std::ifstream stream(LinuxParser::kProcDirectory + to_string(pid_) + LinuxParser::kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    while (count != 23) {
      if (count == 14) {
        linestream >> utime;
      } else if (count == 15) {
        linestream >> stime;
      } else if (count == 16) {
        linestream >> cutime;
      } else if (count == 17) {
        linestream >> cstime;
      } else if (count == 22) {
        linestream >> starttime;
      }
      count += 1;
    }
  }

    totaltime = utime + stime + cutime + cstime;
    float seconds = UpTime() - starttime / sysconf(_SC_CLK_TCK);
    float cpu_usage = ((totaltime /sysconf(_SC_CLK_TCK)) / seconds);

    return cpu_usage;
  }

  // TODO: Return the command that generated this process
  string Process::Command() {
    command_ = LinuxParser::Command(pid_);
    return command_;
  }

  // TODO: Return this process's memory utilization
  string Process::Ram() {
    ram_ = LinuxParser::Ram(pid_);
    return ram_;
  }

  // TODO: Return the user (name) that generated this process
  string Process::User() {
    user_ = LinuxParser::User(pid_);
    return user_;
  }

  // TODO: Return the age of this process (in seconds)
  long int Process::UpTime() {
    uptime_ = LinuxParser::UpTime(pid_);
    return uptime_;
  }

  // TODO: Overload the "less than" comparison operator for Process objects
  // REMOVE: [[maybe_unused]] once you define the function
  bool Process::operator<(Process const& a) const {
    return a.cpuutilization_ < this->cpuutilization_;
  }