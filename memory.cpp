//
// Created by sxc200006 on 3/26/2021.
//

#include <memory>
#include <iostream>

struct Foundation
{
    const char *founder;
};

int main()
{
    std::unique_ptr<Foundation> second_foundation{new Foundation{}};
    std::cout << "hello" << std::endl;
}