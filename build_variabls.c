#include "main.h"
/**
  * build_all_variables - builds all the variables for each function used.
  * @var_s: takes in a variable
  * Return: returns the variable needed
  */
all_variables_t *build_all_variables(all_variables_t *var_s)
{
	var_s->buf = NULL;
	var_s->n_env_nod = 0;
	var_s->len = 0;
	var_s->in_hd = NULL;
	var_s->env_hd = NULL;
	var_s->env_ar = NULL;
	var_s->pth_ar = NULL;
	var_s->in_ar = NULL;
	var_s->n_tok = 0;
	return (var_s);
}
