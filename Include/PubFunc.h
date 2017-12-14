/*================================================================*
*           Copyright(c) 2015-2018, VMAX Power Co., Ltd.
*                      ALL RIGHTS RESERVED
*
* PRODUCT  : SAIC6600P220AC1U801
* FILENAME : PubFunc.h
* PURPOSE  : Define base data type.
*
* HISTORY :
*    DATE           VERSION           AUTHOR         NOTE
* 2016-03-19          V1.0              VS         Created.
*=================================================================*/
#ifndef PUBFUNC_H
#define PUBFUNC_H

#ifdef __cplusplus
extern "C" {
#endif

#define		S2U(x)		(*((volatile UINT16*)(&(x))))

#define 	MAX2(x,y)	(((x)>=(y))?(x):(y))
#define 	MIN2(x,y)	(((x)<=(y))?(x):(y))
#define 	SIGN(x)		(((x)<=0)?0:1)
#define 	UPDNLMT16(Var,Max,Min)	{(Var)=((Var)>=(Max))?(Max):(Var);(Var)=((Var)<=(Min))?(Min):(Var);}
#define 	UPDNLMT32(Var,Max,Min)	{(Var)=((Var)>=(Max))?(Max):(Var);(Var)=((Var)<=(Min))?(Min):(Var);}
#define 	UPLMT32(Var,Max)	{(Var)=((Var)>=(Max))?(Max):(Var);}
#define 	DNLMT32(Var,Min)	{(Var)=((Var)<=(Min))?(Min):(Var);}
#define 	FILTER(ik,iVar,lMean)	(((((long)(iVar)<<16)-(lMean))>>((ik)+1))+(lMean))   
#define 	FILTER_32BITS_I(ik,lVar,lMean)	((((lVar)-(lMean))>>((ik)+1))+(lMean))

#ifdef __cplusplus
}
#endif 


#endif 


