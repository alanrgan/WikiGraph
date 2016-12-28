CC=gcc
CFLAGS=-I

xml_parser: xml_parser.c
	$(CC) xml_parser.c $(CFLAGS) /usr/local/include -lcurl -o xml_parser

download_page: download_page.c
	$(CC) download_page.c $(CFLAGS) /usr/local/include -lcurl -o download_page

https: https_test.c
	$(CC) https_test.c $(CFLAGS) /usr/local/include -lcurl -o https_test

html_parser: parse_test.c
	$(CC) parse_test.c $(CFLAGS) /usr/local/include -lxml2 -o parse_test

clean:
	rm -f xml_parser	