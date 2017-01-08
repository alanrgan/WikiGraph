#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

void parseDoc(char *docname);

int main(int argc, char **argv)
{
	char *docname;
		
	if (argc <= 1) {
		printf("Usage: %s docname\n", argv[0]);
		return(0);
	}

	docname = argv[1];
	parseDoc (docname);

	return 1;
}

void parseDoc(char *docname)
{
	xmlDocPtr doc;
	xmlNodePtr cur;

	doc = xmlParseFile(docname);
	
	if (doc == NULL ) 
	{
		fprintf(stderr,"Document not parsed successfully. \n");
		return;
	}
	
	cur = xmlDocGetRootElement(doc);
	
	if (cur == NULL) 
	{
		fprintf(stderr,"empty document\n");
		xmlFreeDoc(doc);
		return;
	}
	
	// if (xmlStrcmp(cur->name, (const xmlChar *) "story")) {
	// 	fprintf(stderr,"document of the wrong type, root node != story");
	// 	xmlFreeDoc(doc);
	// 	return;
	// }
	
	// cur = cur->xmlChildrenNode;
	// while (cur != NULL)
	// {
	// 	if ((!xmlStrcmp(cur->name, (const xmlChar *)"storyinfo")))
	// 	{
	// 		parseStory (doc, cur);
	// 	}
		 
	// cur = cur->next;
	// }
	
	xmlFreeDoc(doc);
	return;
}