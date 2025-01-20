#ifndef PlusMinusPLUGIN_H
#define PlusMinusPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include "Tool.h"
#include <string>

class PlusMinusPlugin : public Plugin, public Tool
{
public: 
 std::string toString() {return "PlusMinus";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
};

#endif
