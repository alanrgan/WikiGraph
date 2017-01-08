#include <stdio.h>
#include <libxml/HTMLparser.h>

int main(int argc, char *argv[])
{

	char *fileName = argv[1];
	htmlParserCtxtPtr parser = 
		htmlCreateMemoryParserCtxt(fileName, sizeof(fileName)/sizeof(fileName[0]));

	if(parser != NULL)
		printf("YYEAYYYYYYY\n");

	htmlDocPtr doc_ptr = htmlParseFile(fileName, "xml");

	if(doc_ptr != NULL) 
	{
		printf("HEYAYAYAYAYAAYA. WHATS GOING ON /n");
	}

	htmlFreeParserCtxt(parser);
	return 0;
}