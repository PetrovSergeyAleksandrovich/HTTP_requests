#include <iostream>
#include <cpr/cpr.h>

struct Commands{
    std::string get = "get";
    std::string post = "post";
    std::string put = "put";
    std::string del = "delete";
    std::string patch = "patch";
};

int main()
{
    std::string user_input = "none";
    Commands command;

    do
    {
        std::cout << "Type get/post/put/delete/patch or exit: ";
        std::cin >> user_input;

        if(user_input == command.get)
        {
            cpr::Response resp = cpr::Get(cpr::Url("http://httpbin.org/"+user_input));
            std::cout << resp.text << std::endl;
            continue;
        }

        if(user_input == command.post)
        {
            cpr::Response resp = cpr::Post(cpr::Url("http://httpbin.org/post"));
            std::cout << resp.text << std::endl;
            continue;
        }

        if(user_input == command.put)
        {
            cpr::Response resp = cpr::Put(cpr::Url("http://httpbin.org/put"));
            std::cout << resp.text << std::endl;
            continue;
        }

        if(user_input == command.del)
        {
            cpr::Response resp = cpr::Delete(cpr::Url("http://httpbin.org/delete"));
            std::cout << resp.text << std::endl;
            continue;
        }

        if(user_input == command.patch)
        {
            cpr::Response resp = cpr::Patch(cpr::Url("http://httpbin.org/patch"));
            std::cout << resp.text << std::endl;
            continue;
        }

    } while(user_input != "exit");


    return 0;
}