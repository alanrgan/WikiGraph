#include <string.h>
#include <stdlib.h>

/**
* For quick testing purposes only
*/
NodeChildPair *parseLine(char *line, char pcdelim, char ccdelim)
{
	stringstream children;

	NodeChildPair *p = new NodeChildPair;
	vector<string> strvec;
	char *parent, *token;
	//char *cline = new char[line.length()+1];
	//strcpy(cline, line.c_str());

	char pcdel[2] = {pcdelim, '\0'};
	char ccdel[2] = {ccdelim, '\0'};

	parent = strtok(line, pcdel);
	while((token = strtok(NULL, ccdel)))
		strvec.push_back(token);

	p->first = parent;
	p->second = strvec;

	return p;
}