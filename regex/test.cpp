#include<sys/types.h>
#include<regex.h>
#include<string>
#include<stdio.h>
int main()
{
	  char *haa = "a very simple simple simple string";
	     char       *regex = "([a-z]+)[ \t]([a-z]+)";
	regex_t comment;
	size_t nmatch;
	regmatch_t regmatch[100];
	regcomp(&comment, regex, REG_EXTENDED|REG_NEWLINE);
	while(1)
	{
		int j = regexec(&comment,haa,sizeof(regmatch)/sizeof(regmatch_t),regmatch,0); 
		if(j != 0)
			break;
		for(int i = 0; i< 100 && regmatch[i].rm_so!= -1;i++)
		{
			std::string str;
			str.assign(haa+regmatch[i].rm_so, regmatch[i].rm_eo - regmatch[i].rm_so);
			printf("%s\n",str.c_str());
		}

		if(regmatch[0].rm_so != -1)
			haa+= regmatch[0].rm_eo;
	}
	regfree(&comment);
	return 0;
}
