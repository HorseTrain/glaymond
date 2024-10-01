#include "user_interface.h"

#include <iostream>

int main()
{
    user_interface ui;

    user_interface::create(&ui);

    while (true)
    {
        user_interface::draw_screen(&ui);
    }
}