#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "PlusMinusPlugin.h"

void PlusMinusPlugin::input(std::string file) {
   readParameterFile(file);
}

void PlusMinusPlugin::run() {}

void PlusMinusPlugin::output(std::string file) {
       	std::string outputfile = file;
	
	std::string myCommand = "echo -e \"contig\\tplus_counts\" > "+file+"/plus_counts.txt; ";
myCommand += "while read -r line; do samtools view -F 16 "+PluginManager::addPrefix(myParameters["alignmentdir"])+"/\"${line}\"_reads.bam | awk -v line=\"${line}\" '{count++; contig=$3} END {if (NR==0) {print line 0} else {print line count}}' >> "+file+"/plus_counts.txt; done < "+PluginManager::addPrefix(myParameters["contigs"]);
 std::cout << myCommand << std::endl;
system(myCommand.c_str());
myCommand = "sed -i 's/ /\t/' "+file+"/plus_counts.txt";
system(myCommand.c_str());

myCommand = "echo -e \"contig\\tminus_counts\" > "+file+"/minus_counts.txt; ";
myCommand += "while read -r line; do samtools view -f 16 "+PluginManager::addPrefix(myParameters["alignmentdir"])+"/\"${line}\"_reads.bam | awk -v line=\"${line}\" '{count++; contig=$3} END {if (NR==0) {print line 0} else {print line count}}' >> "+file+"/minus_counts.txt; done < "+PluginManager::addPrefix(myParameters["contigs"]);
 std::cout << myCommand << std::endl;
system(myCommand.c_str());
myCommand = "sed -i 's/ /\t/' "+file+"/minus_counts.txt";
system(myCommand.c_str());
}

PluginProxy<PlusMinusPlugin> PlusMinusPluginProxy = PluginProxy<PlusMinusPlugin>("PlusMinus", PluginManager::getInstance());
