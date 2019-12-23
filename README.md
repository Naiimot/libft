# 42's libft

Teaching at 42 focus on giving a solid understanding of the most basic elements in programming. For most of the project we do we are not allowed to use external libraries. **Most of the time malloc, free and write are our only allies**. That's why we are progressively building **our own library of usefull functions**. Some are reimplementations of classic C functions, others are my own creation, result from a repeated need for them.

## libft

This folder contains basic functions for **string manipulation**, **memory management** and some useful **linked list tools**.

## get_next_line

One of the first 42's projects, this function allow us to **read line by line on any file descriptor**. Multiple FDs ca be handled at the same time.

## ft_printf

This is my own version of printf, which can be use with flags "**#-0 +*.**" allong with **field width**. The following modificators are implemented **hh, h, l, ll, L, j, z** and can be used to print integer as **binary**, **octal**, **decimal** or **hexadecimal** numbers.

I aslo wrote my own implementation of the **Dragon4 algorithm**, allowing me to perfectly print any **float**, **double** or **long double** without any loss regardless of the precision.
