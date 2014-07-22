/****************************************************************************
 *
 * Date: February 20, 2013
 *
 * E. Marinetto
 *
 * This function allow to use bspline_interpol software in Matlab software.
 *
 *
 *
 * E. Marinetto
 * Laboratorio de Imagen Médica
 * WEB del LIM
 * Unidad de Medicina y Cirugía Experimental.
 * Fundación para la Investigación Biomédica del
 * Hospital Gregorio Marañón
 * C/ Doctor Esquerdo, 46
 * 28007  Madrid
 * Teléfono: +34 91 4265017
 * Fax: +34 91 4265108
 *
****************************************************************************/

/*****************************************************************************
 *	Include
 ****************************************************************************/
#include	"addMex_c.h"

/*****************************************************************************
 *	This file implements the method for mexfile
 *
 *	It convert a vector of data to the coefficients values.
 *	Input is passed as double
 ****************************************************************************/



/*************************************************************************/


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){



	/* This function implements a interface to matlab in order to use :
	 *
				(
					double	A,				/* dimension of the image *
					double	B	/* degree of the spline model *
				);
	 */

	/* Inputs */
    #define A_IN	prhs[0]
    #define B_IN	prhs[1]

	/* Outputs */
    #define RESULT  plhs[0]      
            
	/* Duplicate the input to get the output */
    double A;
    double B;
	double C;
	double* result;
    
	// Using other function
	printMessageFunction();
	
	
    if(!mxIsDouble(A_IN) || !mxIsDouble(B_IN)){
        mexErrMsgTxt("Input must be a double");
    }  
    
	A = (double) mxGetScalar(A_IN);
	B = (double) mxGetScalar(B_IN);
	
	C = A+B;
	
	
	
	
	RESULT = mxCreateDoubleMatrix(1,1,mxREAL);
    result = (double *) mxGetPr(RESULT);
    result[0] = C;
	
	
    return;
}


