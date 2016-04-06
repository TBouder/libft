# ft_printf

[PDF](https://mega.nz/#!VxAWmZSa!mD6758M1O06xHDIL-loe0mCVd6_R179JIar4kGiVA68)  

###Gameplay  
>Printf format string (of which "printf" stands for "print formatted") refers to a control parameter. The format string is written in a simple template language, and specifies a method for rendering an arbitrary number of varied data type parameters into a string. This string is printed on the standard output stream. Characters in the format string are usually copied literally into the function's output, as is usual for templates, with the other parameters being rendered into the resulting text in place of certain placeholders – points marked by format specifiers, which are introduced by a % character. The format string itself is very often a string literal, which allows static analysis of the function call.  
>You have to reproduce printf with sSpdDioOuUxXcC, %%, .#0-+ and space flags.  

###Bonus :  
- [x] Flag *  
- [x] Flag ! (Do not display the result of the conversion)  
- [x] %f (float)  
- [x] Colors ({b} for blue, {g} for green, etc.)  
- [x] %b (binary)  
- [x] %B (binary UTF-8)  

###Requirements :  
- [LIBFT](https://bitbucket.org/Tbouder/libft)  
- C compiler  
- GNU  

###Installation :  
1. git clone https://bitbucket.org/Tbouder/ft_printf && cd ft_printf  
2. git clone https://bitbucket.org/Tbouder/libft  
3. make  
