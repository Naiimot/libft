# 42's libft

Teaching at 42 focus on giving a solid understanding of the most basic elements in programming. For most of the project we do we are not allowed to use external libraries, most of the time malloc, free and write are our only allies. That's why we are progressively building our own library of usefull function. Some are copies of classic C libraries, others are my own creation, result from a repeated need for them.

## libft

This folder contains basic functions for string manipulation, memory management and some useful linked list tools.

## get_next_line

One of the first 42 project, this function allow us to read line by line on any fd. Multiple fds ca be handled simultaneously.

## ft_printf

This is my own version of printf, which can be use with flags "**#-0 +.**" allong with **field width**. The following modificators are implemented "**hh, h, l, ll, L, j, z**" and can be used to print integer as **binary**, **octal**, **decimal** or **hexadecimal**.
I aslo wrote my own implementation of the **dragon4 algorithm**, allowing me to perfectly print any **float**, **double** or **long double** without any loss regardless of the precision.
