#ifndef DEFINE_H
# define DEFINE_H

# ifdef __linux
#  define BUTTON1 1
#  define BUTTON2 3
#  define BUTTON3 2
#  define BUTTON4 4
#  define BUTTON5 5
#  define KEY_SPC 32
#  define KEY_ESC 65307
#  define KEY_RAZ 65438
#  define KEY_UP 65362
#  define KEY_DO 65364
#  define KEY_RI 65363
#  define KEY_LE 65361
#  define KEY_PLUS 65451
#  define KEY_MINUS 65453
# endif

# ifdef __macos
#  define BUTTON1 1
#  define BUTTON2 2
#  define BUTTON3 3
#  define BUTTON4 5
#  define BUTTON5 4
#  define KEY_SPC 49
#  define KEY_ESC 53
#  define KEY_UP 126
#  define KEY_DO 125
#  define KEY_RI 124
#  define KEY_LE 123
# endif

#endif
