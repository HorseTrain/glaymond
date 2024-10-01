#ifndef UI_H
#define UI_H

enum user_interface_mode
{
    main_screen,
    operation_add,
    operation_subtract,
    operation_multiply,
    operation_divide,
};

struct user_interface
{
    user_interface_mode working_mode;

    static void create(user_interface* result);
    static void destroy(user_interface* user_interface_context);
    static void draw_screen(user_interface* user_interface_context);
};

#endif