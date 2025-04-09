// degree.h - defines the degree programs
#pragma once
#include <string>

// the different degrees a student can have
enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };

// strings to print the degree programs, matched to the enum above
static const std::string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };