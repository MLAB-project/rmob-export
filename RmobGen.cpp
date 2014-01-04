//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Run whit -input parameter whit path to .info file as: ./RmobGen -input-./io/Observatory.info
//
//

#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <Magick++.h>
#include <mysql/mysql.h>


#include "incl/SvgGen.h"
#include "incl/Parser.h"

using namespace std;

int main(int argc, char const *argv[]){

	string ObsInfo[15];
	int HourCount[744];

	for (int i = 0; i < 744; ++i)
	{
		HourCount[i]=0;
	}


	ParArgB(argc, argv);

	ParObsInfo(ObsInfo, ParArg(argc, argv));


	if (ObsInfo[14] == "Bolidozor")
	{
		ParBolidozorFile(HourCount,ObsInfo[13]);
		TxtGen(ObsInfo,HourCount);
		SvgGen(ObsInfo,HourCount);
		SvgJpg("./io/");
	}
	if (ObsInfo[14] == "Rmob")
	{
		ParRmobFile(HourCount,ObsInfo[13]);
		TxtGen(ObsInfo,HourCount);
		SvgGen(ObsInfo,HourCount);
		SvgJpg("./io/");
	}
	if (ObsInfo[14] == "MySQL")
	{
		ParMySQL(HourCount);
	}


	//ParBolidozorFile(HourCount,ObsInfo[15]);
	//ParRmobFile(HourCount,ObsInfo[15]);

	//SvgPng("./io/");
	return 0;
}
