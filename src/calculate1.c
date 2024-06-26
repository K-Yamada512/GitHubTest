/*****************************************************************************/
/*
*	filename:calculate1.c
*	about:
*		calculate function 1
*
*	attention:
*
*	history:
*		2024/04/13:K.Yamada :create this file
*		2024/06/02:K.Yamada :create function (Fractrial)
*/
/*****************************************************************************/
/*****************************************************************************/
/*                         include headerfile                                */
/*****************************************************************************/
/*standard library*/
#include <stdlib.h>
#include <stdint.h>

#include <calculate1.h>

/*****************************************************************************/
/*                               define const                                */
/*****************************************************************************/
/*none*/

/*****************************************************************************/
/*                         define variable (global)                          */
/*****************************************************************************/
/*none*/

/*****************************************************************************/
/*                         define structure (global)                         */
/*****************************************************************************/
/*none*/

/*****************************************************************************/
/*                                 define function                           */
/*****************************************************************************/
/*
*	function name:Fractrial
*	about:
*		calculate fractrial (n!)
*
*	out	uint64_t*	ans		:pointer variable to store the answer to the calculation
*	in	uint64_t	n		:natural number
*	out	int64_t				:error code
*/
int64_t Fractrial(uint64_t* ans, uint64_t n)
{
	if (ans == NULL)return -1;
	if (n < 1)return -2;

	*ans = 0;

	uint64_t answer = 1;

	for (uint64_t i = 0; i < n - 1; i++)
	{
		uint64_t n_value = n - i;

		if (n_value >= UINT64_MAX / answer)return -3;
		else answer *= n_value;
	}

	*ans = answer;

	return 0;
}
