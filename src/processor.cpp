#include "processor.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  cpu = LinuxParser::CpuUtilization();

  float user, nice, system, idle, iowait, irq, softirq, steal, guest, guestnice;


  user = std::stof(cpu[LinuxParser::kUser_]);
  nice = std::stof(cpu[LinuxParser::kUser_]);
  system = std::stof(cpu[LinuxParser::kSystem_]);
  idle = std::stof(cpu[LinuxParser::kIdle_]);
  iowait = std::stof(cpu[LinuxParser::kIOwait_]);
  irq = std::stof(cpu[LinuxParser::kIRQ_]);
  softirq = std::stof(cpu[LinuxParser::kSoftIRQ_]);
  steal = std::stof(cpu[LinuxParser::kSteal_]);
  guest = std::stof(cpu[LinuxParser::kGuest_]);
  guestnice = std::stof(cpu[LinuxParser::kGuestNice_]);

  user = user - guest;
  nice = nice - guestnice;
  idle = idle + iowait;
  system = system + irq + softirq;


  // repeat
  float PrevIdle = previdle + previowait;
  float Idle = idle + iowait;

  float PrevNonIdle =
      prevuser + prevnice + prevsystem + previrq + prevsoftirq + prevsteal;
  float NonIdle = user + nice + system + irq + softirq + steal;

  float PrevTotal = PrevIdle + PrevNonIdle;
  float Total = Idle + NonIdle;

  float totald = Total - PrevTotal;
  float idled = Idle - PrevIdle;

  float CPU_Percentage = (totald - idled) / totald;
  previdle = idle;
  previowait = iowait;
  prevuser = user;
  prevnice = nice;
  prevsystem = system;
  previrq = irq;
  prevsoftirq = softirq;
  prevsteal = steal;
  return CPU_Percentage;
}
