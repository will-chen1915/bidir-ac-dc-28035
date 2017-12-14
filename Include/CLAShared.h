// TI File $Revision: /main/1 $
// Checkin $Date: March 18, 2012   09:24:46 $
//###########################################################################
//
// FILE:   CLAShared.h
//
// TITLE:  CLA and CPU shared variables and constants
//
//###########################################################################
// $TI Release: 2803x Header Files V1.01 $
// $Release Date: April 30, 2012 $
//###########################################################################


#ifndef CLA_SHARED_H
#define CLA_SHARED_H

#ifdef __cplusplus
extern "C" {
#endif

  //#include "DSP2803x_Device.h"
/*
// The following are symbols defined in the CLA assembly code
// Including them in the shared header file makes them 
// .global and the main CPU can make use of them. 
  extern Uint32 Cla1Task1;
  extern Uint32 Cla1Task2;
  extern Uint32 Cla1Task8;
  extern Uint32 Cla1Prog_Start;
  extern Uint32 Cla1T1End;
  extern Uint32 Cla1T2End;
  extern Uint32 Cla1T8End;
*/
#ifdef __cplusplus
}
#endif /* extern "C" */

//fs=80e3HZ   
//_Filter10HzK1	.equ	65171
//filter=tf([1],[1/6.28/10 1]);c2d(filter,Ts,'tustin')	
/*#define 	Filter10HzK1	    0.9992066
#define 	Filter10HzK2	 	0.0003967
#define 	Filter10HzK3	 	0.0003923
*/
#define 	Filter10HzK1	    0.92
#define 	Filter10HzK2	 	0.04
#define 	Filter10HzK3	 	0.04

//fs=80e3HZ   
//filter=tf([1],[1/6.28/10000 1]);c2d(filter,Ts,'tustin')
#define 	Filter1kHzK1	    0.4363
#define 	Filter1kHzK2	 	0.2819
#define 	Filter1kHzK3	 	0.2819
//4K
#define 	Filter4kHzK1	    0.7286
#define 	Filter4kHzK2	 	0.1357
#define 	Filter4kHzK3	 	0.1357

//fs=80e3HZ   
//filter=tf([1],[1/6.28/7500 1]);c2d(filter,Ts,'tustin')
#define 	Filter7k5HzK1	    0.5451
#define 	Filter7k5HzK2	 	0.2274
#define 	Filter7k5HzK3	 	0.2274

//fs=80e3HZ   
//filter=tf([1],[1/6.28/15000 1]);c2d(filter,Ts,'tustin')
#define 	Filter15kHzK1	    0.4363
#define 	Filter15kHzK2	 	0.2819
#define 	Filter15kHzK3	 	0.2819

//#define		BURST_OUT_POINT				5957818.2	//330K-(60000/660)*65536
//#define		BURST_OUT_POINT				5633467.2	//350K-(60000/660)*65536
//#define		BURST_IN_POINT				3801088.0	//58*65536
//#define		BURST_OUT_POINT				    3866624.0	//59*65536

//#define		BURST_IN_POINT				3866624.0	//59*65536 340k
//#define		BURST_OUT_POINT				    3932160.0	//60*65536

//#define		BURST_IN_POINT          4915200.0	//75*65536 250k
//#define		BURST_OUT_POINT         4980736.0	//76*65536

#define		BURST_IN_POINT          6488064	//99*65536 250k
#define		BURST_OUT_POINT         6553600	//100*65536

//CPU to CLA RAM 0x1500-0x157F
struct CputoClaVarStruct
{
	//------------offset=0000H-----------------------
	short	  _i16VdcRef;					//1500
	short     _i16IdcRef;					//1501
	short     _i16IdcRefRamp;				//1502
	short	  _i16IdcPioutPermit;			//1503
	short 	  _i16DcdcPWMTsMin;				//1504
	short 	  _i16DcdcPWMTsMax;				//1505
	short     _u16FlagClrLoop;				//1506
	short     _i16PWMModeEnable;			//1507
	float32   _f32VPIOutFmax;				//1508~1509
	float32   _f32VILoopPIOutMin;           //150A~150B 电压、电流环运算环路输出下限值，-100(Q16格式)
    float32   _f32VinCompDelta;             //150C~150D
	//------------offset=0010H-------------------------
	
	float32	  _f32IdcPIA1;				    //1518~1519
	float32	  _f32IdcPIA2;				    //151A~151B
	float32	  _f32IdcPIA3;				    //151C~151D
	float32   _f32IdcPIB0;				    //1514~1515
	float32   _f32IdcPIB1;				    //1516~1517
	float32   _f32IdcPIB2;				    //1514~1515
	float32   _f32IdcPIB3;				    //1516~1517
    float32	  _f32VdcPIA1;				    //1518~1519
	float32	  _f32VdcPIA2;				    //151A~151B
	float32	  _f32VdcPIA3;				    //151C~151D
	float32   _f32VdcPIB0;				    //151E~151F
	//------------offset=0020H-------------------------
	float32   _f32VdcPIB1;				    //1520~1521
	float32   _f32VdcPIB2;				    //1522~1523	
	float32	  _f32VdcPIB3;				    //1524~1525
    float32   _f32P1VoutICoefK;		        //1526~1527
	float32   _f32P1VoutICoefB;		        //1528~1529
	float32   _f32P1IoutCoefK;		        //152A~152B
	float32   _f32P1IoutCoefB;		        //152C~152D
	float32   _f32VoutFilted;		        //152C~152D
};               
extern volatile struct CputoClaVarStruct CputoClaVar;

//CLA to CPU RAM 0x1480-0x14FF
struct ClatoCpuVarStruct
{
	//------------offset=0000H---------------------
	float32	    _f32VdcPIA1;			//1480~1481
	float32	    _f32VdcPIA2;			//1482~1483
	float32	    _f32VdcPIA3;			//1484~1485
	float32     _f32VdcPIB0;			//1486~1487
	float32     _f32VdcPIB1;			//1488~1489
	float32     _f32VdcPIB2;			//148A~148B
	float32	    _f32VdcPIB3;			//148C~148D
	float32	  	_f32VdcFb;     		    //148E~148F
	//------------offset=0010H---------------------
	float32		_f32VdcFb1; 			//1490~1491
	float32	  	_f32VdcFbFilted;		//1492~1493
	INT32	  	_i32VdcFbFilted; 		//1494~1495
	float32		_f32VdcPIErr;			//1496~1497 
	float32		_f32VdcPIErr1;			//1498~1499 
	float32		_f32VdcPIErr2;			//149A~149B
	float32		_f32VdcPIErr3;			//149C~149D
	float32		_f32VdcPiOut;		    //149E~149F
	//------------offset=0020H---------------------
	float32   	_f32VdcPiOut1;		    //14a0~14a1
	float32   	_f32VdcPiOut2;		    //14a2~14a3
	float32   	_f32VdcPiOut3;		    //14a4~14a5
	INT32	  	_i32VdcPioutBak;   	   	//14a6~14a7 
    float32   	_f32IdcFb;				//14a8~14a9
	float32   	_f32IdcFb1;  			//14aa~14ab
	float32   	_f32IdcFbFilted;	    //14ac~14ad 
	INT32		_i32IdcFbFilted;	    //14ae~14af
	//------------offset=0030H--------------------  
	float32   	_f32IdcRef;  			//14B0~14B1
	float32		_f32IdcPIErr;			//1488~1489 
	float32		_f32IdcPIErr1;			//148A~148B 
	float32		_f32IdcPIErr2;			//148C~148D
	float32		_f32IdcPIErr3;			//148C~148D
	float32   	_f32IdcPiOut;			//14A8~14A9
	float32   	_f32IdcPiOut1;		    //1490~1491
	float32   	_f32IdcPiOut2;		    //1492~1493
	//------------offset=0040H--------------------  
	float32   	_f32IdcPiOut3;		    //1492~1493
	INT32		_i32IdcPioutBak;		//14AA~14AB
	INT32		_i32VIdcPiOutLast;		//14AC~14AD 
    INT32 	    _i32DcdcDutyShadow; 	//14AE~14AF
	INT32 	    _i32DcdcPWMTsShadow; 	//14B0~14B1
	short	 	_u16FlagFs;				//14B2
	short 	  	_u16FlagVI;				//14B3
	short       _u16OffsetCalcedFlag;   //14B4
	short       _u16IoutOffset;         //14B5
	short       _u16VloopParamSel;         //14B5
	
	//------------offset=0050H---------------------
	//------------offset=0060H---------------------
	//------------offset=0070H---------------------
	
};               
extern volatile struct ClatoCpuVarStruct ClatoCpuVar;  


//CLA RAM 0x8C00-0x9000
struct ClaVarStruct
{
	//------------offset=0000H-----------------------
    INT32     _i32OffsetSum;
    float32   _f32IoutOffset;
    short     _u16OffsetCnt;
	short	  s16AD1;			        //8C00
	short	  s16AD2;					//8C01
	short 	  s16AD3;				    //8C02
	short 	  s16AD4;				    //8C03
	short     s16AD5;					//8C04
	short     s16AD6;				    //8C05
	short     s16AD7;				    //8C06
	short     s16AD8;					//8C07
	short     s16AD9;				    //8C08
};               
extern volatile struct ClaVarStruct ClaVar;

//Task 3 (C) Variables

//Task 4 (C) Variables

//Task 5 (C) Variables

//Task 6 (C) Variables

//Task 7 (C) Variables

//Task 8 (C) Variables

//Common (C) Variables

//CLA C Tasks
__interrupt void Cla1Task1();
__interrupt void Cla1Task2();
__interrupt void Cla1Task3();
__interrupt void Cla1Task4();
__interrupt void Cla1Task5();
__interrupt void Cla1Task6();
__interrupt void Cla1Task7();
__interrupt void Cla1Task8();

//C Function Prototypes

#endif  // end of CLA_SHARED definition

