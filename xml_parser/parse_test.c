#include <stdio.h>
#include <libxml/HTMLparser.h>

int main(int argc, char *argv[])
{

	char *fileName = argv[1];
	htmlParserCtxtPtr parser = 
		htmlCreateMemoryParserCtxt(fileName, sizeof(fileName)/sizeof(fileName[0]));

	if(parser != NULL)
		printf("YYEAYYYYYYY\n");

	int success = htmlParseDocument(parser);
	printf("%d \n", success);

	htmlFreeParserCtxt(parser);
	return 0;
}