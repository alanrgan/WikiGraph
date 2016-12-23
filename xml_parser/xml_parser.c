#include <curl/curl.h>
#include <stdio.h>

int main()
{
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
	if(curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, 
			"https://en.wikipedia.org/wiki/University_of_Illinois_at_Urbana-Champaign");

		// the following line tells to follow the redirect
		// curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

		res = curl_easy_perform(curl);

		/* Check for errors */ 
    	if(res != CURLE_OK)
      		fprintf(stderr, "curl_easy_perform() failed: %s\n",
        curl_easy_strerror(res));
 
    	/* always cleanup */ 
    	curl_easy_cleanup(curl);	
	}
}