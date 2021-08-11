#include <iostream>
#include <cpr/cpr.h>

std::string find_header_h1(std::string inText)
{
    std::string output;
    for(int i = 0; i < inText.length(); ++i)
    {
        if(inText[i] == '<' && inText[i+1] == 'h' && inText[i+2] == '1' && inText[i+3] == '>')
        {
            i += 4;
            while(inText[i] != '<' && inText[i+1] != '/' && inText[i+2] != 'h' && inText[i+3] != '1' && inText[i+4] != '>')
            {
                output += inText[i];
                i++;
            }
        }
    }
    return output;
}

int main ()
{
    cpr::Response resp = cpr::Get(cpr::Url("http://httpbin.org/html"),
                                  cpr::Header{{"Accept", "text/html"}});

    std::cout << find_header_h1(resp.text);

    return 0;
}