//============================================================================
// Name        : proj_refactor_file
// Author      : 
// Version     :
// Copyright   : Steal this code!
// Description : learn how to refactor files into a sensible directory structure
//============================================================================
#include <iostream>
#include <string>
#include <vector>
#include "../includes/constants.h"
#include "../includes/fileio.h"
#include "../includes/utils.h"
using namespace std;

int main() {
	vector<process> myProcesses;

	//assumme failure
	int iRet = FAIL;

	//get raw data
	iRet = loadData(SOURCE_FILE, myProcesses);
	if (iRet != SUCCESS)
		return iRet;

	int orig_size = getSize(myProcesses);
	int new_size = handleMissingData(myProcesses);
	if (orig_size != new_size)
		cout<<"Dropped "<<(orig_size-new_size)<<" rows with missing data"<<endl;

	//sort the data
	sortData(SORT_ORDER::START_TIME,myProcesses);

	//how many entries in vector
	iRet = getSize(myProcesses);
	if (iRet < EMPTY)
		return iRet;

	process p = getNext(myProcesses);
	if (p.cpu_time == UNINITIALIZED)
		return

	//save processed data
	iRet = saveData(RESULTS_FILE, myProcesses);
	return iRet;
}
