/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue May 08 10:09:10 2001
 */
/* Compiler settings for S:\lib\oceanEngine\Working\OeXp\OeT\OeT.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IOeTVariant = {0x00000000,0x4F45,0x0100,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeTString = {0x00000000,0x4F45,0x0101,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeTArray = {0x00000000,0x4F45,0x0102,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID DIID_IOeTArrayEvents = {0x00000000,0x4F45,0x0102,{0x00,0x17,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeTChain = {0x00000000,0x4F45,0x0103,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeTQueue = {0x00000000,0x4F45,0x0104,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeTStack = {0x00000000,0x4F45,0x0105,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeTSet = {0x00000000,0x4F45,0x0106,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeTTable = {0x00000000,0x4F45,0x0107,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeTHash = {0x00000000,0x4F45,0x0108,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeTTree2 = {0x00000000,0x4F45,0x0110,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeTTree = {0x00000000,0x4F45,0x0111,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeTGraph = {0x00000000,0x4F45,0x0112,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID IID_IOeTCodedStream = {0x00000000,0x4F45,0x0120,{0x00,0x01,0x48,0x69,0x54,0x65,0x63,0x68}};


const IID LIBID_OeTLib = {0x00000000,0x4F45,0x0000,{0x00,0x04,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeTVariant = {0x00000000,0x4F45,0x0100,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeTString = {0x00000000,0x4F45,0x0101,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeTArray = {0x00000000,0x4F45,0x0102,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeTChain = {0x00000000,0x4F45,0x0103,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeTQueue = {0x00000000,0x4F45,0x0104,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeTStack = {0x00000000,0x4F45,0x0105,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeTSet = {0x00000000,0x4F45,0x0106,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeTTable = {0x00000000,0x4F45,0x0107,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeTHash = {0x00000000,0x4F45,0x0108,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeTTree2 = {0x00000000,0x4F45,0x0110,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeTTree = {0x00000000,0x4F45,0x0111,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeTGraph = {0x00000000,0x4F45,0x0112,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


const CLSID CLSID_OeTCodedStream = {0x00000000,0x4F45,0x0120,{0x00,0x02,0x48,0x69,0x54,0x65,0x63,0x68}};


#ifdef __cplusplus
}
#endif
