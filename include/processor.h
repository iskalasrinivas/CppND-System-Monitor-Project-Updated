#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <string>
#include <vector>

#include "linux_parser.h"

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
 private:
  std::vector<std::string> cpu;
  float previdle;
  float previowait;
  float prevuser;
  float prevnice;
  float prevsystem;
  float previrq;
  float prevsoftirq;
  float prevsteal;
};

#endif