# ft_printf
## ft_printf - 42 Project

Conversion supported : scidpuxX%

Options supported : -0.* and width


Complete parsing of arguments in linked t_arg structures before printing (return error if invalid).

Each t_arg contain a pointer to the print function of the associated type.

Each t_arg contain a union to keep different possible type of arg in one variable.

Each t_arg contain a option char that contain flag combinations readed with binary mask.
