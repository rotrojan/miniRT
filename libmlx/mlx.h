/*
** mlx.h for MinilibX in 
** 
** Made by Charlie Root
** Login   <ol@staff.42.fr>
** 
** Started on  Mon Jul 31 16:37:50 2000 Charlie Root
** Last update Tue Oct 01 16:23:28 2014 Olivier Crouzet
*/

/*
**   MinilibX -  Please report bugs
*/


/*
** FR msg - FR msg - FR msg
**
** MacOSX
** La MinilibX utilise 2 frameworks Mac : OpenGL et AppKit
**    qu'il faut ajouter a la compilation :
**   -framework OpenGL -framework AppKit
**
** UNIX / Linux
** La MinilibX utilise 2 librairies supplementaires qu'il
**      est necessaire de rajouter a la compilation :
**   -lmlx -lXext -lX11
**
** La MinilibX permet le chargement des images de type Xpm.
** Notez que cette implementation est incomplete.
**
** Il y a des differences entre X11 et MacOS.
** les numeros des touches ne sont pas les memes,
** les numeros des boutons souris ne sont pas les memes.
** Egalement l'expose est gere differemment, et sous MacOS
** il est preferable d'entrer le plus tot possible dans mlx_loop,
** il est normal que les fenetres n'apparaissent pas avant mlx_loop
** (ou bien forcez avec mlx_do_sync mais c'est pas genial).
** Sous MacOS, l'octet Alpha est pris en compte dans toutes les
** images, et represente la transparence et non l'opacite comme
** c'est normalement le cas.
*/


#ifndef MLX_H

# define	MLX_H

/*
 * ** Event mask define
 * */

# define NOEVENTMASK 0L
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)
# define BUTTONPRESSMASK (1L<<2)
# define BUTTONRELEASEMASK (1L<<3)
# define ENTERWINDOWMASK (1L<<4)
# define LEAVEWINDOWMASK (1L<<5)
# define POINTERMOTIONMASK (1L<<6)
# define POINTERMOTIONHINTMASK (1L<<7)
# define BUTTON1MOTIONMASK (1L<<8)
# define BUTTON2MOTIONMASK (1L<<9)
# define BUTTON3MOTIONMASK (1L<<10)
# define BUTTON4MOTIONMASK (1L<<11)
# define BUTTON5MOTIONMASK (1L<<12)
# define BUTTONMOTIONMASK (1L<<13)
# define KEYMAPSTATEMASK (1L<<14)
# define EXPOSUREMASK (1L<<15)
# define VISIBILITYCHANGEMASK (1L<<16)
# define STRUCTURENOTIFYMASK (1L<<17)
# define RESIZEREDIRECTMASK (1L<<18)
# define SUBSTRUCTURENOTIFYMASK (1L<<19)
# define SUBSTRUCTUREREDIRECTMASK (1L<<20)
# define FOCUSCHANGEMASK (1L<<21)
# define PROPERTYCHANGEMASK (1L<<22)
# define COLORMAPCHANGEMASK (1L<<23)
# define OWNERGRABBUTTONMASK (1L<<24)

/*
 * ** Event define
 * */

# define KEYPRESS 2
# define KEYRELEASE 3
# define BUTTONPRESS 4
# define BUTTONRELEASE 5
# define MOTIONNOTIFY 6
# define ENTERNOTIFY 7
# define LEAVENOTIFY 8
# define FOCUSIN 9
# define FOCUSOUT 10
# define KEYMAPNOTIFY 11
# define EXPOSE 12
# define GRAPHICSEXPOSE 13
# define NOEXPOSE 14
# define VISIBILITYNOTIFY 15
# define CREATENOTIFY 16
# define DESTROYNOTIFY 17
# define UNMAPNOTIFY 18
# define MAPNOTIFY 19
# define MAPREQUEST 20
# define REPARENTNOTIFY 21
# define CONFIGURENOTIFY 22
# define CONFIGUREREQUEST 23
# define GRAVITYNOTIFY 24

/*
 * ** Mouse button keycodes
 * */

# define BUT1_KEY 1
# define BUT2_KEY 2
# define BUT3_KEY 3
# define SCROLLUP_KEY 4
# define SCROLLDOWN_KEY 5
# define SCROLLLEFT_KEY 6
# define SCROLLRIGHT_KEY 7

/*
 * ** Keyboard keys
 * */

/*
 * ** Letters keys
 * */

# define A_KEY 0
# define B_KEY 11
# define C_KEY 8
# define D_KEY 2
# define E_KEY 14
# define F_KEY 3
# define G_KEY 5
# define H_KEY 4
# define I_KEY 34
# define J_KEY 38
# define K_KEY 40
# define L_KEY 37
# define M_KEY 46
# define N_KEY 45
# define O_KEY 31
# define P_KEY 35
# define Q_KEY 12
# define R_KEY 15
# define S_KEY 1
# define T_KEY 17
# define U_KEY 32
# define V_KEY 9
# define W_KEY 13
# define X_KEY 7
# define Y_KEY 16
# define Z_KEY 6

/*
 * ** Numbers (not numeric keypad ones)
 * */

# define K1_KEY 18
# define K2_KEY 19
# define K3_KEY 20
# define K4_KEY 21
# define K5_KEY 23
# define K6_KEY 22
# define K7_KEY 26
# define K8_KEY 28
# define K9_KEY 25
# define K0_KEY 29

/*
 * ** Special characters
 * ** SP_KEY is the space ( ) key
 * ** BQ_KEY is the back quote (`) and tilde (~) key
 * ** MN_KEY is the minus (-) and underscore (_) key
 * ** PL_KEY is the plus (+) and equal (=) key
 * ** SBO_KEY is the square bracket opening ([) and brace opening ({) key
 * ** SBC_KEY is the square bracket closing (]) and brace closing (}) key
 * ** BSL_KEY is the backslash (\) and pipe (|) key
 * ** SC_KEY is the semicolon (;) and colon (:) key
 * ** SQ_KEY is the simple quote (') and double quote (") key
 * ** CM_KEY is the comma (,) and angle bracket opening (<) key
 * ** PT_KEY is the point (.) and angle bracket closing (>) key
 * ** SL_KEY is the slash (/) and question mark (?) key
 * */

# define SP_KEY 49
# define BQ_KEY 50
# define MN_KEY 27
# define PL_KEY 24
# define SBO_KEY 33
# define SBC_KEY 30
# define BSL_KEY 42
# define SC_KEY 41
# define SQ_KEY 39
# define CM_KEY 43
# define PT_KEY 47
# define SL_KEY 44

/*
 * ** Functions keys, you might use fn key to use them
 * ** Seems that did not work. I don't know. Deso pas deso, au pire on les use pas.
 * */

# define F1_KEY 122
# define F2_KEY 120
# define F3_KEY 99
# define F4_KEY 118
# define F5_KEY 96
# define F6_KEY 97
# define F7_KEY 98
# define F8_KEY 100
# define F9_KEY 101
# define F10_KEY 109
# define F11_KEY
# define F12_KEY 111
# define F13_KEY 105
# define F14_KEY 107
# define F15_KEY 113
# define F16_KEY 106
# define F17_KEY 64
# define F18_KEY 79
# define F19_KEY 80

/*
 * ** Arrow keys
 * */

# define UP_KEY 126
# define DOWN_KEY 125
# define RIGHT_KEY 124
# define LEFT_KEY 123

/*
 * ** Special keys
 * ** CL_KEY is the caps lock key
 * ** LSFT_KEY and RLFT_KEY are the left shift and right shift keys
 * ** LCTRL_KEY and RCTRL_KEY are the left control and right control keys
 * ** LOPT_KEY and ROPT_KEY are the left option and right option keys
 * ** LCMD_KEY and RCMD_KEY are the left command and right command keys
 * ** LDEL_KEY and RDEL_KEY are the left delete and right delete keys
 * ** RTN_KEY is the return key
 * ** EJ_KEY is the eject key and doesn't react
 * ** PUP_KEY and PDOWN_KEY are the page up and page down keys
 * ** CLR_KEY is the clear key
 * */

# define ESC_KEY 53
# define TAB_KEY 48
# define CL_KEY 272
# define LSFT_KEY 257
# define LCTRL_KEY 256
# define LOPT_KEY 261
# define LCMD_KEY 259
# define LDEL_KEY 51
# define RTN_KEY 36
# define RSFT_KEY 258
# define RCTRL_KEY 269
# define ROPT_KEY 262
# define RCMD_KEY 260
# define EJ_KEY
# define FN_KEY 279
# define RDEL_KEY 117
# define HOME_KEY 115
# define END_KEY 119
# define PUP_KEY 116
# define PDOWN_KEY 121
# define CLR_KEY 71

/*
 * ** Numeric keyboard keys, preceded by NK
 * ** NKEQ_KEY is the equal (=) key
 * ** NKSL_KEY is the slash (/) key
 * ** NKWC_KEY is the wildcard (*) key
 * ** NKMN_KEY is the minus (-) key
 * ** NKPL_KEY is the plus (+) key
 * ** NKPT_KEY is the point (.) key
 * ** NKNTR_KEY is the enter key
 * */

# define NK1_KEY 83
# define NK2_KEY 84
# define NK3_KEY 85
# define NK4_KEY 86
# define NK5_KEY 87
# define NK6_KEY 88
# define NK7_KEY 89
# define NK8_KEY 91
# define NK9_KEY 92
# define NK0_KEY 82
# define NKEQ_KEY 81
# define NKSL_KEY 75
# define NKWC_KEY 67
# define NKMN_KEY 78
# define NKPL_KEY 69
# define NKPT_KEY 65
# define NKNTR_KEY 76

# define RED_COMP 2
# define GREEN_COMP 1
# define BLUE_COMP 0
# define ALPHA_COMP 3

void	*mlx_init();
/*
**  needed before everything else.
**  return (void *)0 if failed
*/


/*
** Basic actions
*/

void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
/*
**  return void *0 if failed
*/
int	mlx_clear_window(void *mlx_ptr, void *win_ptr);
int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
/*
**  origin for x & y is top left corner of the window
**  y down is positive
**  color is 0x00RRGGBB
*/


/*
** Image stuff
*/

void	*mlx_new_image(void *mlx_ptr,int width,int height);
/*
**  return void *0 if failed
*/
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
			   int *size_line, int *endian);
/*
**  endian : 0 = sever X is little endian, 1 = big endian
**  endian : useless on macos, client and graphical framework have the same endian
*/
int	mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
				int x, int y);
unsigned int	mlx_get_color_value(void *mlx_ptr, int color);


/*
** dealing with Events
*/

int	mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int	mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int	mlx_expose_hook (void *win_ptr, int (*funct_ptr)(), void *param);

int	mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);
int	mlx_loop (void *mlx_ptr);


/*
**  hook funct are called as follow :
**
**   expose_hook(void *param);
**   key_hook(int keycode, void *param);
**   mouse_hook(int button, int x,int y, void *param);
**   loop_hook(void *param);
**
*/


/*
**  Usually asked...
*/

int	mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color,
		       char *string);
void	*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,
			  int *width, int *height);
void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
			       int *width, int *height);
void    *mlx_png_file_to_image(void *mlx_ptr, char *file, int *width, int *height);

int	mlx_destroy_window(void *mlx_ptr, void *win_ptr);

int	mlx_destroy_image(void *mlx_ptr, void *img_ptr);

int	mlx_destroy_font(void *mlx_ptr);

/*
**  generic hook system for all events, and minilibX functions that
**    can be hooked. Some macro and defines from X11/X.h are needed here.
*/

int	mlx_hook(void *win_ptr, int x_event, int x_mask,
                 int (*funct)(), void *param);

int     mlx_mouse_hide();
int     mlx_mouse_show();
int     mlx_mouse_move(void *win_ptr, int x, int y);
int     mlx_mouse_get_pos(void *win_ptr, int *x, int *y);

int	mlx_do_key_autorepeatoff(void *mlx_ptr);
int	mlx_do_key_autorepeaton(void *mlx_ptr);
int	mlx_do_sync(void *mlx_ptr);

#endif /* MLX_H */
