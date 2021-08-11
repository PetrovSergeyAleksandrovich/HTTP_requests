#include <iostream>
#include <vector>
#include <map>
#include <cpr/cpr.h>

int main ()
{
    std::vector<std::string> input_data;
    std::string user_input;

    while (true)
    {
        std::cout << "Type parameters: ";
        std::cin >> user_input;
        if(user_input == "get" || user_input == "post") break;
        input_data.push_back(user_input);
    }

    std::cout << "input done. sending data" << std::endl;

    if(user_input == "get")
    {
        std::string link_path = "http://httpbin.org/get?";
        for(int i = 0; i < input_data.size(); i += 2)
        {
            link_path += (input_data[i] + '=' + input_data[i+1]) + '&';
        }
        std::cout << "YOUR REQUEST: " << link_path << std::endl;
        cpr::Response resp = cpr::Get(cpr::Url(link_path));
        std::cout << resp.text << std::endl;
    }

    if(user_input == "post")
    {
        std::string link_path = "http://httpbin.org/post";
        std::vector<cpr::Pair> pairs = {{"t", "e"}, {"s", "t"}};

        for(int i = 0; i < input_data.size();)
        {
            std::string x = "none";
            std::string y = "none";

            x = input_data[i];
            if(++i < input_data.size()) {y = input_data[i]; ++i;}
            pairs.emplace_back(x.c_str(), y.c_str());
        }

        cpr::Payload payload = cpr::Payload(pairs.begin(), pairs.end());

        cpr::Response resp = cpr::Post(cpr::Url(link_path), cpr::Payload({payload}));
        std::cout << resp.text << std::endl;
    }

    return 0;
}