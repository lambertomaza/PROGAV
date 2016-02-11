#ifndef _TDDPROGDETALLADO_
#define _TDDPROGDETALLADO_
#include <wchar.h> /* wchar_t */

#define hazcad(s)	# s
#define unidad(unid, n)	unid##_##n
#define tema(tema, m, n)	tema##_##m##_##n 
#define subtema(subt, u, t, st)	subt##_##u##_##t##_##st

#ifdef __unix__
#define EXT_WEAK      __attribute__ ((weak)) 
#else
#define EXT_WEAK
#endif /* __unix__ */

//extern wchar_t unidaddaprendizaje[]; /* Nombre de la Unidad de Aprendizaje (UA)*/
extern char unidaddaprendizaje[]; /* Nombre de la Unidad de Aprendizaje (UA)*/
extern int numdunidades; /* Numdero de unidades de la UA */

/* Unidades */
//extern wchar_t unidad(Unidad, 1)[];
//extern wchar_t unidad(Unidad, 2)[];
//extern wchar_t unidad(Unidad, 3)[];
//extern wchar_t unidad(Unidad, 4)[];
//extern wchar_t unidad(Unidad, 5)[];
extern char unidad(Unidad, 1)[];
extern char unidad(Unidad, 2)[];
extern char unidad(Unidad, 3)[];
extern char unidad(Unidad, 4)[];
extern char unidad(Unidad, 5)[];

//extern wchar_t *unit[]; /* array de wchar_t* que debe contener los nombres de las unidades, i.e. Unidad_1, Unidad_2, etc. */
extern char *unit[]; /* array de wchar_t* que debe contener los nombres de las unidades, i.e. Unidad_1, Unidad_2, etc. */

extern int numdtemas[]; /* array de int que debe contener los numeros de temas de las unidades */

/* Temas */
//extern wchar_t tema(Tema, 1, 1)[];
//extern wchar_t tema(Tema, 1, 2)[];
//extern wchar_t tema(Tema, 1, 3)[];
//extern wchar_t tema(Tema, 1, 4)[];
//extern wchar_t tema(Tema, 2, 1)[];
//extern wchar_t tema(Tema, 2, 2)[];
//extern wchar_t tema(Tema, 2, 3)[];
//extern wchar_t tema(Tema, 2, 4)[];
//extern wchar_t tema(Tema, 2, 5)[];
//extern wchar_t tema(Tema, 3, 1)[];
//extern wchar_t tema(Tema, 3, 2)[];
//extern wchar_t tema(Tema, 3, 3)[];
//extern wchar_t tema(Tema, 4, 1)[];
//extern wchar_t tema(Tema, 4, 2)[];
//extern wchar_t tema(Tema, 4, 3)[];
//extern wchar_t tema(Tema, 4, 4)[];
//extern wchar_t tema(Tema, 4, 5)[];

extern char tema(Tema, 1, 1)[];
extern char tema(Tema, 1, 2)[];
extern char tema(Tema, 1, 3)[];
extern char tema(Tema, 1, 4)[];
extern char tema(Tema, 1, 5)[];
extern char tema(Tema, 2, 1)[];
extern char tema(Tema, 2, 2)[];
extern char tema(Tema, 2, 3)[];
extern char tema(Tema, 2, 4)[];
extern char tema(Tema, 2, 5)[];
extern char tema(Tema, 3, 1)[];
extern char tema(Tema, 3, 2)[];
extern char tema(Tema, 3, 3)[];
extern char tema(Tema, 4, 1)[];
extern char tema(Tema, 4, 2)[];
extern char tema(Tema, 4, 3)[];
extern char tema(Tema, 4, 4)[];
extern char tema(Tema, 4, 5)[];

/* Subtemas */
//extern wchar_t subtema(Subtema, 1, 1, 1)[];
//extern wchar_t subtema(Subtema, 1, 1, 2)[];
//extern wchar_t subtema(Subtema, 1, 2, 1)[];
//extern wchar_t subtema(Subtema, 1, 3, 1)[];
//extern wchar_t subtema(Subtema, 2, 1, 1)[];
//extern wchar_t subtema(Subtema, 2, 1, 2)[];
//extern wchar_t subtema(Subtema, 2, 2, 1)[];
//extern wchar_t subtema(Subtema, 2, 3, 1)[];
//extern wchar_t subtema(Subtema, 2, 3, 2)[];
//extern wchar_t subtema(Subtema, 2, 3, 3)[];
//extern wchar_t subtema(Subtema, 2, 4, 1)[];
//extern wchar_t subtema(Subtema, 2, 5, 1)[];
//extern wchar_t subtema(Subtema, 3, 1, 1)[];
//extern wchar_t subtema(Subtema, 3, 2, 1)[];
//extern wchar_t subtema(Subtema, 3, 2, 2)[];
//extern wchar_t subtema(Subtema, 3, 2, 3)[];
//extern wchar_t subtema(Subtema, 3, 3, 1)[];
//extern wchar_t subtema(Subtema, 3, 3, 2)[];
//extern wchar_t subtema(Subtema, 3, 3, 3)[];
//extern wchar_t subtema(Subtema, 4, 1, 1)[];
//extern wchar_t subtema(Subtema, 4, 1, 2)[];
//extern wchar_t subtema(Subtema, 4, 3, 1)[];
//extern wchar_t subtema(Subtema, 4, 3, 2)[];
//extern wchar_t subtema(Subtema, 4, 3, 3)[];

extern char subtema(Subtema, 1, 1, 1)[];
extern char subtema(Subtema, 1, 1, 2)[];
extern char subtema(Subtema, 1, 2, 1)[];
extern char subtema(Subtema, 1, 3, 1)[];
extern char subtema(Subtema, 2, 1, 1)[];
extern char subtema(Subtema, 2, 1, 2)[];
extern char subtema(Subtema, 2, 2, 1)[];
extern char subtema(Subtema, 2, 2, 2)[];
extern char subtema(Subtema, 2, 2, 3)[];
extern char subtema(Subtema, 2, 2, 4)[];
extern char subtema(Subtema, 2, 3, 1)[];
extern char subtema(Subtema, 2, 3, 2)[];
extern char subtema(Subtema, 2, 3, 3)[];
extern char subtema(Subtema, 2, 4, 1)[];
extern char subtema(Subtema, 2, 5, 1)[];
extern char subtema(Subtema, 3, 1, 1)[];
extern char subtema(Subtema, 3, 1, 2)[];
extern char subtema(Subtema, 3, 1, 3)[];
extern char subtema(Subtema, 3, 2, 1)[];
extern char subtema(Subtema, 3, 2, 2)[];
extern char subtema(Subtema, 3, 2, 3)[];
extern char subtema(Subtema, 3, 2, 4)[];
extern char subtema(Subtema, 3, 3, 1)[];
extern char subtema(Subtema, 3, 3, 2)[];
extern char subtema(Subtema, 3, 3, 3)[];
extern char subtema(Subtema, 3, 3, 4)[];
extern char subtema(Subtema, 3, 3, 5)[];
extern char subtema(Subtema, 3, 3, 6)[];
extern char subtema(Subtema, 3, 3, 7)[];
extern char subtema(Subtema, 3, 3, 8)[];
extern char subtema(Subtema, 4, 1, 1)[];
extern char subtema(Subtema, 4, 1, 2)[];
extern char subtema(Subtema, 4, 1, 3)[];
extern char subtema(Subtema, 4, 2, 1)[];
extern char subtema(Subtema, 4, 2, 2)[];
extern char subtema(Subtema, 4, 2, 3)[];
extern char subtema(Subtema, 4, 2, 4)[];
extern char subtema(Subtema, 4, 2, 5)[];
extern char subtema(Subtema, 4, 2, 6)[];
extern char subtema(Subtema, 4, 3, 1)[];
extern char subtema(Subtema, 4, 3, 2)[];
extern char subtema(Subtema, 4, 3, 3)[];
extern char subtema(Subtema, 4, 3, 4)[];
extern char subtema(Subtema, 4, 3, 5)[];
extern char subtema(Subtema, 4, 3, 6)[];
extern char subtema(Subtema, 4, 3, 7)[];
extern char subtema(Subtema, 5, 1, 1)[];
extern char subtema(Subtema, 5, 1, 2)[];
extern char subtema(Subtema, 5, 1, 3)[];
extern char subtema(Subtema, 5, 1, 4)[];
extern char subtema(Subtema, 5, 1, 5)[];

/* arrays de wchar_t* que deben contener los nombres de los temas de las 
   unidades 1, 2, 3 y 4 */
//wchar_t *nombresdtemasdu1[] __attribute__((weak));
//extern wchar_t *nombresdtemasdu1[];
//extern wchar_t *nombresdtemasdu2[];
//extern wchar_t *nombresdtemasdu3[];
//extern wchar_t *nombresdtemasdu4[];
//extern wchar_t *nombresdtemasdu5[];

extern char *nombresdtemasdu1[];
extern char *nombresdtemasdu2[];
extern char *nombresdtemasdu3[];
extern char *nombresdtemasdu4[];
extern char *nombresdtemasdu5[];




extern int *numdsubtemas[];
//extern wchar_t ***nombresdsubtemas[];
extern char ***nombresdsubtemas[];


/* Modelo de programa detallado de una Unidad de Aprendizaje */
struct unidad;
struct prog_detallado {
	//wchar_t nombre[120];
	char nombre[120];
	int numdunidades;
	struct unidad *unidad;
};
struct tema;
struct unidad {
	//wchar_t nombre[120];
	char nombre[120];
	int numdtemas;
	struct tema *tema;
};
struct subtema;
struct tema {
	//wchar_t nombre[120];
	char nombre[120];
	int numdsubtemas;
	struct subtema *subtema;
};
struct subtema {
	//wchar_t nombre[120];
	char nombre[120];
};

void copy(wchar_t to[], wchar_t from[]);

void prog_detallado(struct prog_detallado *pd);
void set_prog_detallado(struct prog_detallado *pd);
void mostrar_prog_detallado(struct prog_detallado *pd);



#endif /* _TDDPROGDETALLADO_ */
