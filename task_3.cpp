#include <iostream>
#include <vector>
#include <map>
#include <cpr/task_1.h>

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

        std::map<std::string, std::string> mp;
        //cpr::Payload payload = cpr::Payload{mp};

        //cpr::Response resp = cpr::Post(cpr::Url(link_path), cpr::Payload({payload}));
        //std::cout << resp.text << std::endl;
    }

    return 0;
}