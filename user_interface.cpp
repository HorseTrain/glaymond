#include "user_interface.h"
#include <assert.h>
#include <iostream>
#include <string>
#include <stdlib.h>

void user_interface::create(user_interface* result)
{
    result->working_mode = user_interface_mode::main_screen;
}

void user_interface::destroy(user_interface* to_destroy)
{
    //
}

static void ask(std::string* result,std::string question)
{
    std::cout << question << " : ";
    std::cin >> *result;
}

static void to_lower(std::string* result, std::string source)
{
    *result = "";

    for (int i = 0; i < source.size(); ++i)
    {
        if (source[i] >= 'A' && source[i] <= 'Z')
        {
            *result += source[i] + 32;
        }
        else
        {
            *result += source[i];
        }
    }
}

static void clear_screen()
{
    system("clear");
}

static void draw_ui_entry_screen(user_interface* user_interface_context)
{
    while (true)
    {
        clear_screen();

        std::cout << "Welcome to the Calculator" << std::endl;

        std::string to_do ;
        
        ask(&to_do,"What Operation would you like to do?");
        to_lower(&to_do, to_do);

        if (to_do == "add")
        {
            user_interface_context->working_mode = operation_add;

            return;
        }
        else
        {
            std::cout << "Undefined operation " << to_do << std::endl;
            std::cin;
        }
    }
}

void user_interface::draw_screen(user_interface* user_interface_context)
{
    switch (user_interface_context->working_mode)
    {
        case user_interface_mode::main_screen: draw_ui_entry_screen(user_interface_context); break;
        default: std::cout << "UNDEFINED UI MODE GANG" << std::endl; assert(false); throw 0;
    }
}